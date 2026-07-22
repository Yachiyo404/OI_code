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
ll read(){
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
void write(ll a){
    if(a<0){
        pc('-');
        a=-a;
    }
    if(a>9)
        write(a/10);
    pc(a%10+'0');
} 

int main(){
    

    
    return 0;
}