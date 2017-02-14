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
		int l, r;
		for (int i = 0; i < N; i++) {
			cin >> V[i];
			if (V[i] == 1) l = i;
		}
		r = l+1;
		l--;
		int _min = 2, _max = N;
		bool ans = true;
		while (l >= 0 || r < N) {
			if (l >= 0) {
				if (V[l] == _min) {
					_min++;
					l--;
					continue;
				} else if (V[l] == _max) {
					_max--;
					l--;
					continue;
				}
			}
			if (r < N) {
				if (V[r] == _min) {
					_min++;
					r++;
					continue;
				} else if (V[r] == _max) {
					_max--;
					r++;
					continue;
				}
			}
			ans = false;
			break;
		}
		res[t] = (ans)?1:0;
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << ((res[i]==1)?"yes":"no") << endl;
	return 0;
}