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
ll n,m;
ll xy[110][110];
bool vis[105][105][1000];
vector<ll> ans;
struct node{
    ll x,y;
    ll col;
    ll pri;
    bool flag;
};
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
    n=read(),m=read();
    up(i,1,n){
        ll x=read(),y=read(),c=read();
        xy[x][y]=++c;
    }
    queue<node> q;
    q.push({1,1,xy[1][1],0,0});
    while(q.size()){
        auto pos=q.front();
        q.pop();
        up(i,1,4){
            ll nx=pos.x,ny=pos.y,ncol=pos.col,npri=pos.pri;
            switch(i){
                case 1:nx++;break;
                case 2:nx--;break;
                case 3:ny++;break;
                case 4:ny--;
            }
            if((1<=nx&&nx<=m)&&(1<=ny&&ny<=m)){
                if(xy[ny][nx]==ncol&&!vis[ny][nx][npri]){
                    if(nx==m&&ny==m){
                        ans.push_back(npri);
                        continue;
                    }
                    vis[ny][nx][npri]=1;
                    q.push({nx,ny,xy[ny][nx],npri,0});
                }
                if(xy[ny][nx]!=ncol&&xy[ny][nx]&&!vis[ny][nx][npri]){
                    if(nx==m&&ny==m){
                        ans.push_back(npri+1);
                        continue;
                    }
                    vis[ny][nx][npri+1]=1;
                    q.push({nx,ny,xy[ny][nx],npri+1,0});
                }
                if(!xy[ny][nx]&&!vis[ny][nx][npri]){
                    if(!pos.flag){
                        if(nx==m&&ny==m){
                            ans.push_back(npri+2);
                            continue;
                        }
                        vis[ny][nx][npri+2]=1;
                        q.push({nx,ny,xy[ny][nx],npri+2,0});
                    }
                }
            }
        }
    }
    if(ans.size()){
        stable_sort(ans.begin(),ans.end());
        write(ans[0]);
    }
    else
        write(-1);
    return 0;
}