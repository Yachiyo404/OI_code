#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int main(){
    ios::sync_with_stdio(0);
    freopen("colony.in","r",stdin);
    freopen("colony.out","w",stdout);
    cin>>T;
    while(T--){
        ll n,k,m;
        cin>>n>>k>>m;
        ll l=k-1,r=n-k;
        ll x=min({n-1,2*(m+1)/3,(m+l+1)/2,(m+r+1)/2});
        cout<<x+1<<endl;
    }
    return 0;
}   