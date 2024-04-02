// we create a n*32 sized array in order to store the bits --> then we do prefix bits...
// if no of 1 bits == the size of the range then this bit will be 1 in the result also

#include <iostream>
#include <vector>
using namespace std;

#define int long long
const char nl = '\n';

bool isPossible(int l, int r, int mid, vector<vector<int>> &pref)
{

    int curr = 0;

    for (int i = 0; i < 32; i++)
    {
        int ss = pref[mid][i];
        if (l != 0)
            ss -= pref[l - 1][i];
        if (ss == mid - l + 1)
            curr += (1LL << i);
    }

    return curr >= r;
}

int binarySearch(int l, int r, int arr[], int n, vector<vector<int>> &pref)
{

    int low = l;
    int high = n - 1;

    int ans = -1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if (isPossible(l, r, mid, pref))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans == -1 ? ans : ans + 1;
}

void inputArr(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    inputArr(n, arr);

    int q;
    cin >> q;

    vector<vector<int>> pref(n, vector<int>(32, 0));
    for (int i = 0; i < n; i++)
    {

        int v = arr[i];
        int p = 0;
        while (v > 0)
        {
            if (v % 2 != 0)
                pref[i][p] += 1;
            v /= 2;
            p++;
        }

        if (i != 0)
        {
            for (int j = 0; j < 32; j++)
                pref[i][j] += pref[i - 1][j];
        }
    }

    for (int i = 0; i < q; i++)
    {

        int l, r;
        cin >> l >> r;

        --l;

        int ind = binarySearch(l, r, arr, n, pref);

        cout << ind << " ";
    }

    cout << nl;
}

int32_t main()
{
    // file(); // Assuming this function handles file I/O, comment out if not needed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
