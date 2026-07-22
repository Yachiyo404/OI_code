#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int a[100001],b[100001],map[100001],f[100001];
signed main(){
    ios::sync_with_stdio(0);
	int n;
	cin>>n;
    /*for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int dp[5000][5000]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else    
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][n];*/
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        map[a[i]]=i;
    }
	for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        f[i]=0x7fffffff;
    }
	int len=0;
	f[0]=-1;
	for(int i=1;i<=n;i++){
		int l=0,r=len,mid;
		if(map[b[i]]>f[len])
            f[++len]=map[b[i]];
		else{
            while(l<r){
                mid=(l+r)/2;
                if(f[mid]>map[b[i]])
                    r=mid;
                else 
                    l=mid+1; 
            }
            f[l]=min(map[b[i]],f[l]);
     	}
    }
    cout<<len;
    return 0;
}