#include<bits/stdc++.h>
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<20],*p1=buf,*p2=buf;
int read()
{
	int x=0,f=1;
    char c=gc();
	for(;!isdigit(c);c=gc())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=gc())
		x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
	return ;
}
signed main()
{
	int n=read(),ans=0;
	while(n--)
		ans+=read();
	write(ans);
	return 0;
}
