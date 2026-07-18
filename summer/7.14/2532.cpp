#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=7e4;
int W,n;
int t[20],w[20],maxt[N],sumw[N],f[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>W>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i]>>w[i];
    for(int s=0;s<=(1<<n)-1;s++){
        int tmp_t=INT_MIN,tmp_w=0;
        for(int i=1;i<=n;i++){
            if(s&(1<<(i-1))){
                tmp_t=max(tmp_t,t[i]);
                tmp_w+=w[i];
            }
        }
        maxt[s]=tmp_t;
        sumw[s]=tmp_w;
    }
    for(int s=0;s<=(1<<n)-1;s++)    
        f[s]=INT_MAX;
    f[0]=0;
    for(int s=0;s<=(1<<n)-1;s++){
        for(int t=s;t;t=(t-1)&s){
            if(sumw[t]<=W)
                f[s]=min(f[s],f[s-t]+maxt[t]);
        }
    }
    cout<<f[(1<<n)-1];
    return 0;
}