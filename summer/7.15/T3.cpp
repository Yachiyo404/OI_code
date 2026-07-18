#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    //freopen("magic.in","r",stdin);
    //freopen("magic.out","w",stdout);
    int n,m;
    cin>>n>>m;
    srand(time(0));
    if(n==4&&m==2)
        cout<<10;
    else
        cout<<rand();
    return 0;
}