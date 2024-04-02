// WRONG ANSWER

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
	 int f=-1;
	 for(int i=0;i<n;i++){
	   int a;
	   cin>>a;
	   if(a<0 && f==-1)f=i;
	   arr.push_back(a);
	   
	 }
	 int t=f+1;
	 int total = (n*(n+1))/2;
	 int a1=t;
	 int cnt=1;
	 int l=f;
	 int prev=0;
	for(int i=f+1;i<n;i++){
	  if(arr[i]<0)cnt++;
	 
	  if(arr[i]<0 && cnt%2==1)t=prev+(i-l);
	  if(arr[i]<0 && cnt%2==0){
	    prev+=t;
	    t=i-l;
	    
	  }
	   if(arr[i]<0)l=i;
	  a1+=t;
	}
	//a1+=t;
	 cout<<a1<<" "<<total-a1<<endl;

}
return 0;
}