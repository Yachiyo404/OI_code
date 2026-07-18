#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,k;
struct node{
    int id,data;
}a[N];
deque<node> dq;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].data;
        a[i].id=i;
    }
    dq.push_back(a[1]);
    for(int i=2;i<=n;i++){
        if(!dq.empty()&&a[i].data>dq.back().data)
            dq.push_back(a[i]);
        else{
            while(!dq.empty()&&dq.back().data>=a[i].data)
                dq.pop_back();
            dq.push_back(a[i]);
        }
        while(!dq.empty()&&dq.front().id<=i-k)
            dq.pop_front();
        if(i>=k)
            cout<<dq.front().data<<' ';
    }
    cout<<endl;
    dq.clear();
    dq.push_back(a[1]);
    for(int i=2;i<=n;i++){
    if(!dq.empty()&&a[i].data<dq.back().data)
            dq.push_back(a[i]);
        else{
            while(!dq.empty()&&dq.back().data<=a[i].data)
                dq.pop_back();
            dq.push_back(a[i]);
        }
        while(!dq.empty()&&dq.front().id<=i-k)
            dq.pop_front();
        if(i>=k)
            cout<<dq.front().data<<' ';
    }
    return 0;
}