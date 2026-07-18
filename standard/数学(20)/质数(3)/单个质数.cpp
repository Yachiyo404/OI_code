#include<bits/stdc++.h>
#define int long long
using namespace std;
bool ck(int x)
{
	if(x==1||x==0)
        return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
signed main()
{
	int n;
	cin>>n;
	if(ck(n))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
