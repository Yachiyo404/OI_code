#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x) 
#define I using
#define like namespace
#define yxy std
I like yxy;
typedef long long ll;
ll n;
struct memo{
    string name,type;
    ll l,r;
};
struct memb{
    string name,type_name;
    ll siz;
};
struct stru{
    string name;
    ll siz,head;//总体积 对齐体积
    vector<memb> member;
};
vector<memo> memory;
vector<stru> val;
bool flag;
inline void solve_op4(ll addr,string type,string name,string &ans){
    ll siz=val.size();
    up(i,0,siz-1){
        if(val[i].name==name){
            ans+=val[i].name;
            ans+='.';
            siz=val[i].member.size();
            up(i,0,siz-1){
                if(val[i].member[i].siz>=addr){
                    if(val[i].member[i].type_name=="byte"||val[i].member[i].type_name=="short"||val[i].member[i].type_name=="int"||val[i].member[i].type_name=="long"){
                        if(addr>val[i].member[i].siz)
                            ans="ERR";
                        else
                            ans+=val[i].member[i].type_name;
                        flag=1;
                        return;
                    }
                    else{
                        solve_op4(addr-val[i].member[i].siz,val[i].member[i].type_name,val[i].member[i].name,ans);
                        if(flag)
                            return;
                    }
                }
                    
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    while(n--){
        ll op,lst=-1;
        cin>>op;
        if(op==1){
            string s;
            ll k,Max=0,sum=0;
            cin>>s>>k;
            vector<memb> tmp;
            while(k--){
                string name,type;
                ll tp;
                cin>>type>>name;
                if(type=="byte")
                    tp=1;
                else if(type=="short")
                    tp=2;
                else if(type=="int")
                    tp=4;
                else if(type=="long")
                    tp=8;
                else{
                    ll siz=val.size();
                    up(i,0,siz-1){
                        if(val[i].name==type)
                            tp=val.size();
                    }
                }
                sum+=tp;
                Max=max(Max,tp);
                tmp.push_back({name,type,tp});
            }
            val.push_back({s,sum,Max*k,tmp});
        }
        else if(op==2){
            string in_type,in_name;
            cin>>in_type>>in_name;
            ll siz=val.size();
            up(i,0,siz-1){
                if(val[i].name==in_type){
                    lst++;
                    memory.push_back({in_name,in_type,lst,lst+val[i].head-1});
                }
            }
        }
        else if(op==3){
            ll ans=0;
            string s;
            vector<string> name;
            cin>>s;
            ll i=0,len=s.size(),siz;
            while(i<=len-1){
                string tmp;
                while(s[i]!='.'){
                    tmp.push_back(s[i]);
                    i++;
                }
                name.push_back(tmp);
                i++;
            }
            up(j,0,memory.size()-1){
                if(memory[j].name==name[0]){
                    ans=memory[j].l;
                    break;
                }
            }
            i=0;
            while(i<=name.size()-1){
                up(k,0,val.size()){
                    if(val[k].name==name[i]){
                        i++;
                        up(j,0,val[k].member.size()-1){
                            if(val[k].member[j].name!=name[i])
                                ans+=val[k].member[j].siz;
                            else{
                                
                            }
                        }
                    }
                }
            }

        }
        else{
            ll addr;
            string ans;
            flag=0;
            cin>>addr;
            ll siz=memory.size();
            up(i,0,siz-1){
                if(memory[i].l<=addr&&memory[i].r>=addr)
                    solve_op4(addr-memory[i].l,memory[i].type,memory[i].name,ans);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}