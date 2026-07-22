#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
const int N=1e5+10;
int m,q,x;
int res[N];
string str;
inline int get(int s,int &x){
    x=0;
    while(isdigit(str[s])){
        x=x*10+str[s]-'0';
        s++;
    }
    return s;
}
inline int count(int s,int l,int r){
    if(isdigit(str[s])){
        int tmp;
        int ret=get(s,tmp);
        up(i,l,r)
            res[i]=tmp;
        return ret;
    }
    int sep,stt=get(s+2,sep);
    if(str[s+1]=='>'){
        int neg=count(stt+1,sep+1,r);
        return count(neg+1,l,sep);
    }
    else{
        int neg=count(stt+1,l,sep-1);
        return count(neg+1,sep,r);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>m>>q>>str;
    count(0,1,m+1);
    while(q--){
        cin>>x;
        cout<<res[min(x,m+1)]<<endl;
    }
    return 0;
}