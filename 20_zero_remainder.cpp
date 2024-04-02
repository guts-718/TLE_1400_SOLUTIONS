#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{

    int n;
    int k, x;
    cin >> n >> k;
    map<int, int> mp;
    while (n--)
    {
        cin >> x;
        x %= k;
        if (x)
            mp[k - x]++;
    }
    map<int, int>::iterator it;
    int mx = 0;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        int x = (it->second - 1) * k + it->first;
        mx = max(mx, x);
    }
    if (mx)
    {
        mx++;
    }
    cout << mx << "\n";

    return;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	int x;
  cin>>x;
	while(x--){
	   int n,k;
	   cin>>n>>k;
	   vector<int>arr;
	   unordered_multiset<int>s1,s2;
	   for(int i=0;i<n;i++){
	     int x;
	     cin>>x;
	     int p=((k-x%k)%k);
	     if(p!=0)arr.push_back((k-x%k)%k);
	     //s1.insert((k-x%k)%k);
	     // s2.insert((k-x%k)%k);
	     
	     
	   }
	   sort(arr.begin(),arr.end());
	   int ans=0;
	   int t=0;
	   while(arr.size()!=0){
	   vector<int>v;
	   for(auto x:arr){
      if(x>t){
	       ans+=(x-t);
	       t=x+1;
	     }
	     //else if(t==x){
	     //  t=x+1;
	       
	     //}
	     else{
	       v.push_back(k+x);
	     }
	   }
	   arr=v;
	   
	}
	cout<<ans<<endl;
	

}
return 0;
}*/

