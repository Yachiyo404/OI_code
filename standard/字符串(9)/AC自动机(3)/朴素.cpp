#include<bits/stdc++.h>
using namespace std;
struct cxt
{
	int son[26],cnt,fail;
}t[1000005];
int id;
void insert(string s)
{
	int now=0;
	for(int i=0;s[i];i++)
	{
		int k=s[i]-'a';
		if(t[now].son[k]==0)
			t[now].son[k]=++id;
		now=t[now].son[k];
	}
	t[now].cnt++;
	return ;
}
void build()
{
	queue<int>q;
	for(int i=0;i<=25;i++)
		if(t[0].son[i])
			q.push(t[0].son[i]);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<=25;i++)
		{
			if(t[x].son[i])
			{
				t[t[x].son[i]].fail=t[t[x].fail].son[i];
				q.push(t[x].son[i]);
			}
			else
				t[x].son[i]=t[t[x].fail].son[i];
		}
	}
	return ;
}
int query(string s)
{
	int sum=0,now=0;
	for(int i=0;s[i];i++)
	{
		int k=s[i]-'a';
		now=t[now].son[k];
		for(int j=now;j&&t[j].cnt!=-1;j=t[j].fail)
		{
			sum+=t[j].cnt;
			t[j].cnt=-1;
		}
	}
	return sum;
}
string s;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		insert(s);
	}
	build();
	cin>>s;
	cout<<query(s);
	return 0;
}
