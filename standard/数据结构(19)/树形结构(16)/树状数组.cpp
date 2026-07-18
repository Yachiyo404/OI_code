#include<bits/stdc++.h>
using namespace std;
int tree[100005],a[100005];
int m,n;
int lowbit(int x)
{
	return x&(-x);
}
void build(int n)
{
	for(int i=1;i<=n;i++)
	{
		tree[i]+=a[i];
		int j=i+lowbit(i);
		if(j<=n)
			tree[j]+=tree[i];
	}
}
void up(int i,int x)
{
	for(;i<=n;i+=lowbit(i))
		tree[i]+=x;
}
int getsum(int i)
{
	int sum=0;
	for(;i;i-=lowbit(i))
		sum+=tree[i];
	return sum;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(n);
	while(m--)
	{
		int x,y;
		char op;
		cin>>op>>x>>y;
		if(op=='x')
			up(x,y);
		else if(op=='y')
			cout<<getsum(y)-getsum(x-1)<<'\n';
	}
	return 0;
}
