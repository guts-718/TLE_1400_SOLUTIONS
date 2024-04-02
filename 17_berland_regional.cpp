// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// int32_t main() {
//    int t;
//    cin>>t;
//    while(t--){
//      int n;
//      cin>>n;
//      vector<vector<int>>arr(2,vector<int>(n));
//      for(int i=0;i<2;i++){
//        for(int j=0;j<n;j++){
//          int a;
//          cin>>a;
//          arr[i][j]=a;
//        }
//      }
//      int sol=0;
//      unordered_map<int,vector<int>>mp;
//      for(int i=0;i<n;i++){
//        mp[arr[0][i]].push_back(arr[1][i]);
//      }
//      vector<int>ans(n+1);
//      for(auto it=mp.begin();it!=mp.end();it++){
//        int size=it->second.size();
//        sort(it->second.begin(),it->second.end(),greater<int>());
//        vector<int>suffix(size+1,0);
//        suffix[size-1]=it->second[size-1];
//        for(int i=size-2;i>=0;i--){
//          suffix[i]=suffix[i+1]+it->second[i];
//        }
//        int sum=suffix[0];
//        int sol=0;
//        for(int i=1;i<=n;i++){
//          int rem=size%i;
//          ans[i]+=(sum-suffix[size-rem]);
        
         
//        }
      
//      }
//      for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
//      cout<<endl;
     
     
//    }
   
//    return 0;

// }




#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int M = 1e9+7;
ll mod(ll x){
    return (x%M + M)%M;
}

ll mul(ll a, ll b){
    return mod((mod(a)*mod(b)));
}

void solve(){
    int n;
    cin>>n;
    map<int,vector<ll>>mp;
    vector<int>u(n),s(n);
    for(int i=0;i<n;i++){
        cin>>u[i];
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        mp[u[i]-1].push_back(s[i]);
    }
    vector<vector<ll>>az;
    for(auto i : mp){
        az.push_back(i.second);
        sort(az.back().begin(),az.back().end());
    }
    vector<ll>ans(n,0);
    vector<vector<ll>>z;
    for(auto i : az){
        vector<ll>other;
        for(int j=0;j<(int)i.size();j++){
            if(j==0) other.push_back(i[j]);
            else other.push_back(other.back() + i[j]);
        }
        z.push_back(other);
    }
    // for(auto i : z){
    //     for(int j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(auto i : z){
        for(int j=1;j<=(int)i.size();j++){
            int left=(int)i.size() % j;
            ll del=0;
            if(left>0) del=i[left-1];
            ans[j-1]+=(i.back() - del);
            // cout<<"in "<<(i.back() - del)<<"\n";
        }
    }
    for(auto i : ans) cout<<i<<" ";
    cout<<"\n";
}  
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            int t=1;
            cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}

 