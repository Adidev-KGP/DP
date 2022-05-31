#include<bits/stdc++.h>
using namespace std;
int len = 0;


int lcs(string x,string y,int n,int m,int count){
    if(n==0 || m==0 )return count;
    
    if(x[n-1]==y[m-1])count=lcs(x,y,n-1,m-1,count+1);
    
    count=max(count,max(lcs(x,y,n-1,m,0),lcs(x,y,n,m-1,0)));
    return count;
    
}

void solve(){
    string y;cin>>y;
    string x=y;
    int n;cin>>n;
    int m=n;
    reverse(y.begin(),y.end());
    cout<<lcs(x,y,n,m,0);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    solve();
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
   
}
