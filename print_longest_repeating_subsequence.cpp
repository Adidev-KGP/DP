#include<bits/stdc++.h>
using namespace std;

void solve(){
    string x;cin>>x;
    string y=x;
    int n=x.length();
    int m=y.length();
    
    int dp[n+1][m+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0)dp[i][j]=0;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1] && i!=j)dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
  
    int i=n;
    int j=m;
    string s="";
    
    while(i>0 && j>0){
        if(x[i-1]==y[j-1] && i!=j){
            s+=x[i-1];
            i--;j--;
        }else{
            if(dp[i][j-1]>dp[i-1][j])j--;
            else i--;
        }
    }reverse(s.begin(),s.end());
    cout<<s;
  
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    solve();
}
