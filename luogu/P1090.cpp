#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,num[10005],ans;
int main(){
    ios::sync_with_stdio(0);
    //freopen("P1090_6.in","r",stdin);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>num[i];
    sort(num+1,num+n+1);
    for(ll j=1;j<=n-1;j++){
        num[j+1]+=num[j];
        ans+=num[j+1];
        sort(num+j+1,num+n+1);
    }
    cout<<ans;
    return 0;
}