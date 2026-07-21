#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int n,m;
int fa[N<<1];
int find(int x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
        fa[i]=i;
    while(m--){
        
    }
    return 0;
}