#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;x++)
#define down(x,a,b) for(ll x=a;x>=b;x--)
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a,b,p,ans;
ll fa[N];
bool sign[N];
inline void read(ll &a){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x*f;
}
inline ll find(ll x){
    if(fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}
int main(){
    read(a),read(b),read(p);
    ans=b-a+1;
    up(i,a,b)
        fa[i]=i;
    up(i,2,b){
        if(!sign[i]){
            if(i>=p){
                for(ll j=i*2;j<=b;j+=i){
                    sign[j]=1;
                    if(j-i>=a&&find(j)!=find(j-i)){
                        fa[find(j)]=find(j-i);
                        ans--;
                    }
                }
            }
            else{
                for(ll j=i*2;j<=b;j+=i)
                    sign[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}