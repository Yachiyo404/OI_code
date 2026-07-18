#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
int n;
double a[15];
//普通的求多项式
double f(double x)
{
	double sum=0;
	for(int i=n;i>=0;i--)
	{
		double t=1;
		for(int j=1;j<=i;j++)
			t*=x;
		sum+=a[i]*t;
	}
	return sum;
}
//秦九韶算法从里到外逐层计算一次多项式的值
double f(double x)
{
	double sum=0;
	for(int i=n;i>=0;i--)
		sum=sum*x+a[i];
	return sum;
}
int main()
{
	double l,r;
	cin>>n>>l>>r;
	for(int i=n;i>=0;i--)
		cin>>a[i];
	while(fabs(l-r)>=eps)
	{
		double mid=(l+r)/2;
		if(f(mid+eps)>f(mid-eps))
			l=mid;
		else
			r=mid;
	}
	cout<<fixed<<setprecision(5)<<r;
	return 0;
}
--------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int n;
int a[10005],b[10005],c[10005];
double f(double x)
{
	double maxn=INT_MIN;
	for(int i=1;i<=n;i++)
		maxn=max(maxn,a[i]*x*x+b[i]*x+c[i]);
	return maxn;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		double l=0,r=1000;
		while(r-l>eps)
		{
			double mid1=(2*l+r)/3,mid2=(l+2*r)/3;
			if(f(mid1)<f(mid2))
				r=mid2;
			else
				l=mid1;
		}
		cout<<fixed<<setprecision(4)<<f(l)<<'\n';
	}
	return 0;
}
