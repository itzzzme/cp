// Created at: 2025-08-15 19:31:29

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vti vector<int>
#define vvti vector<vti>
#define vtl vector<ll>
#define vvtl vector<vtl>
#define vtc vector<char>
#define vvtc vector<vtc>
#define vts vector<string>
#define vvts vector<vts>
#define vtb vector<bool>
#define vvtb vector<vtb>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pii>
#define vpl vector<pll>
#define pic pair<int, char>
#define pci pair<char, int>
#define pcc pair<char, char>
#define pss pair<string, string>
#define pq priority_queue
#define pb push_back
#define gcd __gcd
#define nline "\n"
#define pi acos(-1)
#define elif else if
#define pf printf
#define sf scanf
#define fi first
#define si second
#define bpop(x) __builtin_popcount(x)
#define len(x) x.length()
#define asc(v) sort(all(v))
#define all(v) v.begin(), v.end()
#define sall(v, a) accumulate(all(v), a)
#define rall(v) v.rbegin(), v.rend()
#define dsc(v) asc(v), reverse(all(v))
#define sum(v) accumulate(all(v), 0)
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define memc(a, c) memset(a, c, sizeof(a))
#define FOR(i, start, end, a) for (ll i = start; i < end; i += a)
#define FORN(i, start, end, a) for (ll i = start; i > end; i -= a)
#define remDup(c) c.erase(unique(all(c)), c.end());

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int d8x[] = {0, 1, 0, -1, -1, 1, -1, 1};
int d8y[] = {1, 0, -1, 0, -1, -1, 1, 1};
const long long INF = LLONG_MAX >> 1;
const long long MOD = 1e9 + 7;
const long double e = 1e-9;

//------------------------------------------------------------------------------
ll power(ll a, ll b)
{
    ll result = 1;
    for (; b; a *= a, b /= 2)
        result *= (b % 2) ? a : 1;
    return result;
}
int factorial(int a) { return tgamma(a + 1); }
//------------------------------------------------------------------------------

void solve()
{
    int n, tar;
    cin >> n >> tar;
    vti v(n);
    for (auto &x : v)
        cin >> x;

    vtl dp(tar + 1, 0);
    dp[0] = 1;

    // if order matters then outer loop is target sum , and inner loop is coins
    // if order does not matter then outer loop is coins, and inner loop is target sum
    // here order does not matter, so we iterate over coins first
    FOR(j, 1, tar + 1, 1)
    for (int i : v)
        if (j >= i)
            dp[j] = (dp[j] + dp[j - i]) % MOD;

    cout << dp[tar] << nline;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}