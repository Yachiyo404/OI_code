#include<bits/stdc++.h>
using namespace std;
struct cxt
{
	int son[26],cnt,fail,idx;
}t[200005];
int id,in[200005],mp[200005],ans[200005];
void insert(string s,int x)
{
	int now=0;
	for(int i=0;s[i];i++)
	{
		int k=s[i]-'a';
		if(t[now].son[k]==0)
			t[now].son[k]=++id;
		now=t[now].son[k];
	}
	if(!t[now].idx)
		t[now].idx=x;
	mp[x]=t[now].idx;
	return ;
}
queue<int>q;
void build()
{
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
				in[t[t[x].son[i]].fail]++;
				q.push(t[x].son[i]);
			}
			else
				t[x].son[i]=t[t[x].fail].son[i];
		}
	}
	return ;
}
void query(string s)
{
	int now=0;
	for(int i=0;s[i];i++)
	{
		int k=s[i]-'a';
		now=t[now].son[k];
		t[now].cnt++;
	}
	return ;
}
string s;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		insert(s,i);
	}
	build();
	cin>>s;
	query(s);
	for(int i=0;i<=id;i++)
    	if(in[i]==0)
			q.push(i);
    while(!q.empty())
	{
        int x=q.front();
		q.pop();
		ans[t[x].idx]=t[x].cnt;
		in[t[x].fail]--;
        t[t[x].fail].cnt+=t[x].cnt;
        if(in[t[x].fail]==0)
			q.push(t[x].fail);
    }
    for(int i=1;i<=n;i++)
    	cout<<ans[mp[i]]<<'\n';
	return 0;
}
