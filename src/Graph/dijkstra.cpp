typedef pair<int, int> pii;
int V; // |G|

// adjacency list of graph. (connected node, weight)
vector<pii> adj[MAX_V];

vector<int> dijkstra(int src){
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(nextDist, there));
            }
        }
    }
}