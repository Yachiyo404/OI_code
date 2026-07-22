#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll n,ans;
//ll g[N],f[N];
char str[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>str+1;
    up(l,1,n-1){
        up(r,l+1,n){
            stack<char> sta;
            up(i,l,r){
                if(sta.empty()||str[i]!=sta.top())
                    sta.push(str[i]);
                else
                    sta.pop();
            }
            if(!sta.size())
                ans++;
        }
    }
    cout<<ans;
    return 0;
}