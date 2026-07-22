#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t int128;
const int N=1e6+10,mod=1e9+7;
ll n,k,m;
ll ans;
ll arr[N];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}
int main(){
    ios::sync_with_stdio(0);
    // freopen("","r",stdin);
    // freopen("","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>m;
    
    return 0;
}