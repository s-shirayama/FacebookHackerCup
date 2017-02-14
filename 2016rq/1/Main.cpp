#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

const int MAXN = 2000;
const int MAXT = 50;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());

	int T, N, X[MAXN], Y[MAXN], res[MAXT];
	vector<int> d[MAXN];
	cin >> T;
//T = 50;
	for (int a = 0; a < T; a++) {
		cin >> N;
//N = 1000;
		for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
//for (int i = 0; i < N; i++) X[i] = 10000 - i, Y[i] = -10000 + i;
		for (int i = 0; i < N; i++) {
			d[i].clear();
			for (int j = 0; j < N; j++) {
				if (i <= j) {
					d[i].push_back((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
				} else {
					d[i].push_back(d[j][i]);
				}
			}
		}

		res[a] = 0;
		for (int i = 0; i < N; i++) {
			sort(d[i].begin(), d[i].end());
			int pre = d[i][0], cnt = 1;
			for (int j = 1; j < N; j++) {
				if (d[i][j] == pre) {
					cnt++;
				} else if (cnt > 1) {
					res[a] += LL(cnt) * (cnt - 1) / 2;
					cnt = 1;
				}
				pre = d[i][j];
			}
			if (cnt > 1) res[a] += LL(cnt) * (cnt - 1) / 2;
		}
	}
	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}