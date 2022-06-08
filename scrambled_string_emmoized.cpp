#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool>mp;

bool solve(string a,string b){
    if(a.compare(b)==0)return true;
    
    if(a.length()<=1)return false;
    
    string key = a; key+=" "; key+=b;
    
    if(mp.find(key)!=mp.end())return mp[key];
    
    int n=a.length();
    
    bool flag = false;
    
    for(int i=1;i<=n-1;i++){
        if((solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true)
        ||
        (solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true)){
            flag = true; break;
        }
    }return mp[key]=flag;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    string a;cin>>a;
    string b;cin>>b;
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    if(a.length()!=b.length())cout<<"False";
    if(a=="" && a==b)cout<<"True";
    else cout<<solve(a,b);
}
