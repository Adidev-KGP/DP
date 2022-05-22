#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int dp[n+1][sum+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)dp[i][j]=0;
            else if(j==0)dp[i][j]=1;
    }
    }dp[0][0]=1;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j)dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<=sum/2;i++){
        if(dp[n][i])ans=min(ans,abs(sum-2*i));
    }
    cout<<ans;
}

signed main(){
    
    solve();
}
