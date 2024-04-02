// we have to make k partition which must involve the first and the last broken part ... so for k such tapes we try to find (k-1) worst places which we would not combine


#include <bits/stdc++.h>
using namespace std;

// sorting the vector<vector<int>> in descending order
bool compare(vector<int>&a, vector<int>&b){
  return a[0]>b[0];
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>arr;
	for(int i=0;i<n;i++){
	  int x;
	  cin>>x;
	  arr.push_back(x);
	}
	vector<vector<int>>v;
    //storing the diff and the lower index...
	for(int i=1;i<n;i++){
	  v.push_back({arr[i]-arr[i-1],i-1});
	}
	sort(v.begin(),v.end(),compare);
    //unordered_Set will give wrong answer
	set<int>st;
    // picking (k-1) worst places to pick...
	int p=k-1;
	int i=0;
	while(p--){
	  st.insert(v[i][1]);
	  i++;
	}
	st.insert(n-1);
	int last=0;
	int ans=0;
	for(auto x:st){
	  ans+=arr[x]-arr[last]+1;
	  last=x+1;
	}
	cout<<ans<<endl;
	return 0;

}