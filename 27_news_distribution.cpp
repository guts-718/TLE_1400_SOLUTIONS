//rank of parent is giving the size of component

#include <bits/stdc++.h>
#define int long long
using namespace std;
class DisjointSet {
  public:
    vector<int>rank, parent;

    DisjointSet(int n) {
        // initiallisd with 1 as we want it to store the size of the component
        rank.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]+=rank[ulp_u];
        }
        else if (rank[ulp_v] <= rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]+=rank[ulp_v];
        }
        
    }
};
int32_t main() {
    int n,m;
    cin>>n>>m;
    
    DisjointSet ds(n);
    
    for(int i=0;i<m;i++){
      int k;
      cin>>k;
      vector<int>a1;
      while(k--){
        int o;
        cin>>o;
        // my dsu is 0 indexed but the question is having 1 indexed
        a1.push_back(o-1);
      }
      for(int i=1;i<a1.size();i++){
        int l=a1[i-1];
        int r=a1[i];
        ds.unionByRank(l, r);
        
      }
      a1.clear();
    }
    for(int i=0;i<n;i++){
       //rank of parent is giving the size of component
       int an=ds.findUPar(i);
       cout<<ds.rank[an]<<" ";
       
    }
    cout<<endl;
    
   return 0;

}