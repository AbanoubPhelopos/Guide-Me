#include "readgraph.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <set>
#include <string>

ReadGraph::ReadGraph() {}
map<string, vector<Path>> ReadGraph::graph;
map<string, int> ReadGraph::cityId;
vector<int> ReadGraph::adjList[500];
bool ReadGraph::is_read = false;

vector<string> ReadGraph::Cities;
map<string,int>ReadGraph::cits;

string ReadGraph::StartFrom;
string ReadGraph::GoTo;
int ReadGraph::Budget;

void addEdge(const std::string& line) {
    istringstream iss(line);
    vector<string> tokens(istream_iterator<string>{iss},
                          istream_iterator<string>());

    if (tokens.size() < 3) {
        qWarning() << "Invalid input line: " << line.c_str();
        return;
    }

    const string& src = tokens[0];
    const string& dest = tokens[2];

    if( ReadGraph::cits[src]==0){
        ReadGraph::Cities.push_back(src);
         ReadGraph::cits[src]++;
    }
    if( ReadGraph::cits[dest]==0){
        ReadGraph::Cities.push_back(dest);
         ReadGraph::cits[dest]++;
    }

    for (int i = 3; i < tokens.size(); i += 2) {
        const string& transport = tokens[i];
        int cost = stoi(tokens[i + 1]);

        ReadGraph::graph[src].emplace_back(dest, cost, transport);
        ReadGraph::graph[dest].emplace_back(src, cost, transport);

        int sourceId = ReadGraph::cityId[src] ? ReadGraph::cityId[src] : (ReadGraph::cityId[src] = ReadGraph::cityId.size() + 1);
        int destId = ReadGraph::cityId[dest] ? ReadGraph::cityId[dest] : (ReadGraph::cityId[dest] = ReadGraph::cityId.size() + 1);

        ReadGraph::adjList[sourceId].push_back(destId);
        ReadGraph::adjList[destId].push_back(sourceId);

    }
}

void ReadGraph::GetGraph() {
    if (is_read) {
        qInfo() << "graph already read";
        return;
    }
    const QString fileName = "C:\\Users\\youss\\OneDrive\\Desktop\\TransportationMap.txt";
    QFile file(fileName);

    if (!file.exists()) {
        qCritical() << "File does not exist: " << fileName;
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Failed to open file: " << file.errorString();
        return;
    }

    QTextStream stream(&file);

    int n = stream.readLine().trimmed().toInt();
    while(n--) {
        QString line = stream.readLine().trimmed();
        if (!line.isEmpty()) {
            addEdge(line.toStdString());
        }
    }
    qInfo() << graph.size();
    file.close();
   // qDebug()<<Cities.size();
    is_read = true;
}
bool ReadGraph :: writeFile() {
    const QString fileName = "C:\\Users\\youss\\OneDrive\\Desktop\\TransportationMap.txt";
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qCritical() << "Failed to open file for writing: " << file.errorString();
        return false;
    }
  QTextStream stream(&file);

    int cnt{};
    string s="";
    // Write the graph edges
    set<string> visCities;
    for (const auto& city : Cities) {
        visCities.insert(city);
        map<string,vector<pair<string,int>>>mp;
        for(const auto& path:graph[city]){
            if(visCities.find(path.destination)==visCities.end())
                mp[path.destination].push_back({path.transportation,path.money});
        }
        for(const auto& path:mp){
            s+=city+" - "+path.first;
            cnt++;
            for(const auto&trans:path.second){
                s+=(" "+trans.first+" "+to_string(trans.second));
            }
            s+='\n';
        }
    }
    stream<<cnt<<'\n';
    stream<<s.c_str();
    file.close();
    return true;
}
