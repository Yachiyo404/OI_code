#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,cnt;
ll mem[10];
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
    return;
}

inline void dfs(ll num,ll kr,ll sum){
    if(kr==1&&sum+num==n){
        cnt++;
        return;
    }
    if(num<=0)
        return;
    for(ll i=1;i<=num;i++){
        dfs(num-i,kr-1,sum+i);
        kr++;
    }
}
int main(){
    read(n),read(k);
    dfs(n,k,0);
    cout<<cnt;
    return 0;
}