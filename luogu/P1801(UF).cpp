#include<bits/stdc++.h>
#define ll long long 
#define mem(a,m) memset(a,m,sizeof(a))
using namespace std;

inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

int main(){


    return 0;
}