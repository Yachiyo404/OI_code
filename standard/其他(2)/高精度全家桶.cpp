#include<bits/stdc++.h>
#define int long long
using namespace std;
struct gaojingdu
{
	int sum[114514],len;
	bool flag;
	void clear()
	{
		memset(sum,0,sizeof(sum));
		len=0;
		flag=1;
		return ;
	}
	gaojingdu operator=(string s)
	{
		int l=s.size();
		this->clear();
		for(int i=l-1;i>=0;i--)
		{
			this->len++;
			this->sum[this->len]=(s[i]^48);
		}
		return *this;
	}
	gaojingdu operator=(int num)
	{
		this->clear();
		while(num)
		{
			this->len++;
			this->sum[this->len]=(num%10);
			num/=10;
		}
		return *this;
	}
	friend gaojingdu operator+(gaojingdu x,gaojingdu y)
	{
		int jw=0;
		gaojingdu c;
		c.clear();
		c.len=max(x.len,y.len)+1;
		for(int i=1;i<=c.len;i++)
		{
			c.sum[i]=x.sum[i]+y.sum[i]+jw;
			jw=c.sum[i]/10;
			c.sum[i]%=10;
		}
		while(c.sum[c.len]==0&&c.len)
			c.len--;
		return c;
	}
	gaojingdu operator+=(gaojingdu x)
	{
		*this=*this+x;
		return *this;
	}
	friend bool operator==(gaojingdu x,gaojingdu y)
	{
		int l=max(x.len,y.len);
		for(int i=0;i<l;i++)
			if(x.sum[l-i]!=y.sum[l-i])
				return 0;
		return 1;
	}
	friend bool operator>(gaojingdu x,gaojingdu y)
	{
		if(x.len!=y.len)
			return x.len>y.len;
		int l=max(x.len,y.len);
		for(int i=0;i<l;i++)
			if(x.sum[l-i]!=y.sum[l-i])
				return x.sum[l-i]>y.sum[l-i];
		return 0;
	}
	friend bool operator<(gaojingdu x,gaojingdu y)
	{
		if(x.len!=y.len)
			return x.len<y.len;
		int l=max(x.len,y.len);
		for(int i=0;i<l;i++)
			if(x.sum[l-i]!=y.sum[l-i])
				return x.sum[l-i]<y.sum[l-i];
		return 0;
	}
	friend bool operator>=(gaojingdu x,gaojingdu y)
	{
		if(x>y||x==y)
			return 1;
		return 0;
	}
	friend bool operator<=(gaojingdu x,gaojingdu y)
	{
		if(x<y||x==y)
			return 1;
		return 0;
	}
	friend bool operator!=(gaojingdu x,gaojingdu y)
	{
		if(x==y)
			return 0;
		return 1;
	}
	friend gaojingdu operator-(gaojingdu x,gaojingdu y)
	{
		gaojingdu c;
		c.clear();
		c.len=max(x.len,y.len)+1;
		if(x<y)
			c.flag=0;
		for(int i=1;i<=c.len;i++)
		{
			if(c.flag)
				c.sum[i]+=(x.sum[i]-y.sum[i]);
			else
				c.sum[i]+=(y.sum[i]-x.sum[i]);
			if(c.sum[i]<0)
			{
				c.sum[i]+=10;
				c.sum[i+1]--;
			}
		}
		while(c.sum[c.len]==0&&c.len)
			c.len--;
		return c;
	}
	gaojingdu operator-=(gaojingdu x)
	{
		*this=*this-x;
		return *this;
	}
	friend gaojingdu operator*(gaojingdu x,gaojingdu y)
	{
		gaojingdu c;
		c.clear();
		c.len=x.len+y.len;
		for(int i=1;i<=x.len;i++)
		{
			int jw=0;
			for(int j=1;j<=y.len;j++)
			{
				c.sum[i+j-1]+=(x.sum[i]*y.sum[j]+jw);
				jw=c.sum[i+j-1]/10;
				c.sum[i+j-1]%=10;
			}
			c.sum[i+y.len]=jw;
		}
		while(c.sum[c.len]==0&&c.len)
			c.len--;
		return c;
	}
	gaojingdu operator*=(gaojingdu x)
	{
		*this=*this*x;
		return *this;
	}
	friend gaojingdu operator/(gaojingdu x,gaojingdu y)
	{
		gaojingdu c,tmp;
		c.clear();
		c.len=x.len-y.len+1;
		for(int i=c.len;i;i--)
		{
			tmp.clear();
			for(int j=1;j<=y.len;j++)
				tmp.sum[i+j-1]=y.sum[j];
			tmp.len=y.len+i-1;
			while(x>=tmp)
			{
				x-=tmp;
				c.sum[i]++;
			}
		}
		while(c.sum[c.len]==0&&c.len)
			c.len--;
		if(c.len<1)
			c.clear();
		return c;
	}
	gaojingdu operator/=(gaojingdu x)
	{
		*this=*this/x;
		return *this;
	}
	friend gaojingdu operator%(gaojingdu x,gaojingdu y)
	{
		gaojingdu c=x/y;
		c*=y;
		x-=c;
		return x;
	}
	gaojingdu operator%=(gaojingdu x)
	{
		*this=*this%x;
		return *this;
	}
}a,b;
void out(gaojingdu x)
{
	for(int i=x.len;i;i--)
		putchar(x.sum[i]+48);
	return ;
}
signed main()
{
	
	return 0;
}
