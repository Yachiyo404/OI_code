#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    vector<char> m,key;
    char ch=getchar();
    ll size;
    while(ch!='\n'){
        key.push_back(ch);
        ch=getchar();
    }
    ch=getchar();
    while(ch!='\n'){
        m.push_back(ch);
        ch=getchar();
    }
    ll i=0;
    while(key.size()<m.size())
        key.push_back(key[i++]);
    size=m.size();
    for(ll i=0;i<size;i++){
        ll a,b;
        if('a'<=key[i]&&key[i]<='z')
            a=key[i]-'a';
        else
            a=key[i]-'A';
        if('a'<=m[i]&&m[i]<='z')
            b='a'-1;
        else
            b='A'-1;
        ll c=m[i]-b-a;
        if(c<=0)
            c+=26;
        c+=b;
        m[i]=c;
    }
    size=m.size();
    for(ll i=0;i<size;i++)
        cout<<m[i];
    return 0;
}