#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1e5+10;
int bit[2][N];
inline int lowbit(int x){
    return x&-x;
}
void add(int a,int pos){
	while(a<=n){
		bit[pos][a]++;
		a+=lowbit(a);
	}
}
int sum(int a,int pos){
	int sum=0;
	while(a){
		sum+=bit[pos][a];
		a-=lowbit(a);
	}
	return sum;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	while(m--){
		int op,l,r;
		scanf("%lld%lld%lld",&op,&l,&r);
		if(op==1){
			add(l,0);
            add(r,1);
		}
        else{
			int rans=sum(r,0)-sum(l-1,1);
 			printf("%lld\n",rans);
		}
	}
	return 0;
} 