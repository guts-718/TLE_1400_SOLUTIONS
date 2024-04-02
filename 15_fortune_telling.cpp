// x and (x+3) have different parity if x is odd then (x+3) will also be odd
// both addition and XOR do not change parity -->{odd+odd}=odd
// its all about parity
// after all the operations on the array the parity will bw same regardless of whether we do + or XOR 
// O + O = E
// E + O = O
// O + E = O
// E + E = E

#include <bits/stdc++.h>
 
using namespace std;
#define lli long long int
 
int main()
{
  int T;
  cin>>T;
  while(T--) {
    lli n,x,y;
    cin>>n>>x>>y;
 
    lli sum = 0;
 
    for(lli i=0; i<n; i++) {
      lli t;
      cin>>t;
      sum += t;
      // sum^=t;
    }
 
    if((sum + x) % 2 == (y%2)) {
      cout<<"Alice"<<endl;
    } else {
      cout<<"Bob"<<endl;
    }
  }
  return 0;
}