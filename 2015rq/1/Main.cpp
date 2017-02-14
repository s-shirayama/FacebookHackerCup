#include <bits/stdc++.h>
using namespace std;

const int MAXT = 100;
const int MAXN = 1e5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::ifstream in("input.txt");
	std::cin.rdbuf(in.rdbuf());

	int T, N;
	pair<int, int> res[MAXT];
	cin >> T;
	for (int t = 0; t < T; t++) {
		// PREPARE
		cin >> N;
		if (N == 0) {
			res[t] = make_pair(0, 0);
			continue;
		}
		vector<int> v;
		for (int i = 1; i <= N; i = i * 10) {
			int d = (N/i) % 10;
			v.push_back(d);
		}
		reverse(v.begin(), v.end());
		int _min = 0, _max = 0, idx, j;

		// MAX
		for (j = 0; j < v.size() - 1; j++) {
			idx = j;
			for (int i = j + 1; i < v.size(); i++) {
				if (v[j] < v[i] && v[idx] <= v[i]) {
					idx = i;
				}
			}
			if (idx > j || j == v.size() - 2) break;
		}
		swap(v[j], v[idx]);
		for (int i = 0; i < v.size(); i++) {
			_max = _max * 10 + v[i];
		}
		swap(v[j], v[idx]);

		// MIN
		for (j = 0; j < v.size() - 1; j++) {
			idx = j;
			for (int i = j + 1; i < v.size(); i++) {
				if (v[j] > v[i] && v[idx] >= v[i] && (v[i] > 0 || j > 0)) {
					idx = i;
				}
			}
			if (idx > j || j == v.size() - 2) break;
		}
		swap(v[j], v[idx]);
		for (int i = 0; i < v.size(); i++) {
			_min = _min * 10 + v[i];
		}
		swap(v[j], v[idx]);

		res[t] = make_pair(_min, _max);
	}
	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i].first << " " << res[i].second << endl;

}
