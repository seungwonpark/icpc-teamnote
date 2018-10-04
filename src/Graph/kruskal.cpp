struct DisjointSet;
const int MAX_V = 100;
int V;
typedef pair<int, int> pii;
vector<pii> adj[MAX_V];
int kruskal(vector<int>& selected){
    int ret = 0;
    selected.clear();
    vector<pair<int,pii>> edges;
    for(int u=0; u<V; u++){
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSet sets(V);
    for(int i=0; i<edges.size(); i++){
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}