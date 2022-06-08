#include<bits/stdc++.h>
using namespace std;

int solve(int e, int f){
    if(f==0 || f==1)return f;
    if(e==1)return f;
    
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int temp = 1+max(solve(e-1,k-1),solve(e,f-k));
        
        mn=min(mn,temp);
    }return mn;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    int e,f;
    cin>>e>>f;
    cout<<solve(e,f);
}
