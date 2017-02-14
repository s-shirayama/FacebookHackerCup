// http://pheromone.hatenablog.com/entry/2016/01/31/175131
#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

const int MAXN = 1e6;
const int MOD = 1e9+7;

// 各値間の２乗和をO(N)で求める
int calc(vector<int> v) {
	int ans = 0;
	LL sum1 = v[0], sum2 = LL(v[0])*LL(v[0])%MOD;
	for (int i = 1; i < v.size(); i++) {
		ans = ((LL)ans + LL(i) * LL(v[i]) * LL(v[i]) - 2LL * LL(v[i]) * sum1 + sum2) % MOD;
		ans = (ans + MOD) % MOD;
		sum1 = (sum1 + v[i]) % MOD;
		sum2 = (sum2 + LL(v[i])*LL(v[i])) % MOD;
	}
	return ans;
}

int main() {
	vector<int> v;
	for (int i = 1; i <= MAXN; i++) v.push_back(i*2);

	cout << calc(v) << endl;

	return 0;
}