#include<bits/stdc++.h>
using namespace std;
int top1=0,top2=0;
int heap1[100005],heap2[100005];
void up1(int x)
{
	while(x>1)
	{
		if(heap1[x/2]<heap1[x])
		{
			swap(heap1[x/2],heap1[x]);
			x/=2;
		}
		else
			break;
	}
}
void in1(int x)
{
	heap1[++top1]=x;
	up1(top1);
}
void down1(int x)
{
	int s=x*2;
	while(s<=top1)
	{
		if(s<top1&&heap1[s+1]>heap1[s])
			s++;
		if(heap1[s]>heap1[x])
		{
			swap(heap1[s],heap1[x]);
			x=s;
			s=x*2;
		}
		else
			break;
	}
}
void out1()
{
	heap1[1]=heap1[top1];
	top1--;
	down1(1);
}
void up2(int x)
{
	while(x>1)
	{
		if(heap2[x/2]>heap2[x])
		{
			swap(heap2[x/2],heap2[x]);
			x/=2;
		}
		else
			break;
	}
}
void in2(int x)
{
	heap2[++top2]=x;
	up2(top2);
}
void down2(int x)
{
	int s=x*2;
	while(s<=top2)
	{
		if(s<top2&&heap2[s+1]<heap2[s])
			s++;
		if(heap2[s]<heap2[x])
		{
			swap(heap2[s],heap2[x]);
			x=s;
			s=x*2;
		}
		else
			break;
	}
}
void out2()
{
	heap2[1]=heap2[top2];
	top2--;
	down2(1);
}
int main()
{
	int n,a;
	cin>>n>>a;
	in1(a);
	cout<<a<<'\n';
	for(int i=2;i<=n;i++)
	{
		cin>>a;
		if(a>heap1[1])
			in2(a);
		else
			in1(a);
		while(abs(top1-top2)>1)
		{
			if(top1>top2)
			{
				in2(heap1[1]);
				out1();
			}
			else
			{
				in1(heap2[1]);
				out2();
			}
		}
		if(i%2==1)
		{
			if(top1>top2)
				cout<<heap1[1]<<'\n';
			else
				cout<<heap2[1]<<'\n';
		}
	}
	return 0;
}
