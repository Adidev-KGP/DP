#include<bits/stdc++.h>
using namespace std;

int subsetsum(int arr[],int sum,int n){
    if(sum==0)return 1;
    else if(sum>0 && n==0)return 0;
    
    if(arr[n-1]<=sum){
        return(subsetsum(arr,sum-arr[n-1],n-1)||subsetsum(arr,sum,n-1));
    }else return subsetsum(arr,sum,n-1);
}

void solve(){
     int n;cin>>n;
     int sum;cin>>sum;
     int arr[n];
     for(int i=0;i<n;i++)cin>>arr[i];
     cout<<subsetsum(arr,sum,n);
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    
    solve();
}
