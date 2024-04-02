// think about graph (x,y) co-rdinates and visuallise both the map taken has to be mutually exclusive so directly subtract and +2 as we have subtracted the current node in graph 2 times



#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	int x;
  cin>>x;
	while(x--){
	 int a,b,k;
	 cin>>a>>b>>k;
	 unordered_map<int,int>m1;
	 unordered_map<int,int>m2;
	 vector<vector<int>>arr(k,vector<int>(2));
	 for(int i=0;i<k;i++){
	  int a;
	  cin>>a;
	  arr[i][0]=a;
	  m1[a]++;
	   
	 }
 	 for(int i=0;i<k;i++){
	  int a;
	  cin>>a;
	  arr[i][1]=a;
	   m2[a]++;
	 }
	  int sol=0;
	  for(int i=0;i<k;i++){
	    int ans=k-m1[arr[i][0]]-m2[arr[i][1]]-1+2;
	    sol+=ans;
	  }
	  cout<<sol/2<<endl;
	  
	}
	return 0;

}