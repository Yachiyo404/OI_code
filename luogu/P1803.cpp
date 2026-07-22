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
const int N=1e6+10;
struct node{
    int st,ed;
}num[N];
int main(){
    int n=read();
    up(i,1,n)
        num[i].st=read(),num[i].ed=read();
    sort(num+1,num+n+1,[](node a,node b){return a.ed<b.ed;});
    int s=num[1].ed,j=1,sum=1;
    while(j<=n){
        j++;
        if(num[j].st>=s){
            sum++;
            s=num[j].ed;
        }
    }
    write(sum);
    return 0;
}