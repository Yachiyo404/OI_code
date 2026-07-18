#include<bits/stdc++.h>
using namespace std;
int a[300005],b[300005],c[300005];
int main()
{
	int n,top=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
//	b[n+1]=INT_MIN or INT_MAX or 0;
	for(int i=2;i<=n+1;i++)
		if(b[i]!=b[i-1])
			c[++top]=b[i-1];
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(c+1,c+top+1,a[i])-c;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
    return 0;
}
