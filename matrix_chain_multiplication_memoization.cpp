#include<bits/stdc++.h>
using namespace std;
int static dp[1002][1002];

int mcm(int arr[],int i,int j){
    if(i>=j)return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    
    int ans=INT_MAX;
    int tempans;
    int k;
    
    for(k=i;k<=j-1;k++){
        tempans=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
    
    if(tempans<ans)ans=tempans;
    }
    return dp[i][j]=ans;
    
}

signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
   memset(dp,-1,sizeof(dp));
   int n;cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   cout<<mcm(arr,1,n-1);
}
