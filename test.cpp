// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

#define MAXN 300001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++) {
		// checking if i is prime
		if (spf[i] == i) {
			// marking SPF for all numbers divisible by i
			for (int j = i * i; j < MAXN; j += i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
// unordered_map<int,int> getFactorization(int x)
vector<int> getFactorization(int x)
{
    vector<int>ret;
	while (x != 1) {
		ret.push_back(spf[x]);
		//mp[spf[x]]++;
		x = x / spf[x];
	}
	return ret;
}

// driver program for above function
int main(int argc, char const* argv[])
{
	// precalculating Smallest Prime Factor
	sieve();
    int t;
    cin>>t;
    while(t--){
    int l,r;
    cin>>l>>r;
    long long ans=0;
    for(int i=l;i<=r;i++){
	// calling getFactorization function
	//unordered_map<int,int> p = getFactorization(i);
	vector<int>p=getFactorization(i);
	ans+=p.back();
	
	
}

cout<<ans<<endl;
    }
	return 0;
}
