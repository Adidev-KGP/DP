#include<bits/stdc++.h>
using namespace std;

void solve(){
     int n;cin>>n;
     int sum=0;
     int arr[n];
     for(int i=0;i<n;i++){
         cin>>arr[i];
         sum+=arr[i];
     }
     if(sum%2==0){
     sum/=2;
     int dp[n+1][sum+1];
     memset(dp,-1,sizeof(dp));
     for(int i=0;i<n+1;i++){
         for(int j=0;j<sum+1;j++){
             if(j==0)dp[i][j]=1;
             else if(j>0 && i==0)dp[i][j]=0;
         }
     }
     
     for(int i=1;i<n+1;i++){
         for(int j=1;j<sum+1;j++){
             if(arr[i-1]<=j)dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
             else dp[i][j]=dp[i-1][j];
         }
     }cout<<dp[n][sum];
     }else cout<<0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    //memset(dp,-1,sizeof(dp));
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    
    solve();
}
