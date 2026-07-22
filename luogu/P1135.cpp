#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
ll step[205],vis[205];
vector<ll> ans;
inline ll read(){
    ll x=0,f=1;
    char ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=gc();
    }
    return x*f;
}
inline void write(ll a){
    if(a<0){
        pc('-');
        a=-a;
    }
    if(a>9)
        write(a/10);
    pc(a%10+'0');
}
int main(){
    ll n=read(),a=read(),b=read();
    up(i,1,n)
        step[i]=read();
    if(a==b){
        cout<<0;
        return 0;
    }
    queue<pair<ll,ll>> q;
    q.push({a,0});
    while(q.size()){
        auto pos=q.front();
        q.pop();
        up(i,1,2){
            ll npos=pos.first,ncnt=pos.second;
            if(i==1){
                npos+=step[npos];
                if(npos<=n&&npos!=b&&!vis[npos]){
                    q.push({npos,ncnt+1});
                    vis[npos]=1;
                }
                if(npos==b)
                    ans.push_back(ncnt+1);
            }
            else{
                npos-=step[npos];
                if(npos>=1&&npos!=b&&!vis[npos]){
                    q.push({npos,ncnt+1});
                    vis[npos]=1;
                }
                if(npos==b)
                    ans.push_back(ncnt+1);
            }
        }
    }
    if(ans.size()){
        sort(ans.begin(),ans.end());
        cout<<ans[0];
    }
    else
        cout<<-1;
    return 0;
}