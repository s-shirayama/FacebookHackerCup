#include <bits/stdc++.h>
using namespace std;

const int MAXT = 100;
const int MAXN = 301;
const int INF = 1e5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::ifstream in("input.txt");
	std::cin.rdbuf(in.rdbuf());

	int T, N, K, res[MAXT], len[MAXN];
	string S[MAXN];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) cin >> S[i];
		sort(S, S+N);
		int dp[MAXN][MAXN];
		for (int i = 0; i < N; i++) {
			fill(dp[i], dp[i] + K + 1, INF);
			dp[i][1] = S[i].size() + 1;
			for (int j = 0; j < i; j++) {
				int l = 0;
				while (l < S[i].size() && l < S[j].size() && S[i][l] == S[j][l]) l++;
				for (int k = 1; k < K; k++) {
					dp[i][k+1] = min(dp[i][k+1], (int)(dp[j][k] + S[i].size() + S[j].size() - 2 * l + 1));
				}
			}
		}
		res[t] = INF;
		for (int i = 0; i < N; i++) {
			res[t] = min(res[t], (int)(dp[i][K] + S[i].size()));
		}
	}
	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;

	return 0;
}

/*
1
5 3
a
hair
box
awesome
hail

フットボールに対する姿勢を教えていただきありがとうございました。今の強いWARRIORSがあるのは細田さんのおかげだと思っています。お疲れ様でした。#4RB白山

現役時代に叱咤激励頂きありがとうございました。長い間お疲れ様でした。#4RB白山
*/
