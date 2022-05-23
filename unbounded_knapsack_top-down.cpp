#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int ub_knapsack(int wt[],int val[],int w,int n){
    dp[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++)
        if(i==0 || j==0)dp[i][j]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j)dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }return dp[n][w];
}

void solve(){
   int n;cin>>n;
   int w;cin>>w;
   int wt[n];int val[n];
   for(int i=0;i<n;i++)cin>>wt[i];
   for(int i=0;i<n;i++)cin>>val[i];
   cout<<ub_knapsack(wt,val,w,n);
}

signed main(){
    memset(dp,-1,sizeof(dp));
    solve();
}
