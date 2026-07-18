#include<bits/stdc++.h>
using namespace std;
int dp[1005],w[105],t[105];
int main()
{
	int T,m;
    cin>>T>>m;
    for(int i=1;i<=m;i++)
        cin>>t[i]>>w[i];
    for(int i=1;i<=m;i++)
        for(int j=T;j>=t[i];j--)
            dp[j]=max(dp[j],dp[j-t[i]]+w[i]);
    cout<<dp[T];
    return 0;
}
