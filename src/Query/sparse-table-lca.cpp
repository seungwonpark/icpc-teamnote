#include <stdio.h>
#include <vector>
using namespace std;
vector<int> G[100010];
int n,m;
int par[21][100010];
int depth[100010];
bool visited[100010];
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void dfs(int a, int d){
	depth[a] = d;
	visited[a] = true;
	for(int i=0;i<G[a].size();i++){
		int next = G[a][i];
		if(!visited[next]){
			dfs(next, d+1);
			par[0][next] = a;
		}
	}
}
int lca(int a, int b){
	if(depth[a] < depth[b]) swap(a,b);
	int diff = depth[a] - depth[b];
	for(int i=0;i<20;i++){
		if((diff & (1<<i)) != 0){
			a = par[i][a];
		}
	}
	if(a == b) return a;
	for(int i=19;i>=0;i--){
		if(par[i][a] != par[i][b]){
			a = par[i][a];
			b = par[i][b];
		}
	}
	return par[0][a];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1,0);
	for(int k=1;k<20;k++){
		for(int i=1;i<=n;i++){
			par[k][i] = par[k-1][par[k-1][i]];
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n", lca(a,b));
	}
}