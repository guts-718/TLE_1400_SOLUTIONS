#include <bits/stdc++.h>
#define int long long
using namespace std;

int helper(int ind,vector<int>&a,vector<int>&b,int f,vector<vector<int>>&dp){
  if(ind>=a.size())return 0;
  if(dp[ind][f]!=-1)return dp[ind][f];
  int l=helper(ind+1,a,b,0,dp);
  int r=helper(ind+1,a,b,1,dp);
  if(f==0 || f==2)l=max(a[ind]+helper(ind+1,a,b,1,dp),l);
  if(f==1 || f==2)r=max(b[ind]+helper(ind+1,a,b,0,dp),r);
  return dp[ind][f]=max(l,r);
}
int32_t main() {
	int x;
  x=1;
	while(x--){
	 int n;
	 cin>>n;
	 vector<int>a1,b1;
	
	 for(int i=0;i<n;i++){
	   int a;
	   cin>>a;
	   a1.push_back(a);
	   
	 }
	 	 for(int i=0;i<n;i++){
	   int a;
	   cin>>a;
	   b1.push_back(a);
	   
	 }
	 vector<vector<int>>dp(n,vector<int>(3,-1));
	 cout<<helper(0,a1,b1,2,dp)<<endl;
	

}
return 0;
}