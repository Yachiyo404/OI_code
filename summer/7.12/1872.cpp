#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,d,ans=-1;
struct node{
    int x,h;
}drop[N];
bool check(int k){
    deque<node> dq;
    vector<node> mi,ma;
    dq.push_back(drop[1]);
    for(int i=2;i<=n;i++){
        if(!dq.empty()&&drop[i].h>dq.back().h)
            dq.push_back(drop[i]);
        else{
            while(!dq.empty()&&drop[i].h<=dq.back().h)
                dq.pop_back();
            dq.push_back(drop[i]);
        }
        while(!dq.empty()&&dq.front().x<drop[i].x-k)
            dq.pop_front();
        mi.push_back(dq.front());
    }
    dq.clear();
    dq.push_back(drop[1]);
    for(int i=2;i<=n;i++){
        if(!dq.empty()&&drop[i].h<dq.back().h)
            dq.push_back(drop[i]);
        else{
            while(!dq.empty()&&drop[i].h>=dq.back().h)
                dq.pop_back();
            dq.push_back(drop[i]);
        }
        while(!dq.empty()&&dq.front().x<drop[i].x-k)
            dq.pop_front();
        ma.push_back(dq.front());
    }
    for(int i=0;i<mi.size();i++){
        if(ma[i].h-mi[i].h>=d)
            return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>drop[i].x>>drop[i].h;
    sort(drop+1,drop+n+1,[](node a,node b){return a.x<b.x;});
    int l=0,r=1e6;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans;
    return 0;
}