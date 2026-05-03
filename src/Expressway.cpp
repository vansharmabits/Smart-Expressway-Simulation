#include "../include/Expressway.h"
#include <unordered_map>
#include <queue>
#include <fstream>

unordered_map<string, int> mp;

bool Expressway::loadFromFile(string filename) {
    ifstream in(filename);
    if(!in) return false;

    int m;
    in >> n >> m;
    city.resize(n);
    adj.resize(n);

    for(int i = 0; i < n; i++) {
        in >> city[i];
        int dummy; in >> dummy;
        mp[city[i]] = i;
    }

    for(int i = 0; i < m; i++) {
        string u, v;
        int d, t, c;
        in >> u >> v >> d >> t >> c;
        addRoad(u, v, d, t, c);
    }

    return true;
}

void Expressway::addRoad(string u, string v, int d, int t, int c) {
    int a = mp[u], b = mp[v];
    adj[a].push_back({b, d, t, c});
    adj[b].push_back({a, d, t, c});
}

tuple<int,int,int,int,vector<string>> Expressway::shortestPath(string src, string dest, char mode) {
    vector<int> dist(n, 1e9), parent(n, -1);
    int s = mp[src], d = mp[dest];

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto temp = pq.top();
        int cd = temp.first;
        int u = temp.second;

        for(auto &e : adj[u]) {
            int w = (mode == 'D') ? e.dist : (mode == 'T') ? e.time : e.toll;
            if(dist[e.v] > cd + w) {
                dist[e.v] = cd + w;
                parent[e.v] = u;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    vector<string> path;
    for(int v = d; v != -1; v = parent[v])
        path.push_back(city[v]);
    reverse(path.begin(), path.end());

    return {dist[d], 0, 0, 0, path};
}

bool Expressway::hasFuelArbitrage(vector<double>& rates) {
    vector<double> dist(n, 1e9);
    dist[0] = 0;

    for(int i = 0; i < n-1; i++) {
        for(int u = 0; u < n; u++) {
            for(auto &e : adj[u]) {
                if(dist[e.v] > dist[u] + rates[e.v])
                    dist[e.v] = dist[u] + rates[e.v];
            }
        }
    }

    return false;
}

pair<int, vector<tuple<string,string,int>>> Expressway::getMST() {
    vector<Road> roads;

    for(int u = 0; u < n; u++) {
        for(auto &e : adj[u]) {
            if(u < e.v)
                roads.push_back({u, e.v, e.dist});
        }
    }

    sort(roads.begin(), roads.end());
    DSU dsu(n);

    int cost = 0;
    vector<tuple<string,string,int>> res;

    for(auto &r : roads) {
        if(dsu.unite(r.u, r.v)) {
            cost += r.w;
            res.push_back({city[r.u], city[r.v], r.w});
        }
    }

    return {cost, res};
}

void Expressway::passVehicle(string id, string toll) {}
bool Expressway::checkVehicleSeen(string id) { return false; }

int Expressway::citiesInRange(int L, int R) {
    return R - L + 1;
}

void Expressway::printAllCities() {
    for(auto &c : city)
        cout << c << "\n";
}