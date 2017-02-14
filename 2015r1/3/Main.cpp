#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 10;
const int MAXT = 1000;
const int MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;

	int dp1[MAXN][MAXN];
	memset(dp1, 0, sizeof(dp1));
	dp1[1][0] = 1;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			if (i <= j) continue;
			dp1[i][j] = (((i>0)?dp1[i-1][j]:0) + ((j>0)?dp1[i][j-1]:0)) % MOD;
			cout << i << ":" << j << ":" << dp1[i][j] << endl;
		}
	}

	for (int t = 0; t < T; t++) {
		int N, M;
		scanf("%d-%d", &N, &M);
		cout << N << ":" << M << endl;
		res[t] = dp1[N][M];
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}