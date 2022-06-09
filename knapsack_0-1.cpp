#include<bits/stdc++.h>
using namespace std;
int n;
int w;

int knapsack(int wt[], int val[],int w,int n){
    if(n==0 || w==0)return 0;
    
    if(wt[n-1]<=w){
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }else return knapsack(wt,val,w,n-1);
}

void solve(){
    cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cin>>w;
    
    cout<<knapsack(wt,val,w,n);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    solve();
}
