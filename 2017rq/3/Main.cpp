#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXW = 401;
const int MAXT = 1000;

LD calc(int x, int y, int t) {
	if (t <= 0) return 1.0;
	LD dp[2][MAXW];
	int idx = 0;
	memset(dp[idx], 0, sizeof(dp[idx]));
	dp[idx][0] = 1;
	for (int i = 0; i < x; i++) {
		idx ^= 1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		for (int j = 0; j < MAXW; j++) if (dp[idx^1][j] > 0) {
			for (int k = 1; k <= y; k++) {
				dp[idx][j+k] += dp[idx^1][j] / (LD)y;
			}
		}
	}
	LD res = 0.0;
	for (int i = t; i < MAXW; i++) res += dp[idx][i];
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	int T, H, N;
	LD res[MAXT];
	string S;
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> H >> N;
		for (int i = 0; i < N; i++) {
			cin >> S;
			int X = 0, Y = 0, Z = 0;
			int j;
			for (j = 0; S[j] != 'd'; j++) {
				X = X * 10 + (S[j] - '0');
			}
			for (j++; j < S.length() && S[j] != '+' && S[j] != '-'; j++) {
				Y= Y * 10 + (S[j] - '0');
			}
			int h = H;
			if (j < S.length()) {
				int ope = j;
				for (j++; j < S.length(); j++) {
					Z = Z * 10 + (S[j] - '0');
				}
				if (S[ope] == '+') h -= Z;
				else h += Z;
			}
			res[t] = max(res[t], calc(X, Y, h));
		}
	}

	for (int i = 0; i < T; i++) cout << fixed << setprecision(6) << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}

/*
1
121 4
16d20+61 17d8+39 8d6+85 7d12+84
*/