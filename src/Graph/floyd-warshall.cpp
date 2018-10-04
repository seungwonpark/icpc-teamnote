for(int k=0; k<V; k++){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
    }
}