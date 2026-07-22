#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans=-1;
int a[5010],dp1[5010];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++){
	    for(int j=0;j<i;j++){
	    	if(a[j]<a[i])
	    		dp1[i]=max(dp1[i],dp1[j]+1);
	    }
    }
    for(ll i=1;i<=n;i++)
        ans=max(ans,dp1[i]);
    cout<<ans;
    return 0;
}