#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e7;
ll num[1005][1005];
ll ans,n;
int main(){
    scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++)
			scanf("%lld",&num[i][j]);
	}
	for(ll i=n-1;i>=1;i--){
		for(ll j=1;j<=i;j++)
			num[i][j]+=max(num[i+1][j],num[i+1][j+1]);
	}
	cout<<num[1][1];
    return 0;
}