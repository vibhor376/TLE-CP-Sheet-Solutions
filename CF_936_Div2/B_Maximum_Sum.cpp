#include <bits/stdc++.h>
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define pb push_back
#define rev greater<int>()
#define revll greater<ll int>()
#define unsigned long long ull;
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define f first
#define s second
#define endl "\n"
#define get_unique(v)                                 \
    {                                                 \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
using namespace std;
const ll mod = 1000000007;
bool is_square(ll int n)
{
    ll int x = sqrt(n);
    x *= x;
    if (x == n)
    {
        return true;
    }
    return false;
}
int main()
{
    IO int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll a[n];
        ll sum = 0, mx = 0, tot = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            tot += a[i];
            mx = max(mx, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        tot -= mx;
        int mod = 1e9 + 7;
        while (k--)
        {
            (mx += mx) %= mod;
        }
        (mx += tot) %= mod;
        cout << (mx + mod) % mod << endl;
    }
}