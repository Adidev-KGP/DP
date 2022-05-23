#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int ub_knapsack(int wt[],int val[],int w,int n){
    if(n==0 || w==0)return 0;
    if(dp[n][w]!=-1)return dp[n][w];
    
    if(wt[n-1]<=w)return dp[n][w]=max(val[n-1]+ub_knapsack(wt,val,w-wt[n-1],n),ub_knapsack(wt,val,w,n-1));
    else return dp[n][w]=ub_knapsack(wt,val,w,n-1);
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
