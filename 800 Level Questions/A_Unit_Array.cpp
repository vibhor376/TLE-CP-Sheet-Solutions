#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastAF                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define vll vector<ll>
#define pll pair<ll, ll>
#define mapll map<ll, ll>
#define all(v) v.begin(), v.end()
#define mod (int)1e9 + 7
#define pi 3.1415926536
#define deci(x) setprecision(x)
#define rev greater<int>()
#define rev2 greater<pair<int, int>>()
#define revll greater<ll int>()
#define rev2ll greater<pair<ll int, ll int>>()
#define ff first
#define ss second
#define get_unique(v)                                 \
    {                                                 \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define endl "\n"
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vll divisors;
vll factors_prime;
bool check_square(ll int *);
void Divisors(ll int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divisors.pb(i);
            if (n / i != i && i > 1)
            {
                divisors.pb(n / i);
            }
        }
    }
}
void Sieve(ll int n, bool sieve[])
{
    memset(sieve, true, n + 1);
    sieve[0] = false;
    sieve[1] = false;
    for (ll int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (ll int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}
bool CheckPrime(ll int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (ll int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void PrimeFactors(ll int n)
{
    while (n % 2 == 0)
    {
        factors_prime.pb(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            factors_prime.pb(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        factors_prime.pb(n);
    }
}
ll int Power(ll int x, ll int y, ll int m)
{
    ll int res = 1;
    x = x % m;
    if (x == 0)
    {
        return 0;
    }
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}
ll int setBit(ll int x, int i)
{
    return (x | (1 << i));
}
ll int unsetBit(ll int x, int i)
{
    return (x & ~(1 << i));
}
char upperToLower(char x)
{
    return x | ' ';
}
char lowerToUpper(char x)
{
    return x & ('_');
}
int main()
{
    fastAF;
    ll int t;
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
        int ans = 0;
        for (int k = 0; k <= n; k++)
        {
            bool f = true;
            int sum = 0;
            int prod = 1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < 0 && f && k > 0)
                {
                    a[i] = 1;
                    f = false;
                }
                prod *= a[i];
                sum += a[i];
            }
            if (sum >= 0 && prod > 0)
            {
                ans = k;
                break;
            }
        }
        cout << ans << endl;
    }
}
bool check_square(ll int n)
{
    ll int x = sqrt(n);
    x *= x;
    if (x == n)
    {
        return true;
    }
    return false;
}