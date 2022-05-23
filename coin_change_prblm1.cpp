#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int coin_change(int coin[],int sum,int n){
    dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++)
        if(i==0)dp[i][j]=0;
        else if(j==0)dp[i][j]=1;
    }dp[0][0]=1;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j)dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }return dp[n][sum];
}

void solve(){
   int n;cin>>n;
   int sum;cin>>sum;
   int coin[n];
   for(int i=0;i<n;i++)cin>>coin[i];
   cout<<coin_change(coin,sum,n);
}

signed main(){
    memset(dp,-1,sizeof(dp));
    solve();
}
