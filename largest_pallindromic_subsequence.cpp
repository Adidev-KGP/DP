#include<bits/stdc++.h>
using namespace std;

void solve(){
    string y;cin>>y;
    int n;cin>>n;
    string x=y;
    reverse(y.begin(),y.end());
    int m=n;
    
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0)dp[i][j]=0;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    cout<<dp[n][m];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    solve();
}
