#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 302;
const int MAXT = 100;
const int INF = 1 << 30;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, A[MAXN], S[MAXN];
	LL res[MAXT], dp[2][MAXN];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;
		int idx = 0;
		fill(dp[idx], dp[idx] + MAXN, INF);
		dp[idx][0] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) cin >> A[j];
			sort(A, A+M);
			S[0] = 0;
			for (int j = 0; j < M; j++) S[j+1] = S[j] + A[j];
			idx ^= 1;
			fill(dp[idx], dp[idx] + MAXN, INF);
			for (int j = 0; j <= N; j++) {
				for (int k = 0; k <= min(M, j+1); k++) {
					if (dp[idx][j] > dp[idx^1][j+1-k] + S[k] + k * k) dp[idx][j] = dp[idx^1][j+1-k] + S[k] + k * k;
				}
			}
		}
		res[t] = dp[idx][0];
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}