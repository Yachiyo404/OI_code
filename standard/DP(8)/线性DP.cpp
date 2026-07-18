#include<bits/stdc++.h>
using namespace std;
int a[105],f[105],g[105];
int main()
{
	int n,maxn=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=g[i]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[i]>a[j])
                f[i]=max(f[i],f[j]+1);
    for(int i=n;i;i--)
        for(int j=n;j>i;j--)
            if(a[i]>a[j])
                g[i]=max(g[i],g[j]+1);
    for(int i=1;i<=n;i++)
        maxn=max(maxn,f[i]+g[i]-1);
    cout<<n-maxn;
    return 0;
}
