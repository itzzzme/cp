// Created at: 2025-07-20 20:33:01

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


// O(N^2) solution
void dfs(int i, vvti &adj, vti &vis, int &cnt)
{
    vis[i] = 1;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            cnt++;
            dfs(j, adj, vis, cnt);
        }
    }
}

// O(N) solution
void dfs(int i, vvti &adj, vti &subtree_size)
{
    for (auto j : adj[i])
    {
        dfs(j, adj, subtree_size);
        subtree_size[i] += 1 + subtree_size[j];
    }
}

void solve()
{
    int n;
    cin >> n;
    vti v(n + 1);
    v[0] = -1;
    v[1] = 0;
    FOR(i, 2, n + 1, 1)
    cin >> v[i];
    vvti adj(n + 1);
    FOR(i, 2, n + 1, 1)
    adj[v[i]].pb(i);
    vti subtree_size(n + 1, 0);
    dfs(1, adj, subtree_size);

    FOR(i, 1, n + 1, 1)
    cout << subtree_size[i] << ' ';
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