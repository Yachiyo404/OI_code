#include<bits/stdc++.h>
using namespace std;
int fa[200005];
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    int m,n,i,j,k,x,y,z;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        fa[i]=i;
    for(i=1;i<=m;i++)
    {
        cin>>z>>x>>y;
        if(z==1)
        {
            x=find(x);
            y=find(y);
            fa[y]=x;
        }    
        if(z==2)
        {
            x=find(x);
            y=find(y);
            if(x==y)
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }
    }
    return 0;
}
