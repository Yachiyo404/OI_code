#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    string str;
    cin>>str;
    int len=str.length();
    stack<char> sta;
    up(i,1,len){
        if(str[i]=='(')
            sta.push('(');
        else{
            if(sta.empty()){
                
            }
        }
    }
    
    return 0;
}