#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXT = 50;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, N, res[MAXT], D[MAXN];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> D[i];
		for (int i = 0, cnt = 0, pre = 0; i < N || cnt != 4;) {
			if (pre == 0 || (i < N && D[i] - pre <= 10 && D[i] > pre)) {
				pre = D[i];
				cnt = (cnt%4)+1;
				i++;
			} else {
				pre += 10;
				cnt = (cnt%4)+1;
				res[t]++;
			}
			if (cnt == 4) pre = 0;
		}
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}
