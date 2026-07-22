#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+10,mod=1e9+7;
ll n,m,q;
ll fa[N];
set<ll> s;
set<pair<ll,ll>> c;
ll find(ll x){
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
ll fastpow(ll a,ll b,ll p){
    if(b==0)
        return 1;
    if(b==1)
        return a%p;
    ll ans=fastpow(a,b/2,p);
    if(b%2==1)
        return (ans%p*ans%p)*a%p;
    else
        return ans%p*ans%p;
}
void merge(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    fa[x]=y;
}
signed main(){
    ios::sync_with_stdio(0);
    // freopen("resonance.in","r",stdin);
    // freopen("resonance.out","w",stdout);
    cin>>n>>m>>q;
    for(ll i=1;i<=n;i++)
        fa[i]=i;
    if(n<=2000&&q<=2000){
        for(ll i=1;i<=q;i++){
            ll l,r;
            cin>>l>>r;
            for(ll j=l,k=r;j<k;j++,k--)
                merge(j,k);
        }
        for(ll i=1;i<=n;i++)
            s.insert(find(i));
        cout<<fastpow(m,s.size(),mod);
    }
    else{
        ll sum=0,l,r,flag=0;
        cin>>l>>r;
        c.insert({l,r});
        sum=l+r;
        for(int i=2;i<=q;i++){
            cin>>l>>r;
            if(l+r==sum)
                flag=1;
            else
                flag=0;
            c.insert({l,r});
        }
        if(!flag){
            for(auto i:c){
                for(ll j=i.first,k=i.second;j<k;j++,k--)
                    merge(j,k);
            }
        }
        else{
            for(int i=1,j=sum-1;i<j;i++,j--)
                merge(i,j);
        }
        for(ll i=1;i<=n;i++)
            s.insert(find(i));
        cout<<fastpow(m,s.size(),mod);
    }
    return 0;
}