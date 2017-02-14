#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 3001;
const int MAXT = 100;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T;
	double res[MAXT];
	double dp[2][MAXN];
	double p[MAXN];
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, K;
		double P;
		cin >> N >> K >> P;

		// Calculate probabiliry : no less than K from i
		int idx = 0;
		memset(dp[idx], 0, sizeof(dp[idx]));
		memset(p, 0, sizeof(p));
		dp[idx][0] = 1.0;
		for (int i = 1; i <= N; i++) {
			idx ^= 1;
			memset(dp[idx], 0, sizeof(dp[idx]));
			for (int j = 0; j < i; j++) {
				if (dp[idx^1][j] > 0) {
					dp[idx][j+1] += dp[idx^1][j] * P;
					dp[idx][j] += dp[idx^1][j] * (1.0 - P);
				}
			}
			for (int j = 0; j < MAXN; j++) {
				if (j >= K) p[i] += dp[idx][j];
			}
		}

		// Caluculate maximum score
		double ans[MAXN];
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N-i; j++) {
				ans[i+j] = max(ans[i+j], ans[i] + p[j]);
			}
		}
		res[t] = ans[N];
	}

	for (int i = 0; i < T; i++) cout << fixed << setprecision(9) << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}