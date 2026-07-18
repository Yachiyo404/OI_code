#include<bits/stdc++.h>
using namespace std;
struct cxt
{
	int son[65];
}tree[3000005];
int cnt[3000005];
int cg(char x)
{
	if(x>='A'&&x<='Z')
		return x-'A';
	else if(x>='a'&&x<='z')
		return x-'a'+26;
	else
		return x-'0'+52;
}
int id;
void insert(char s[])
{
	int now=0;
	for(int i=0;s[i]!='\0';i++)
	{
		int c=cg(s[i]);
		if(tree[now].son[c]==0)
			tree[now].son[c]=++id;
		now=tree[now].son[c];
		cnt[now]++;
	}
	return ;
}
int find(char s[])
{
	int now=0;
	for(int i=0;i<s[i]!='\0';i++)
	{
		int c=cg(s[i]);
		if(tree[now].son[c]==0)
			return 0;
		now=tree[now].son[c];
	}
	return cnt[now];
}
signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		for(int i=0;i<=id;i++)
            for(int j=0;j<=62;j++)
                tree[i].son[j]=0;
        for(int i=0;i<=id;i++)
            cnt[i]=0;
		id=0;
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;i++)
		{
			char s[100005];
			cin>>s;
			insert(s);
		}
		while(q--)
		{
			char s[100005];
			cin>>s;
			cout<<find(s)<<'\n';
		}
	}
	return 0;
}
