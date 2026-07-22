#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,dp[11][11][11][11][11];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		for(int j=1;j<=9;j++){
			dp[(a+j)%10][b][c][d][e]++;
			dp[a][(b+j)%10][c][d][e]++;
			dp[a][b][(c+j)%10][d][e]++;
			dp[a][b][c][(d+j)%10][e]++;
			dp[a][b][c][d][(e+j)%10]++;
			dp[(a+j)%10][(b+j)%10][c][d][e]++;
			dp[a][(b+j)%10][(c+j)%10][d][e]++;
			dp[a][b][(c+j)%10][(d+j)%10][e]++;
			dp[a][b][c][(d+j)%10][(e+j)%10]++;
		}
	}
	for(int i=0;i<=9;i++)
	    for(int j=0;j<=9;j++)
	        for(int k=0;k<=9;k++)
	            for(int u=0;u<=9;u++)
	                for(int v=0;v<=9;v++)
	                    if(dp[i][j][k][u][v]==n)
                            ans++;
	cout<<ans;
	return 0;
}