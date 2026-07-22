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
const int N=1010;
int n;
double st,xans,yans,ans=1e18+7;
struct node{
    double x,y,w;
}obj[N];
inline double count(double x,double y){
    double result=0;
    up(i,1,n)
        result+=(sqrt(abs(x-obj[i].x)*abs(x-obj[i].x)+abs(y-obj[i].y)*abs(y-obj[i].y)))*obj[i].w;
    return result;
}
inline void solve(){
    double xx=xans,yy=yans;
    for(double t=10000;t>=1e-14;t*=0.999){
        if(((double)clock()-st)/(double)CLOCKS_PER_SEC>=0.99){
            printf("%.3lf %.3lf",xans,yans);
            exit(0);
        }
        double tmpx=xans+(rand()*2-RAND_MAX)*t;
        double tmpy=yans+(rand()*2-RAND_MAX)*t;
        double tmpans=count(tmpx,tmpy);
        if(ans>tmpans){
            xx=tmpx;
            yy=tmpy;
            xans=xx;
            yans=yy;
            ans=tmpans;
        }
        else if(exp(-(tmpans-ans)/t)*RAND_MAX>rand()){
            xx=tmpx;
            yy=tmpy;
        }
    }
}
int main(){
    random_device rd;
    srand(rd());
    st=clock();
    n=read();
    up(i,1,n){
        obj[i].x=read();
        obj[i].y=read();
        obj[i].w=read();
    }
    while(1)
        solve();
    return 0;
}