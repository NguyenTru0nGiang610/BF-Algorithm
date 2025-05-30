#include "bellman.h"


void BF(int edge[][3], int numberOfEdges, char startVertex, int BellmanFordValue[], int BellmanFordPrevious[]) {
    static std::vector<char> nodes;
    static bool initialized = false;

    if (!initialized) {
        for (int i = 0; i < numberOfEdges; i++) {
            char u = edge[i][0];
            char v = edge[i][1];
            if (std::find(nodes.begin(), nodes.end(), u) == nodes.end())
                nodes.push_back(u);
            if (std::find(nodes.begin(), nodes.end(), v) == nodes.end())
                nodes.push_back(v);
        }
        initialized = true;
    }

    int startIdx = std::find(nodes.begin(), nodes.end(), startVertex) - nodes.begin();
    if (BellmanFordValue[startIdx] == -1) {
        BellmanFordValue[startIdx] = 0;
    }

    for (int i = 0; i < numberOfEdges; i++) {
        int u = std::find(nodes.begin(), nodes.end(), edge[i][0]) - nodes.begin();
        int v = std::find(nodes.begin(), nodes.end(), edge[i][1]) - nodes.begin();
        int wt = edge[i][2];

        if (BellmanFordValue[u] != -1 && (BellmanFordValue[v] == -1 || BellmanFordValue[u] + wt < BellmanFordValue[v])) {
            BellmanFordValue[v] = BellmanFordValue[u] + wt;
            BellmanFordPrevious[v] = u;
        }
    }
}

string BF_Path(int edge[][3], int numberOfEdges, char startVertex, char goalVertex) {
    vector<char> nodes;

    for (int i = 0; i < numberOfEdges; i++) {
        char u = edge[i][0];
        char v = edge[i][1];
        if (find(nodes.begin(), nodes.end(), u) == nodes.end())
            nodes.push_back(u);
        if (find(nodes.begin(), nodes.end(), v) == nodes.end())
            nodes.push_back(v);
    }

    int V = nodes.size();
    vector<int> dist(V, INT_MAX);
    vector<int> prev(V, -1);
    int startIndex = find(nodes.begin(), nodes.end(), startVertex) - nodes.begin();
    int goalIndex = find(nodes.begin(), nodes.end(), goalVertex) - nodes.begin();
    dist[startIndex] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < numberOfEdges; j++) {
            int u = find(nodes.begin(), nodes.end(), edge[j][0]) - nodes.begin();
            int v = find(nodes.begin(), nodes.end(), edge[j][1]) - nodes.begin();
            int wt = edge[j][2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                prev[v] = u;
            }
        }
    }
    if (dist[goalIndex] == -1) return "NO PATH";
    vector<char> pathChars;
    for (int cur = goalIndex; cur != -1; cur = prev[cur])
        pathChars.push_back(nodes[cur]);
    reverse(pathChars.begin(), pathChars.end());
    string result;
    for (size_t i = 0; i < pathChars.size(); i++) {
        result += pathChars[i];
        if (i < pathChars.size() - 1)
            result += ' ';
    }

    return result;
}


