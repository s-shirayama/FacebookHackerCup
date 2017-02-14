#include <bits/stdc++.h>
using namespace std;

const int MAXN = 301;
const int MAXT = 100;
const int INF = 1 << 30;

struct trie_t {
	trie_t *p[26];
	bool e;
	int c;
};

trie_t *createNode() {
	trie_t *t = new trie_t;
	for (int i = 0; i < 26; i++) t->p[i] = NULL;
	t->e = false;
	t->c = 0;
	return t;
}

trie_t *getValidTrie(trie_t *root, char c) {
	if (!root->p[c-'a']) root->p[c-'a'] = createNode();
	return root->p[c-'a'];
}

void deleteTrie(trie_t *root) {
	for (int i = 0; i < 26; i++) if (root->p[i]) deleteTrie(root->p[i]);
	delete root;
}

vector<int> bar(trie_t *root) {
	vector<int> dp(root->c + 1, INF);
	dp[0] = 0;
	if (root->e) dp[1] = 1;
	for (int i = 0; i < 26; i++) if (root->p[i]) {
		vector<int> a = bar(root->p[i]);
		for (int j = dp.size() - 1; j >= 0; j--) {
			for (int k = 0; k < a.size(); k++) if (0 <= j - k) {
				dp[j] = min(dp[j], dp[j-k] + a[k] + 2);
			}
		}
	}
	return dp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::ifstream in("input.txt");
	std::cin.rdbuf(in.rdbuf());

	int T, N, K, res[MAXT];
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		trie_t *root = createNode();
		for (int i = 0; i < N; i++) {
			string S;
			cin >> S;
			trie_t *t = root;
			t->c += 1;
			for (char c : S) {
				t = getValidTrie(t, c);
				t->c += 1;
			}
			t->e = true;
		}
		res[t] = bar(root)[K];
		deleteTrie(root);
	}
	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;

	return 0;
}