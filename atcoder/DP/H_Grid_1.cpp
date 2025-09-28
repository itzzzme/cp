// Created at: 2025-09-28 13:32:35

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

int H, W;
vvti dp;

int solve_dp(int i, int j, vvtc &v)
{
    if (i > H - 1 or j > W - 1 or v[i][j] == '#')
        return 0;
    if (i == H - 1 and j == W - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = (solve_dp(i + 1, j, v) + solve_dp(i, j + 1, v)) % MOD;
}

void solve()
{
    cin >> H >> W;
    dp.resize(H + 1, vti(W + 1, 0));
    vvtc v(H, vtc(W));

    dp[0][1] = 1;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> v[i][j];

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (v[i - 1][j - 1] == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            else
                dp[i][j] = 0;
        }
    }
    cout << dp[H][W] << nline;
    // cout << solve_dp(0, 0, v);
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