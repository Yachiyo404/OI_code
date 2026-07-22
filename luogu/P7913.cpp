#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#define mem(a,x) memset(a,x,sizeof(a))
#define gc() getchar()
using namespace std;
typedef long long ll;
ll read(){
    ll x=0,f=1;
    char ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=gc();
    }
    return x*f;
}
const int N=1e5+10;
int n,m1,m2;
int ans1[N],ans2[N];
pair<int,int> in[N],out[N];
priority_queue<int,vector<int>,greater<int>> avi;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> lea;
int main(){
    n=read(),m1=read(),m2=read();
    up(i,1,m1)
        in[i].first=read(),in[i].second=read();
    up(i,1,m2)
        out[i].first=read(),out[i].second=read();
    sort(in+1,in+m1+1);
    sort(out+1,out+m2+1);
    up(i,1,n)
        avi.push(i);
    up(i,1,m1){
        while(!lea.empty()&&in[i].first>=lea.top().first){
            avi.push(lea.top().second);
            lea.pop();
        }
        if(avi.empty())
            continue;
        int loc=avi.top();
        avi.pop();
        ans1[loc]++;
        lea.push({in[i].second,loc});
    }
    up(i,1,n)
        ans1[i]+=ans1[i-1];
    while(!avi.empty())
        avi.pop();
    while(!lea.empty())
        lea.pop();
    up(i,1,n)
        avi.push(i);
    up(i,1,m2){
        while(!lea.empty()&&out[i].first>=lea.top().first){
            avi.push(lea.top().second);
            lea.pop();
        }
        if(avi.empty())
            continue;
        int loc=avi.top();
        avi.pop();
        ans2[loc]++;
        lea.push({out[i].second,loc});
    }
    up(i,1,n)
        ans2[i]+=ans2[i-1];
    int Max=0;
    up(i,0,n)//需要考虑0的情况
        Max=max(Max,ans1[i]+ans2[n-i]);
    cout<<Max;
    return 0;
}