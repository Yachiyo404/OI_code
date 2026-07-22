#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt=1;
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
inline void dfs(ll a){
    
}
int main(){
    read(n);
    dfs(n);
    return 0;
}