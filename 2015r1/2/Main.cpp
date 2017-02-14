#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXT = 100;

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;

	for (int t = 0; t < T; t++) {
		TN *d = getNode();
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string S;
			cin >> S;
			insert(d, S);
			int cnt = 0;
			TN *a = d;
			for (int j = 0; j < S.length() && a->cnt > 1; a = a->c[S[j]-'a'], j++) cnt++;
			res[t] += max(cnt, 1);
//			cout <<  max(cnt, 1) << endl;
		}
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}

/*
1
5
hi
hello
lol
hills
hill

*/
