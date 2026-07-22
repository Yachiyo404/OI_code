//单哈希
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
inline ull str_hash(char *s){
    ull p=131,h=0;
    ll len=strlen(s);
    up(i,0,len-1)
        h=h*p+s[i];
    return h;
}
int main(){
    ll n;
    read(n);
    unordered_set<ull> s;
    while(n--){
        char str[2010];
        scanf("%s",str);
        s.insert(str_hash(str));
    }
    printf("%lld",s.size());
    return 0;
}