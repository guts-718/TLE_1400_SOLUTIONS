// question seemed like dp... also had a dp tag(dp seemed like n^2 sol)..but constraint was of 2x10^5  so had to do it within (nlog n) / (n) 
// then saw --> (i - j == arr[i]-arr[j]) .... (arr[i]-i == arr[j]-j) so store this instead of arr[i] and then for same val of arr[i]-i find max 

#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	int x;
  x=1;
	while(x--){
	 int n;
	 cin>>n;
	 vector<int>arr;
	 unordered_map<int,vector<int>>mp;
	 for(int i=0;i<n;i++){
	   int a;
	   cin>>a;
	   mp[a-(i+1)].push_back(a);
	   
	 }
	 int maxi=-1;
	 for(auto it=mp.begin();it!=mp.end();it++){
	   int sum=0;
	   for(auto k:it->second){
	     sum+=k;
	   }
	   maxi=max(maxi,sum);
	 }
	 cout<<maxi<<endl;
	 

}
return 0;
}