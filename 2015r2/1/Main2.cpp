#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 50000;
const int MAXT = 20;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;

	int N, V[MAXN];
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> V[i];

		bool ans;
		for (int i = 0; i < 2; i++) {
			ans = true;
			int l = 0, r = N-1, _min, _max;
			if (i == 0) {
				_min = V[l], _max = V[l];
				l++;
			} else {
				_min = V[r], _max = V[r];
				r--;
			}
			while (l <= r) {
				if (V[l] == _min-1) {
					l++;
					_min--;
				} else if (V[l] == _max+1) {
					l++;
					_max++;
				} else if (V[r] == _min-1) {
					r--;
					_min--;
				} else if (V[r] == _max+1) {
					r--;
					_max++;
				} else {
					ans = false;
					break;
				}
			}
			if (ans) break;
		}
		res[t] = (ans)?1:0;
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << ((res[i]==1)?"yes":"no") << endl;
	return 0;
}