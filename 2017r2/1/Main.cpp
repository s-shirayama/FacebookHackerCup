#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 8*1e5;
const int MAXT = 1e4;

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
		int s = min(N, M), l = max(N, M);
		int ans = 0, ans2 = 0;
		if (l < 2 * K + 3) ans = -1;
		if (s < K + 1) ans = -1;
		if (ans == 0) for (; ans * K < s; ans++);
		if (s < 2 * K + 2) ans2 = -1;
		if (l < 2 * K + 3) ans2 = -1;
		if (ans2 == 0) {
			if (K == 1) ans2 = 5;
			else ans2 = 4;
		}

		if (ans == -1 && ans2 == -1) res[t] = -1;
		else if (ans == -1) res[t] = ans2;
		else if (ans2 == -1) res[t] = ans;
		else res[t] = min(ans, ans2);
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}