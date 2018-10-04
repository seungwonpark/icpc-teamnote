typedef pair<int, int> pii;
int V;

// adjacency list of graph. (connected node, weight)
vector<pii> adj[MAX_V];
// return an empty array if there's negative-weighted cycle
vector<int> bellmanFord(int src){
    // set all nodes to INF except for src.
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool updated;
    for(int iter=0; iter<V; iter++){
        updated = false;
        for(int here=0; here<V; here++){
            for(int i=0; i<adj[here].size(); i++){
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                // try relaxing through (here, there) edge
                if(upper[there] > upper[here] + cost){ // success
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        // exit the process if relaxing has failed for all nodes
        if(!updated) break;
    }
    // if relaxing was even successful for Vth search
    // there exists an negative cycle.
    if(updated) upper.clear();
    return upper;
}