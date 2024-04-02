#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        unordered_set<int> st;

        vector<int> arr;
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            mp[a]++;
        }
        int maxi = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            arr.push_back(it->second);
            maxi = max(maxi, it->second);
        }
        int ans = 0;
        int to_take = maxi + 1;
        sort(arr.begin(), arr.end(), greater<int>());
        for (int i = 0; i < arr.size(); i++)
        {
            int q = arr[i];
            if (to_take <= 0)
                break;
            if (q >= to_take)
            {
                ans += to_take;
                to_take--;
            }
            else if (q < to_take)
            {
                ans += q;
                to_take = max(q - 1, (long long)0);
            }
        }

        cout << ans << endl;
    }
    return 0;
}