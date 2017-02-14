#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

const int MAXN = 1e5;
const int MAXT = 40;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::ifstream in("input.txt");
	std::cin.rdbuf(in.rdbuf());

	int T, N, P, B[MAXN];
	LL sum[MAXN+2], res[MAXT];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> P;
		for (int i = 0; i < N; i++) cin >> B[i];
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < N; i++) sum[i+1] = sum[i] + B[i];
		for (int i = 0; i < N; i++) {
			LL *d = upper_bound(sum, sum+N+1, sum[i]+P);
			if (d - 1 > sum+i) res[t] += d - 1 - (sum + i);
		}
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}
