#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXM = 1e9;
const int MAXN = 2000;
const int MAXT = 100;
const int MOD = 1e9 + 7;

//LL NPN[MAXM];
vector<LL> NPN;

LL _pow(LL a, LL k) {
	LL res = 1;
	while (k) {
		// k%1 == 1
		if (k & 1) res = res * a % MOD;
		a = a * a % MOD;
		// k /= 2;
		k >>= 1;
	}
	return res;
}

LL nPn(int n) {
	if (NPN[n] > 0) return NPN[n];
	if (n == 0) return NPN[n] = 1;
	return NPN[n] = n * nPn(n-1) % MOD;
}

LL nCr(int n, int r) {
	// /= A  ->  *= A^M-2
	return nPn(n) * _pow(nPn(n-r) * nPn(r) % MOD, MOD - 2) % MOD;
}

int main() {
	NPN.resize(MAXM);
	NPN[0] = 1;
	for (int i = 1; i < MAXM; i++) NPN[i] = NPN[i-1] * i % MOD;

	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T;
	LL res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M, R[MAXN], S = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> R[i];
			S += 2 * R[i];
		}
		if (N == 1) {
			res[t] = M;
			continue;
		}
		LL _res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (i != j) {
				int y = M - 1 - S + R[i] + R[j];
				if (y >= 0) _res = (_res + ((nCr(N+y, N) * nPn(N-2)) % MOD)) % MOD;
			}
		}
		res[t] = _res;
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}