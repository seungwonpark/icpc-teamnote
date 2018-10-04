// from jason9319.tistory.com/356
for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    idx.push_back(a[i]);
}
for(int i=0; i<m; i++){
    scanf("%d", &x);
    idx.push_back(x);
}
sort(idx.begin(), idx.end());
idx.erase(unique(idx.begin(), idx.end()), idx.end());
int getidx(int x){
    return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
}