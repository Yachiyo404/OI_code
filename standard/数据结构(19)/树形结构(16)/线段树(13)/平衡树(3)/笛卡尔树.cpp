#include<bits/stdc++.h>
#define int long long
using namespace std;
struct cxt
{
	int l,r,w;
}t[10000005];
void build(int n)
{
	stack<int>S;
	S.push(0);
	for(int i=1;i<=n;i++)
	{
		while(!S.empty()&&t[S.top()].w>t[i].w)
			S.pop();
		t[i].l=t[S.top()].r;
		t[S.top()].r=i;
		S.push(i);
	}
	return ;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i].w;
	build(n);
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		ans1^=(i*(t[i].l+1));
		ans2^=(i*(t[i].r+1));
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
