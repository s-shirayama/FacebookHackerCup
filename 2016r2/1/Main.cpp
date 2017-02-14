#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXT = 75;
const int MAXN = 1e5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, N, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	bool chk[MAXN];
	for (int t = 0; t < T; t++) {
		cin >> N;
		memset(chk, 0, sizeof(chk));
		string S1, S2;
		cin >> S1 >> S2;
		int idx = 0;
		bool same = true;
		for (int i = 0; i < S1.length(); i++) {
			if (i > 0 && S2[i] != S2[i-1]) {
				chk[idx++] = same;
				same = true;
			}
			if (S1[i] != S2[i]) same = false;
		}
		chk[idx++] = same;
		res[t] = (idx+1)/2;
		for (int i = idx/2; i < idx; i++) {
			if (!chk[i] || !chk[idx-i-1]) break;
			res[t]--;
		}
	}
	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}