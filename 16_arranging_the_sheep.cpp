 // GREEDILY BAS MIDDLE STAR PR LE AAENGE AUR YHI SOLUTION HOGA
 // SECOND SOLUTION --> WE CAN TRY FOR ALL POSSIBLE INDICES WHERE WE HAVE * .... WE NEED TO USE PREFIX AND SUFFIX ARRAY FOR PRECOMPUTATION
 
    #include <bits/stdc++.h>
    using namespace std;
    char v[1000003];
    int main()
    {
        ios_base::sync_with_stdio(false);
        int t,i,j;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            cin>>(v+1);
            int cnt=0;
            for(i=1;i<=n;++i)
                if(v[i]=='*')
                    ++cnt;
            cnt=(cnt+1)/2;
            int s=0;
            for(i=1;i<=n;++i)
                if(v[i]=='*')
                {
                    ++s;
                    if(s==cnt)
                        break;
                }
            cnt=0;
            long long rz=0;
            for(j=i;j>=1;--j)
            {
                if(v[j]=='.')
                    ++cnt;
                else
                    rz+=cnt;
            }
            cnt=0;
            for(j=i+1;j<=n;++j)
                if(v[j]=='.')
                    ++cnt;
                else
                    rz+=cnt;
            cout<<rz<<'\n';
        }
    }





    #include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
typedef std::vector<long long> vi;
#define F first
#define S second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(), a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
const ll INF = LLONG_MAX / 2;
const ll N = 2e5 + 1;
using namespace std;
void solve()
{
    ll n;
    std::cin >> n;
    char s[n + 1];
    ll pres[n + 1] = {0}, suf[n + 1] = {0};
    fr(i, 1, n + 1)
            cin >>
        s[i];
    ll co = 0;
    fr(i, 1, n + 1)
    {
        if (i == 1)
        {
            if (s[i] == '*')
            {
                co++;
                continue;
            }
        }
        else
        {
            if (s[i] == '*')
            {
                co++;
                pres[i] = pres[i - 1];
            }
            else
                pres[i] = pres[i - 1] + co;
        }
    }
    // fr(i, 1, n + 1)
    //         cout
    //     << pres[i] << " ";
    co = 0;
    rf(i, n, 1)
    {
        if (i == n)
        {
            if (s[i] == '*')
            {
                co++;
                continue;
            }
        }
        else
        {
            if (s[i] == '*')
            {
                co++;
                suf[i] = suf[i + 1];
            }
            else
                suf[i] = suf[i + 1] + co;
        }
    }
    ll ans = min(pres[n], suf[1]);
    fr(i, 1, n)
    {
        ans = min(ans, pres[i] + suf[i + 1]);
    }
    cout << ans << "\n";
}

int main()
{
    fast;
    ll t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}