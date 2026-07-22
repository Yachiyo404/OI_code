#include<bits/stdc++.h>
#define ll long long
#define mem(a,m) memset(a,m,sizeof(a))
using namespace std;
const ll N=2e5+10;
ll n,m,op,a,b;
vector <ll> father(N);
vector <ll> size(N);
ll find(ll x){
    if(father[x]==x)
        return x;
    else 
        return father[x]=find(father[x]);
}
void combine(ll x,ll y){
    ll rootx=find(x);
    ll rooty=find(y);
    if(rootx!=rooty){
        if(size[rootx]<=size[rooty]){
            father[rootx]=rooty;
            size[rooty]+=size[rootx];
        }
        else{
            father[rooty]=rootx;
            size[rootx]+=size[rooty];
        }
    }
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        father[i]=i;
        size[i]=1;
    }
    for(ll i=1;i<=m;i++){
        scanf("%lld%lld%lld",&op,&a,&b);
        switch(op){
            case 1:
                combine(a,b);
                break;
            case 2:
                if(find(a)==find(b))
                    cout<<"Y"<<endl;
                else
                    cout<<"N"<<endl;
        }
    }
    return 0;
}