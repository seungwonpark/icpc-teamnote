#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int a[100010], b[100010], f[100010];
int answer;
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; i++){
        f[i] = lower_bound(b+1, b+answer+1, a[i]) - b;
        answer = max(answer, f[i]);
        b[f[i]] = a[i];
    }
    vector<int> T;
    int require = answer;
    for(int i=n; i>=1; i--){
        if(f[i] == require){
            T.push_back(a[i]);
            require--;
        }
    }
    reverse(T.begin(), T.end());
    for(int x : T){
        printf("%d ", x);
    }
    puts("");
}