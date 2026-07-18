#include<bits/stdc++.h>
#define int long long
#define _ __int128
using namespace std;
int in[100005];
_ fenzi[100005],fenmu[100005];
queue<int>q;
vector<int>tu[100005];
_ min_gcd(_ x,_ y)
{
    while(y!=0)
	{
        _ temp=y;
        y=x%y;
        x=temp;
    }
    return x;
}
_ max_gcd(_ x,_ y)
{
	_ z=min_gcd(x,y);
	return x/z*y;
}
void huajian(_ &x,_ &y)
{
	_ z=min_gcd(x,y);
	x/=z;
	y/=z;
	return ;
}
void jia(_ &a,_ &b,_ c,_ d)
{
	if(b==0)
	{
		a=c;
		b=d;
		return ;
	}
	if(b!=d)
	{
		_ e=max_gcd(b,d);
		_ f=e/b*a;
		_ g=e/d*c;
		a=f;
		b=e;
		c=g;
	}
	a+=c;
	return ;
}
void write(_ x)
{
    if(x>9)
		write(x/10);
    putchar(x%10+'0');
}
signed main()
{
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		while(x--)
		{
			int y;
			cin>>y;
			in[y]++;
			tu[i].push_back(y);
		}
	}
	for(int i=1;i<=m;i++)
	{
		fenzi[i]=1;
		fenmu[i]=1;
		if(!in[i])
			q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(tu[x].empty())
			continue;
		int cnt=tu[x].size();
		fenmu[x]*=cnt;
		huajian(fenzi[x],fenmu[x]);
		for(int i=0;i<cnt;i++)
		{
			int j=tu[x][i];
			in[j]--;
			if(!in[j])
				q.push(j);
			jia(fenzi[j],fenmu[j],fenzi[x],fenmu[x]);
			huajian(fenzi[j],fenmu[j]);
		}
	}
	for(int i=1;i<=n;i++)
		if(tu[i].empty())
		{
			write(fenzi[i]);
			cout<<" ";
			write(fenmu[i]);
			cout<<'\n';
		}
	return 0;
}
