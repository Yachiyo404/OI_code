#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+10;
int n,m;
int arr[N],lg2[N],st[N][20];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
        if(ch=='-') 
            f=-1;
        ch=getchar();
    }
	while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
	return x*f;
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        arr[i]=read();
    lg2[1]=0;
    for(int i=2;i<=N;i++)
        lg2[i]=lg2[i>>1]+1;
    for(int i=1;i<=n;i++)
        st[i][0]=arr[i];
    for(int k=1;k<=18;k++){
        for(int i=1;i<=n;i++)
            st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
    }
    while(m--){
        int l=read(),r=read();
        int lg=lg2[r-l+1];
        cout<<max(st[l][lg],st[r-(1<<lg)+1][lg])<<endl;
    }
    return 0;
}