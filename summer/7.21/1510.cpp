#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
int n,k;
ll ans;
int fa[N*3];
int find(int x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    fa[x]=y;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n*3;i++)
        fa[i]=i;
    while(k--){
        int op,x,y;
        cin>>op>>x>>y;
        if(x>n||y>n){
            ans++;
            continue;
        }
        if(op==1){
            if(find(x+n)==find(y)||find(x)==find(y+n))
                ans++;
            else{
                merge(x,y);
                merge(x+n,y+n);
                merge(x+n*2,y+n*2);
            }
        }
        else{
            if(x==y)
                ans++;
            else{
                if(find(x)==find(y)||find(x)==find(y+n))
                    ans++;
                else{
                    merge(x,y+n*2);
                    merge(x+n,y);
                    merge(x+n*2,y+n);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}