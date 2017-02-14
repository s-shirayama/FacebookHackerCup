#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 4000;
const int MAXK = 101;
const int MAXT = 20;
const int INF = 1e9;

typedef struct TrieNode {
	TrieNode *c[26];
	int cnt;
	bool isLeaf;
} TN;

TN *getNode() {
	TN *d;
	d = (TN *)malloc(sizeof(TN));
	for (int i = 0; i < 26; i++) d->c[i] = NULL;
	d->cnt = 0;
	d->isLeaf = false;
	return d;
}

void insert(TN *root, string s) {
	TN *p = root;
	p->cnt++;
	for (int i = 0; i < s.length(); i++) {
		int idx = s[i] - 'a';
		if (!p->c[idx]) p->c[idx] = getNode();
		p = p->c[idx];
		p->cnt++;
	}
	p->isLeaf = true;
}

vector<int> solve(TN *tn, int depth) {
	vector<int> res(MAXK, INF);
	res[0] = 0;
	res[1] = depth;
	if (tn == NULL) return res;
	vector<vector<int>> v;
	for (int i = 0; i < 26; i++) if (tn->c[i] != NULL) {
		v.push_back(solve(tn->c[i], depth+1));
	}
	if (v.size() == 0) return res;

	// DP
	int dp[2][MAXK];
	int idx = 0;
	fill(dp[idx], dp[idx]+MAXK, INF);
	dp[idx][0] = 0;
	for (int i = 0; i < v.size(); i++) {
		idx ^= 1;
		fill(dp[idx], dp[idx]+MAXK, INF);
		for (int j = 0; j < MAXK-1; j++) {
			for (int k = 0; k < MAXK-j; k++) {
				dp[idx][j+k] = min(dp[idx][j+k], dp[idx^1][j] + v[i][k]);
			}
		}
	}
	if (tn->isLeaf) {
		for (int i = 2; i < MAXK; i++) res[i] = depth + dp[idx][i-1];
	} else {
		for (int i = 2; i < MAXK; i++) res[i] = dp[idx][i];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, K;
		string S;
		cin >> N >> K;
		TN *d = getNode();
		for (int i = 0; i < N; i++) {
			cin >> S;
			insert(d, S);
		}
		vector<int> v = solve(d, 0);
		res[t] = v[K];
		cerr << "(cerr)Case #" << t+1 << ": " << res[t] << endl;
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}