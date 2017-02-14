#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 1e7+1;
const int MAXT = 100;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;

	vector<int> v;
	v.resize(MAXN);
	for (int i = 2; i < MAXN; i++) v[i] = 0;
	for (int i = 2; i < MAXN; i++) {
		if (v[i] == 0) {
			v[i] = 1;
			for (int j = i*2; j < MAXN; j+=i) v[j]++;
		}
	}

	for (int t = 0; t < T; t++) {
		int A, B, K;
		cin >> A >> B >> K;
		for (int i = A; i <= B; i++) if (v[i] == K) res[t]++;
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}