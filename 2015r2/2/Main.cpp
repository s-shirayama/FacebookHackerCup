#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 21;
const int MAXT = 20;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T;
	LD res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	LD p[MAXN][MAXN];
	LD P;
	for (int t = 0; t < T; t++) {
		cin >> P;
		memset(p, 0, sizeof(p));
		p[0][0] = 1.0;
		for (int i = 1; i < MAXN; i++) {
			for (int j = 0; j < MAXN-1; j++) {
				if (p[i-1][j] > 0) {
					p[i][j] += p[i-1][j] * (1.0 - P);
					p[i][j+1] += p[i-1][j] * P;
				}
			}
		}
		LD dp[2][MAXN], ans = 0.0;
		int idx = 0;
		memset(dp[idx], 0, sizeof(dp[idx]));
		dp[idx][0] = 1.0;
		for (int i = 1; i <= 1e4; i++) {
			idx ^= 1;
			memset(dp[idx], 0, sizeof(dp[idx]));
			for (int j = 0; j < MAXN-1; j++) {
				if (dp[idx^1][j] > 0) {
					for (int k = 0; k < MAXN-j; k++) {
						dp[idx][j+k] += dp[idx^1][j] * p[MAXN-j-1][k];
					}
				}
			}
			ans += dp[idx][MAXN-1] * i;
		}
		res[t] = ans;
	}

	for (int i = 0; i < T; i++) cout << fixed << setprecision(5) << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}