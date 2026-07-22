#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
using namespace std;
typedef long long ll;
ll n,m;
map<string,ll> stu;
int main(){
    cin>>n;
    string name;
    up(i,1,n){
        cin>>name;
        stu[name]=1;
    }
    cin>>m;
    while(m--){
        cin>>name;
        if(stu[name]==1){
            puts("OK");
            stu[name]++;
        }
        else if(stu[name]==2)
            puts("REPEAT");
        else
            puts("WRONG");
    }
    return 0;
}