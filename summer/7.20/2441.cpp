#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,mod;
vector<int> g[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>mod;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    return 0;
}