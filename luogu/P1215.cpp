#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c;
vector<ll> ans;
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
inline void dfs(ll x,ll y,ll z){
    if(x==0){
        ans.push_back(z);
        return;
    }
    

}
int main(){
    read(a),read(b),read(c);
    ans.push_back(c);
    dfs(0,0,c);
    stable_sort(ans.begin(),ans.end(),greater<ll>());
    while(ans.size()){
        printf("%lld ",ans.back());
        ans.pop_back();
    }
    return 0;
}