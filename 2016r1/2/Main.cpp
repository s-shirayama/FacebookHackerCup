#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<LL, int> P;

const int MAXN = 1e5;
const int MAXT = 50;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, L, N, M, D, W[MAXN];
	LL res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		priority_queue<P, vector<P>, greater<P>> l, d;
		cin >> L >> N >> M >> D;
		for (int i = 0; i < N; i++) {
			cin >> W[i];
			l.push(make_pair(W[i], W[i]));
		}
		for (int i = 0; i < min(M, L); i++) d.push(make_pair(0, D));
		vector<LL> v;
		for (int i = 0; i < L; i++) {
			P p = l.top(); l.pop();
			v.push_back(p.first);
			l.push(make_pair(p.first + p.second, p.second));
		}
		for (int i = 0; i < v.size(); i++) {
			P p = d.top(); d.pop();
			res[t] = max(v[i], p.first) + p.second;
			d.push(make_pair(res[t], p.second));
		}
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}