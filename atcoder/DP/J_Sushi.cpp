// Created at: 2025-09-28 14:46:54

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
#define vvtf vector<vtf>
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
  die have equal probability for each plate
  so :
  At any state (x1, x2, x3) = (how many plates have 1, 2, 3 sushi left),

    I can compute the expected moves E[x1][x2][x3] with a recurrence:

    With probability x1/N, I pick a plate with 1 sushi -> it becomes empty (so state (x1-1, x2, x3)).

    With probability x2/N, I pick a plate with 2 sushi -> it becomes (x1+1, x2-1, x3).

    With probability x3/N, I pick a plate with 3 sushi -> it becomes (x1, x2+1, x3-1).

    With probability (N - (x1+x2+x3))/N, I pick an empty plate -> state doesn’t change.
*/

static double dp[307][307][307];

void solve()
{
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
            ++c1;
        else if (temp == 2)
            ++c2;
        else if (temp == 3)
            ++c3;
    }

    dp[0][0][0] = 0.0; // already zero but explicit for clarity

    // compute by increasing total s = i+j+k
    for (int s = 1; s <= n; ++s)
    {
        // iterate i and j in descending order so references like dp[i+1][j-1][k]
        // and dp[i][j+1][k-1] (same s) are already computed
        for (int i = s; i >= 0; --i)
        {
            for (int j = s - i; j >= 0; --j)
            {
                int k = s - i - j;
                if (k < 0)
                    continue;
                double e = n; // numerator starts with n (because of the +1 * n)
                if (i > 0)
                    e += i * dp[i - 1][j][k];
                if (j > 0)
                    e += j * dp[i + 1][j - 1][k];
                if (k > 0)
                    e += k * dp[i][j + 1][k - 1];
                dp[i][j][k] = e / (double)s;
            }
        }
    }

    cout << dp[c1][c2][c3] << nline;
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