#include<bits/stdc++.h>
#define int long long
using namespace std;
int jc[21];
bool st[21];
signed main()
{
    jc[0]=1;
    for(int i=1;i<21;i++)
		jc[i]=jc[i-1]*i;
    int n,x;
    cin>>n>>x;
    x--;
    for(int i=1;i<=n;i++)
    {
        int tmp=x/jc[n-i];
        for(int j=1;j<=n;j++)
            if(!st[j])
            {
            	if(!tmp)
                {
                    cout<<j<<' ';
                    st[j]=1;
                    break;
                }
                tmp--;
			}
        x%=jc[n-i];
    }
    return 0;
}
