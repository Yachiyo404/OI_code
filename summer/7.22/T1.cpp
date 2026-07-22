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
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>m;
    ll len=lcm(n,(k+1));
    ll cnt=0,lst=1,sum=0;
    while(lst<len){
        sum=(sum+arr[((lst%n==0)?n:lst%n)])%mod;
        lst+=(k+1);
        cnt++;
    }
    if(m<cnt){
        cnt=0;
        sum=0;
        while(cnt<m){
            sum=(sum+arr[((lst%n==0)?n:lst%n)])%mod;
            lst+=(k+1);
            cnt++;
        }
        cout<<sum;
    }
    else{
        ll tot=m/cnt;
        ll ans=((tot%mod)*(sum%mod))%mod;
        m%=cnt;
        cnt=0;
        while(cnt<m){
            ans=(ans+arr[((lst%n==0)?n:lst%n)])%mod;
            lst+=(k+1);
            cnt++;
        }
        cout<<ans;
    }
    return 0;
}