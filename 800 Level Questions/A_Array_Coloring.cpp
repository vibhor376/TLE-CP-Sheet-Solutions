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
#define all(v) v.begin(), v.end()
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
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
vll divisors;
vll factors_prime;
vector<vll> powers;
vector<vll> hash_values;
vll primes = {1000992299, 1000000009};
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
ll bin_expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_inverse(ll a, ll b)
{
    return bin_expo(a, b - 2, b);
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mod_inverse(b, m), m) + m) % m;
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
void rollinHash(string s)
{
    int base = 31;
    int n = s.length();
    hash_values.clear();
    powers.clear();
    for (int i = 0; i < primes.size(); i++)
    {
        vll temp(n, 0);
        vll power(n, 0);
        power[0] = 1;
        for (int j = 1; j < n; j++)
        {
            power[j] = mod_mul(power[j - 1], base, primes[i]);
        }
        temp[0] = s[0] - 96;
        for (int j = 1; j < n; j++)
        {
            ll prod = mod_mul(s[j] - 96, power[j], primes[i]);
            temp[j] = mod_add(temp[j - 1], prod, primes[i]);
        }
        hash_values.pb(temp);
        powers.pb(power);
    }
}
vector<ll> substringHash(int l, int r)
{
    vector<ll> hash(primes.size());
    for (int i = 0; i < primes.size(); i++)
    {
        ll val1 = hash_values[i][r];
        ll val2 = l > 0 ? hash_values[i][l - 1] : 0LL;
        hash[i] = mod_mul(mod_sub(val1, val2, primes[i]), mod_inverse(powers[i][l], primes[i]), primes[i]);
    }
    return hash;
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
        int o = 0, e = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
                o++;
            else
                e++;
        }
        if (o % 2 == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
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