// ans = n + (n/2) + (n/8) + (n/16) +.....
//       last bit + last second bit + .....

#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	int x;
  cin>>x;
	while(x--){
	 int n;
	 cin>>n;
	 int k=1;
	 int ans=0;
	 while(n>=k){
	   ans+=(n/k);
	   k*=2;
	 }
	 cout<<ans<<endl;

	

}
return 0;
}