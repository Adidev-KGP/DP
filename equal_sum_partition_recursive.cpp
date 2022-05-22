#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int subsetsum(int arr[],int sum,int n){
    if(sum==0)return 1;
    else if(sum>0 && n==0)return 0;
    
    if(dp[n][sum]!=-1)return dp[n][sum];
    
    if(arr[n-1]<=sum){
        return dp[n][sum]=(subsetsum(arr,sum-arr[n-1],n-1)||subsetsum(arr,sum,n-1));
    }else return dp[n][sum]=subsetsum(arr,sum,n-1);
}

void solve(){
     int n;cin>>n;
     int sum=0;
     int arr[n];
     for(int i=0;i<n;i++){
         cin>>arr[i];
         sum+=arr[i];
     }
     if(sum%2==0)cout<<subsetsum(arr,sum/2,n);
     else cout<<0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    memset(dp,-1,sizeof(dp));
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    
    solve();
}
