#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 50;
const int MAXT = 50;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, R, X[MAXN], Y[MAXN];
		LL c[MAXN][MAXN];
		cin >> N >> R;
		for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				c[i][j] = 0;
				for (int k = 0; k < N; k++) {
					if (X[k] >= X[i] && X[k] <= X[i] + R && Y[k] >= Y[j] && Y[k] <= Y[j] + R) c[i][j] |= (1LL << k);
				}
			}
		}
		res[t] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {
						res[t] = max(res[t], __builtin_popcountll(c[i][j]|c[k][l]));
					}
				}
			}
		}
	}
	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}

/*
const int dx[4] = {-1, 1, 1, -1};
const int dy[4] = {1, 1, -1, -1};
const double EPS = 1e-6;

int N, R, X[MAXN], Y[MAXN];
bool used[MAXN];

int calc() {
	int cnt = 0;
	for (int i = 0; i < N; i++) if (!used[i]) {
		for (int d = 0; d < 4; d++) {
			int _cnt = 0;
			for (int j = 0; j < N; j++) if (!used[j]) {
				if (X[j] >= min(X[i], X[i] + R * dx[d]) && X[j] <= max(X[i], X[i] + R * dx[d]) &&
					Y[j] >= min(Y[i], Y[i] + R * dy[d]) && Y[j] <= max(Y[i], Y[i] + R * dy[d])) _cnt++;
			}
			if (_cnt > cnt) {
				cnt = _cnt;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> R;
		for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int d = 0; d < 4; d++) {
				int _cnt = 0;
				//
				memset(used, 0, sizeof(used));
				for (int j = 0; j < N; j++) {
					if (X[j] >= min(X[i], X[i] + R * dx[d]) && X[j] <= max(X[i], X[i] + R * dx[d]) &&
						Y[j] >= min(Y[i], Y[i] + R * dy[d]) && Y[j] <= max(Y[i], Y[i] + R * dy[d])) _cnt++, used[j] = true;
				}
				_cnt += calc();
				if (_cnt > cnt) cnt = _cnt;
			}
		}
		res[t] = cnt;
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}

*/