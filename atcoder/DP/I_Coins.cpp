// Created at: 2025-09-28 13:55:18

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vti vector<int>
#define vvti vector<vti>
#define vtl vector<ll>
#define vtd vector<double>
#define vtf vector<float>
#define vvtl vector<vtl>
#define vtc vector<char>
#define vvtc vector<vtc>
#define vts vector<string>
#define vvts vector<vts>
#define vvtd vector<vtd>
#define vvtf vector<vtd>
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
const long long INF = 1e9 + 5;
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

// observations :

/*
    so there are N coins
    I have to make sure no. of heads are in major
    then I have to calculate that for specific no. of heads what's the possibility

    let's say there will be two parameters

    n = no. of coins
    n_h = no. of heads

    dp[n][n_h] = possibility where no. of coins is n and no. of heads is n_h

    so minimum number of heads that must be in the n of coins is
        (n+1)/2 since n is always odd

    inside that there will be permutation, and I have to consider all permutations
    since permutations matter the coins order will be in inner loop
*/

void solve()
{
    int n;
    cin >> n;
    vtd p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    vvtd dp(n + 1, vtd(n + 1, 0.0));

    dp[0][0] = 1.0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            double takeHead = (j - 1 >= 0) ? dp[i - 1][j - 1] * p[i - 1] : 0.0;
            double takeTail = dp[i - 1][j] * (1.0 - p[i - 1]);
            dp[i][j] = takeHead + takeTail;
        }
    }

    int need = (n + 1) / 2;
    double ans = 0.0;
    for (int j = need; j <= n; ++j)
        ans += dp[n][j];

    // cout.setf(ios::fixed);
    // cout << setprecision(10) << ans << nline;
    // or to make precision we can do
    // printf("%.10lf\n", ans);
    // or we can use cout.precision(10) which is already defined inside main function
    cout<<ans;
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