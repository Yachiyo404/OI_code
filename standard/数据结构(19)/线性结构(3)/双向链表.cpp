#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node
{
	int pre,nxt;
}lst[500005];
bool vis[500005];
void shan(int x)
{
    if(!vis[x])
		return ;
    if(lst[x].pre)
		lst[lst[x].pre].nxt=lst[x].nxt;
    if(lst[x].nxt)
		lst[lst[x].nxt].pre=lst[x].pre;
    lst[x].pre=lst[x].nxt=0;
    vis[x]=0;
    return ;
}
void left(int x,int y)
{
	if(x==y)
		return ;
	if(vis[x])
		shan(x);
	lst[x].nxt=y;
	lst[x].pre=lst[y].pre;
	if(lst[y].pre)
		lst[lst[y].pre].nxt=x;
	lst[y].pre=x;
	vis[x]=1;
	return ;
}
void right(int x,int y)
{
	if(x==y)
		return ;
	if(vis[x])
		shan(x);
	lst[x].pre=y;
	lst[x].nxt=lst[y].nxt;
	if(lst[y].nxt)
		lst[lst[y].nxt].pre=x;
	lst[y].nxt=x;
	vis[x]=1;
	return ;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
			lst[i].pre=i-1;
		if(i!=n)
			lst[i].nxt=i+1;
		vis[i]=1;
	}
	lst[1].pre=0;
	lst[n].nxt=0;
	while(m--)
    {
    	int op,x,y;
    	cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			left(x,y);
		}
		else if(op==2)
		{
			cin>>x>>y;
			right(x,y);
		}
		else
		{
			cin>>x;
			shan(x);
		} 
	}
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(lst[i].pre==0&&vis[i])
		{
			pos=i;
			break;
		}
	}
	if(pos==0)
		cout<<"Empty!";
	else
	{
		while(pos!=0)
		{
			cout<<pos<<" ";
			pos=lst[pos].nxt;
		}
	}
	return 0;
}
