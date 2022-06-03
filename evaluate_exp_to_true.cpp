#include<bits/stdc++.h>
using namespace std;

int solve(string s,int i,int j,bool isTrue){
    if(i>j)return false;
    if(i==j){
        if(isTrue==true) return s[i]=='T';
        else return s[i]=='F';
    }
    int ans = 0;
    for(int k=i+1;k<=j-1;k+=2){
        int lt = solve(s,i,k-1,true);
        int lf = solve(s,i,k-1,false);
        int rt = solve(s,k+1,j,true);
        int rf = solve(s,k+1,j,false);
        
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
        
    }return ans;
    
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    string s;cin>>s;
    cout<<solve(s,0,s.length()-1,true);
}
