#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,k,p,now,ans;
ll cnt[N],sum[N],last[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k>>p;
    for(ll i=1;i<=n;i++){
        ll col,pri;
        cin>>col>>pri;
        if(pri<=p)
            now=i;
        if(now>=last[col])
            sum[col]=cnt[col];
        last[col]=i;
        ans+=sum[col];
        cnt[col]++;
    }
    cout<<ans;
    return 0;
}