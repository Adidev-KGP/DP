#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];


int lcs(string x,string y,int n,int m){
    if(n==0 || m==0)return 0;
    
    if(dp[n][m]!=-1)return dp[n][m];
    
    if(x[n-1]==y[m-1])return dp[n][m]=1+lcs(x,y,n-1,m-1);
    else return dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    string x;cin>>x;
    string y;cin>>y;
    int n;cin>>n;
    int m;cin>>m;
    memset(dp,-1,sizeof(dp));
    cout<<lcs(x,y,n,m);
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
   
}
