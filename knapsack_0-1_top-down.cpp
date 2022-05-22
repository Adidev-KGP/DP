#include<bits/stdc++.h>
using namespace std;

void solve(){
   int n;cin>>n;
   int w;cin>>w;
   int wt[n];int val[n];
   for(int i=0;i<n;i++)cin>>wt[i];
   for(int i=0;i<n;i++)cin>>val[i];
   int dp[n+1][w+1];
   memset(dp, -1, sizeof(dp));
   for(int i=0;i<n+1;i++){
       for(int j=0;j<w+1;j++){
           if(i==0 || j==0)dp[i][j]=0;
       }
   }


for(int i=1;i<n+1;i++){
    for(int j=1;j<w+1;j++){
        if(wt[i-1]<=j) dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
        else dp[i][j]=dp[i-1][j];
}
}cout<<dp[n][w];
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    
    solve();
}
