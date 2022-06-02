#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];

bool ispallindrome(string s,int i,int j){
    string s1="";string s2="";
    for(int x=i,y=j;x<=j,y>=i;x++,y--){
        s1+=s[x];
        s2+=s[y];
    }if(s1==s2)return true;
    else return false;
}


int mcm(string s,int i,int j){
    if(i>=j || ispallindrome(s,i,j))return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    //if(ispallindrome(s,i,j))return 0;
    
    int ans=INT_MAX;int tempans;
    
    for(int k=i;k<=j-1;k++){
        tempans=mcm(s,i,k)+mcm(s,k+1,j)+1;
        if(tempans<ans)ans=tempans;
    }return dp[i][j]=ans;
}

signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
   memset(dp,-1,sizeof(dp));
   string s;cin>>s;
   int n=s.length();
   cout<<mcm(s,0,n-1);
   
}
