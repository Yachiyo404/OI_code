#include<bits/stdc++.h>
using namespace std;
vector<int>tu[500005];
int fa[500005][21],deep[500005];
bool vis[500005];
void dfs(int x)
{
    for(int i:tu[x])
	{
		if(!vis[i])
		{
			vis[i]=1;
			deep[i]=deep[x]+1;
			fa[i][0]=x;
	        dfs(i);
		}
    }
    return ;
}
int lca(int x,int y)
{
    if(deep[x]<deep[y])
		swap(x,y);
    for(int i=20;i>=0;i--)
        if(deep[fa[x][i]]>=deep[y])
            x=fa[x][i];
    if(x==y)
        return x;
    for(int i=20;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
		{
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<n;i++)
	{
        int x,y;
        cin>>x>>y;
    	tu[x].push_back(y);
    	tu[y].push_back(x);  
    }
    deep[s]=1;
    fa[s][0]=0;
    vis[s]=1;
    dfs(s);
    for(int j=1;j<21;j++)
        for(int i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    while(m--)
	{
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }
    return 0;
}
