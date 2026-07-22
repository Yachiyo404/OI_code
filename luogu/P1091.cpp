#include <bits/stdc++.h>
using namespace std;
int n,ans=-1;
int a[1007],dp1[1007],dp2[1007];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++){
	    for(int j=0;j<i;j++){
	    	if(a[j]<a[i]){
				//printf("a[i]=%d a[j]=%d dpi=%d dpj=%d i=%d j=%d\n",a[i],a[j],dp1[i],dp1[j],i,j);
	    		dp1[i]=max(dp1[i],dp1[j]+1);
	    		//printf("a[i]=%d a[j]=%d dpi=%d dpj=%d i=%d j=%d\n",a[i],a[j],dp2[i],dp2[j],i,j);
			}
		}
	}
    for(int i=n;i>0;i--){
	    for(int j=n+1;j>i;j--){
	    	if(a[j]<a[i]){
	    		//printf("a[i]=%d a[j]=%d dpi=%d dpj=%d i=%d j=%d\n",a[i],a[j],dp2[i],dp2[j],i,j);
				dp2[i]=max(dp2[i],dp2[j]+1);
				//printf("a[i]=%d a[j]=%d dpi=%d dpj=%d i=%d j=%d\n",a[i],a[j],dp2[i],dp2[j],i,j);
			}
		}
	    for(int i=1;i<=n;i++){
	    	ans=max(dp1[i]+dp2[i]-1,ans);
		}
	}
    cout<<n-ans;
    return 0;
}