#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002][2];

int solve(string s,int i,int j,bool isTrue){
    if(i>j)return false;
    if(i==j){
        if(isTrue==true) return s[i]=='T';
        else return s[i]=='F';
    }
    
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    
    int ans = 0;
    int lt,lf,rt,rf;
    for(int k=i+1;k<=j-1;k+=2){
        if(dp[i][k-1][true]!=-1)lt = dp[i][k-1][true];
        else{
            lt=solve(s,i,k-1,true);
            dp[i][k-1][true]=lt;
        }
        
        
        if(dp[i][k-1][false]!=-1)lf = dp[i][k-1][false];
        else{
            lf=solve(s,i,k-1,false);
            dp[i][k-1][false]=lf;
        }
        
        int rt = solve(s,k+1,j,true);
        if(dp[k+1][j][true]!=-1)rt = dp[k+1][j][true];
        else{
            rt=solve(s,k+1,j,true);
            dp[k+1][j][true]=rt;
        }
        
        int rf = solve(s,k+1,j,false);
        if(dp[k+1][j][false]!=-1)rf = dp[k+1][j][false];
        else{
            rf=solve(s,k+1,j,false);
            dp[k+1][j][false]=rf;
        }
        
        if(s[k]=='&'){
            if(isTrue)ans+= lt*rt;
            else ans+= lf*rt + lt*rf + lf*rf;
        }else if(s[k]=='|'){
            if(isTrue)ans+= lt*rf + lf*rt + lt*rt;
            else ans+= lf*rf;
        }else if(s[k]=='^'){
            if(isTrue)ans+= lf*rt + lt*rf;
            else ans+= lt*rt + lf*rf;
        }
        
    }return dp[i][j][isTrue]=ans;
    
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    memset(dp,-1,sizeof(dp));
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    string s;cin>>s;
    cout<<solve(s,0,s.length()-1,true);
}
