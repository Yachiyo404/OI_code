#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#define mem(a,x) memset(a,x,sizeof(a))
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
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
struct node{
    int x,y,num;
};
int m,n,k;
vector<node> pos;
int main(){
    m=read(),n=read(),k=read();
    up(i,1,m){
        up(j,1,n){
            int a=read();
            if(a)
                pos.emplace_back((node){i,j,a});
        }
    }
    sort(pos.begin(),pos.end(),[](node a,node b){return a.num>b.num;});
    int t=1,cur_x=1,cur_y=pos[0].y,ans=0;
    for(auto nxt:pos){
         
    }
    
    return 0;
}