#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;

const int MAXN = 100;
const int MAXT = 500;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, N, W[MAXN], res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> W[i];
		sort(W, W+N, greater<int>());
		int l = 0, r = N - 1;
		while (r >= l) {
			r -= 50 / W[l] - ((50%W[l]==0)?1:0);
			if (r < l++) break;
			res[t]++;
		}
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}