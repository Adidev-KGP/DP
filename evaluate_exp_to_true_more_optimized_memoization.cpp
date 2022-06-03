#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;

int solve(string s,int i,int j,bool isTrue){
    if(i>j)return false;
    if(i==j){
        if(isTrue==true) return s[i]=='T';
        else return s[i]=='F';
    }
    
    string temp = to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
    
    if(mp.find(temp)!=mp.end())return mp[temp];
    
    
    int ans = 0;
     for(int k = i+1; k<=j-1; k=k+2)
        {
            int leftTrue, leftFalse, rightTrue, rightFalse;
            
            string leftTruekey = to_string(i);
            leftTruekey.push_back(' '); 
            leftTruekey.append(to_string(k-1)); 
            leftTruekey.push_back(' '); 
            leftTruekey.append(to_string(true));
            
            string leftFalsekey = to_string(i);
            leftFalsekey.push_back(' '); 
            leftFalsekey.append(to_string(k-1)); 
            leftFalsekey.push_back(' '); 
            leftFalsekey.append(to_string(false));
            
            string rightTruekey = to_string(k+1); 
            rightTruekey.push_back(' '); 
            rightTruekey.append(to_string(j)); 
            rightTruekey.push_back(' '); 
            rightTruekey.append(to_string(true));
            
            string rightFalsekey = to_string(k+1); 
            rightFalsekey.push_back(' '); 
            rightFalsekey.append(to_string(j)); 
            rightFalsekey.push_back(' ');
            rightFalsekey.append(to_string(false));
            
            if(mp.find(leftTruekey) != mp.end()) {
                leftTrue = mp[leftTruekey];
            }
            else {
                leftTrue = solve(s,i,k-1,true);
            }
            
            if(mp.find(leftFalsekey) != mp.end()) {
                leftFalse = mp[leftFalsekey];
            }
            else {
                leftFalse = solve(s,i,k-1,false);
            }
            
            if(mp.find(rightTruekey) != mp.end()) {
                rightTrue = mp[rightTruekey];
            }
            else {
                rightTrue = solve(s,k+1,j,true);
            }
            
            if(mp.find(rightFalsekey) != mp.end()) {
                rightFalse = mp[rightFalsekey];
            }
            else {
                rightFalse = solve(s,k+1,j,false);
            }
        
       if(s[k] == '&') 
            {
                if(isTrue) {
                    ans = ans + leftTrue*rightTrue; 
                }
                else {
                    ans = ans + leftFalse*rightTrue + leftTrue*rightFalse + leftFalse*rightFalse;  
                }
            }
            else if(s[k] == '|') 
            {
                if(isTrue) {
                    ans = ans + leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue;
                }
                else {
                    ans = ans + leftFalse*rightFalse;  
                }
            }
            else // S[k] == "^" 
            {
                if(isTrue) {
                    ans = ans + leftFalse*rightTrue + leftTrue*rightFalse; 
                }
                else {
                    ans = ans + leftTrue*rightTrue + leftFalse*rightFalse;  
                }
            }
            
        
        
    }return mp[temp]=ans;
    
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    mp.clear();
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    string s;cin>>s;
    cout<<solve(s,0,s.length()-1,true);
}
