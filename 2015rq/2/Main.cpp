#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int MAXT = 20;
int P[MAXN], C[MAXN], F[MAXN];
int N, GP, GC, GF;

bool func(int idx, int p, int c, int f) {
	if (p == GP && c == GC && f == GF) return true;
	if (N == idx || p > GP || c > GC || f > GF) return false;
	return func(idx+1, p, c, f) || func(idx+1, p + P[idx], c + C[idx], f + F[idx]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::ifstream in("input.txt");
	std::cin.rdbuf(in.rdbuf());
	int T;
	bool res[MAXT];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> GP >> GC >> GF;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> P[i] >> C[i] >> F[i];
		res[t] = func(0, 0, 0, 0);
	}
	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << (res[i]?"yes":"no") << endl;
	return 0;
}