#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;cin>>n;
    int sum;cin>>sum;
    int coin[n];
    for(int i=0;i<n;i++)cin>>coin[i];
    
    int dp[n+1][sum+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)dp[i][j]=INT_MAX-1;
            else if(j==0)dp[i][j]=0;
        }
    }dp[0][0]=0;
    
    // for(int j=1;j<=sum;j++){
    //     if(j%coin[0]==0)dp[0][j]=j/coin[0];
    //     else if(j%coin[0]!=0)dp[0][j]=INT_MAX-1;
    // }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j)dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }cout<<dp[n][sum];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    solve();
}
