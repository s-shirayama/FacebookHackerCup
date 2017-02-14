#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;


#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "basket"


void solve()
{
    const LL inf64 = inf * 1000000;
    int T;
    scanf("%d", &T);
    for (int q = 0; q < T; q++)
    {
        cerr << q << endl;
        int n, m, K;
        scanf("%d %d %d", &n, &m, &K);

        vector <vector <LL> > d(n, vector <LL>(n, inf64));
        for (int i = 0; i < n; i++)
            d[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--; b--;
            d[a][b] = min(d[a][b], LL(c));
            d[b][a] = min(d[b][a], LL(c));
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                {
                    if (d[j][i] != inf64 && d[i][k] != inf64)
                        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                }

        vector<pair<int, int> > a(K + 1);
        a[0] = mp(0, 0);
        for (int i = 1; i <= K; i++)
        {
            scanf("%d %d", &a[i].X, &a[i].Y);
            a[i].X--; a[i].Y--;
        }
        vector<vector <LL> > dp(K + 1, vector <LL>(2, inf64));
        dp[0][0] = 0;
        bool isBad = false;
        for (int i = 0; i < K && !isBad; i++)
        {
            int last = a[i].Y;
            int from1 = a[i + 1].X;
            int to1 = a[i + 1].Y;

            dp[i + 1][0] = min( dp[i][0] + d[last][from1] + d[from1][to1],
                                dp[i][1] + d[last][to1]);
            if (i + 2 <= K)
            {
                int from2 = a[i + 2].X;
                dp[i + 1][1] = min( dp[i][0] + d[last][from1] + d[from1][from2] + d[from2][to1],
                                    dp[i][1] + d[last][from2] + d[from2][to1]);
            }

            if (dp[i + 1][0] >= inf64 && dp[i + 1][1] >= inf64)
                isBad = true;

            dp[i + 1][0] = min(dp[i + 1][0], inf64);
            dp[i + 1][1] = min(dp[i + 1][1], inf64);
        }

        cout << "Case #" << q + 1 << ": ";
        if (isBad)
            cout << -1 << endl;
        else
            cout << dp[K][0] << endl;
    }
}

int main()
{
    //START
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    //freopen("C:/Users/Vlad/Downloads/manic_moving.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    solve();
    //END
    return 0;
}
/*******************************************
*******************************************/

template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
    forn(i, v.size())
        is >> v[i];
    return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
    forn(i, v.size())
        os << v[i];
    return os;
}
#endif