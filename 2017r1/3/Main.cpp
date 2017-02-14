#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 101;
const int MAXK = 5000;
const int MAXT = 100;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M, K;
		cin >> N >> M >> K;
		// Calculate distance
		int d[MAXN][MAXN];
		for (int i = 0; i < N; i++) {
			fill(d[i], d[i]+N, INF);
			d[i][i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int A, B, G;
			cin >> A >> B >> G;
			A--, B--;
//			d[A][B] = G, d[B][A] = G;
			d[A][B] = min(d[A][B], G), d[B][A] = min(d[B][A], G);
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		// Input family
		int S[MAXK], D[MAXK];
		S[0] = D[0] = 0;
		for (int i = 1; i <= K; i++) {
			cin >> S[i] >> D[i];
			S[i]--, D[i]--;
		}
		// Check validity
		bool chk = true;
		for (int i = 1; i <= K; i++) if (d[D[i-1]][S[i]] == INF || d[S[i]][D[i]] == INF) chk = false;
		if (!chk) {
			res[t] = -1;
			continue;
		}
		// DP
		int idx = 0;
		int dp[2][2];
		dp[idx][0] = 0, dp[idx][1] = INF;
		for (int i = 1; i <= K; i++) {
			idx ^= 1;
			int last = D[i-1];
			int from1 = S[i];
			int to1 = D[i];
			dp[idx][0] = min(dp[idx^1][1] + d[last][to1],
					         dp[idx^1][0] + d[last][from1] + d[from1][to1]);
			if (i < K) {
				int from2 = S[i+1];
				dp[idx][1] = min(dp[idx^1][1] + d[last][from2] + d[from2][to1],
   	                             dp[idx^1][0] + d[last][from1] + d[from1][from2] + d[from2][to1]);
			}
		}
		res[t] = dp[idx][0];
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}