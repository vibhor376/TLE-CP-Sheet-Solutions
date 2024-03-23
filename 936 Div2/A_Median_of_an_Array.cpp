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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int med = n / 2;
        med--;
        if (n & 1)
        {
            med++;
        }
        int cnt = 0;
        for (int i = n - 1; i >= med; i--)
        {
            if (a[i] == a[med])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}