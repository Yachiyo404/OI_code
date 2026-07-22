//双哈希
#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
inline pair<ull,ull> str_hash(char *s){
    ull p1=131,p2=1313,h1=0,h2=0;
    ll len=strlen(s);
    up(i,0,len-1)
        h1=h1*p1+s[i];
    up(i,0,len-1)
        h2=h2*p2+s[i];
    return {h1,h2};
}
int main(){
    ll n;
    read(n);
    set<pair<ull,ull>> s;
    while(n--){
        char str[2010];
        scanf("%s",str);
        s.insert(str_hash(str));
    }
    printf("%lld",s.size());
    return 0;
}