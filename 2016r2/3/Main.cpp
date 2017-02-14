#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXN = 200000;
const int MAXT = 50;
const int MOD = 1e9+7;

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
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
//T = 1;
	for (int t = 0; t < T; t++) {
		int N, X, H;
		cin >> N;
//N = 200000;
		vector<P> v;
		for (int i = 0; i < N; i++) {
			cin >> X >> H;
//X = 1e9, H = 1e9;
			v.push_back(P(X, H));
		}
		sort(v.begin(), v.end());
		priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;
		int ans = 0;
		for (int i = 0; i < N; i++) {
//			if (i%10000 == 0) cout << i << endl;;
			int x = v[i].first, h = v[i].second;
			while(q.size()) {
				int _h = q.top().first;
				if (_h < h) {
					vector<int> _v = q.top().second;
					ans = (LL(ans) + calc(_v))%MOD;
/*
					for (int j = 0; j < _v.size(); j++) for (int k = j+1; k < _v.size(); k++) {
						ans = (LL(ans) + LL(_v[j]-_v[k])*LL(_v[j]-_v[k])) % MOD;
					}
*/
					q.pop();
					continue;
				}
				if (_h == h) {
					/*
					for (int s : _v) {
						ans = (LL(ans) + LL(x-s)*LL(x-s)) % MOD;
					}
					*/
					vector<int> _v = q.top().second;
					q.pop();
					_v.push_back(x);
					q.push(make_pair(_h, _v));
//					q.top().second.push_back(x);
				} else {
//					q.push(make_pair(_h, _v));
				}
				break;
			}
			if (q.size() == 0 || q.top().first > h) {
				vector<int> __v;
				__v.push_back(x);
				q.push(make_pair(h, __v));
			}
		}
		while(q.size()) {
			int _h = q.top().first;
			vector<int> _v = q.top().second;
			ans = (LL(ans) + calc(_v))%MOD;
			q.pop();
/*
			for (int j = 0; j < _v.size(); j++) for (int k = j+1; k < _v.size(); k++) {
				ans = (LL(ans) + LL(_v[j]-_v[k])*LL(_v[j]-_v[k])) % MOD;
			}
*/
		}
		res[t] = ans;
		cout << "Case #" << t+1 << ": " << res[t] << endl;
	}

//	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}