// dont know why but it is giving wrong answer

#include <bits/stdc++.h>
//#define int long long
using namespace std;

int main() {

	   int n,m;
	   cin>>n>>m;
	   unordered_map<int,vector<int>>mp1;
	   unordered_map<int,vector<int>>mp2;
     for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
         int k;
         cin>>k;
         mp1[k].push_back(i);
         mp2[k].push_back(j);
         
       }
     }
     int ans=0,ans2=0;
     for(auto it=mp1.begin();it!=mp1.end();it++){
       int pre=0;
       sort(it->second.begin(),it->second.end());
       vector<int>temp(it->second.size());
       temp[0]=it->second[0];
       for(int i=1;i<(it->second).size();i++){
         //(it->second)[i]=(it->second)[i]+(it->second)[i-1];
         temp[i]=temp[i-1]+(it->second)[i];
       }
       for(int i=0;i<(it->second).size();i++){
         ans+=(it->second)[i]*(i)-temp[i-1]+temp[it->second.size()-1]-temp[i]-(it->second.size()-1-i)*(it->second[i]);
       }
     }
     for(auto it=mp2.begin();it!=mp2.end();it++){
       int pre=0;
       vector<int>temp(it->second.size());
       
       sort(it->second.begin(),it->second.end());
        temp[0]=it->second[0];
       for(int i=1;i<(it->second).size();i++){
         //(it->second)[i]=(it->second)[i]+(it->second)[i-1];
         temp[i]=temp[i-1]+(it->second)[i];
       }
       for(int i=0;i<(it->second).size();i++){
         ans2+=(it->second)[i]*(i)-temp[i-1]+temp[it->second.size()-1]-temp[i]-(it->second.size()-1-i)*(it->second[i]);
       }
     }
     cout<<(ans+ans2)/2<<endl;
	
	return 0;

}