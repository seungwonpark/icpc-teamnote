// length of LIS
// https://www.acmicpc.net/source/427134 (portableangel)
#include <stdio.h>
#include <vector>

using namespace std;

int arr[100001], n;
vector<int> lis;

int b(int l, int r, int k) {
	if(l+1==r) return r;
	if(lis[(l+r)/2]<k) return b((l+r)/2,r,k);
	else return b(l,(l+r)/2,k);
}

void f(int s) {
	if(s==n) return;
	if(lis.empty() || lis[lis.size()-1]<arr[s]) lis.push_back(arr[s]);
	else if(lis[0]>=arr[s]) lis[0]=arr[s];
	else lis[b(0,lis.size()-1,arr[s])]=arr[s];
	f(s+1);
}

int main() {
	while(scanf("%d",&n) != -1){
		lis.clear();
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		f(0);
		printf("%d\n",lis.size());
	}
}