#include<bits/stdc++.h>
using namespace std;

int dp[102][1002];

void initialize(){
 for(int i=0;i<102;i++){
    for(int j=0;j<1002;j++)dp[i][j]=-1;
  }
}

int knapsack(int wt[],int val[],int w,int n){
    if(n==0 || w==0)return 0;
    
    if(dp[n][w]!=-1)return dp[n][w];
    
    if(wt[n-1]<=w){
        return dp[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }else return dp[n][w]=knapsack(wt,val,w,n-1);
}

void solve(){
    int n;cin>>n;
    int w;cin>>w;
    int wt[n];int val[n];
    for(int i=0;i<n;i++)cin>>wt[i];
    for(int i=0;i<n;i++)cin>>val[i];
    int x=knapsack(wt,val,w,n);
    cout<<x;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    initialize();
    solve();
}
