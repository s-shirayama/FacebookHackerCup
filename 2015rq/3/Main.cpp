#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int MAXN = 100;
const int MAXT = 100;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	int T, res[MAXT];
	cin >> T;
	for (int t = 0; t < T; t++) {
		int M, N, m[MAXN][MAXN], chk[MAXN][MAXN];
		P gl;
		queue<pair<int, P>> que;
		vector<P> v;

		// input
		cin >> M >> N;
		for (int i = 0; i < M; i++) {
			memset(chk[i], 0, sizeof(chk[i]));
			string S;
			cin >> S;
			for (int j = 0; j < N; j++) {
				if (S[j] == 'S') {
					que.push(make_pair(0, make_pair(i, j)));
					chk[i][j] = 1;
				} else if (S[j] == 'G') {
					gl = make_pair(i, j);
				}
				m[i][j] = 0;
				switch(S[j]) {
					case '#': m[i][j] = 1; break;
					case '<': m[i][j] = 10; v.push_back(make_pair(i, j)); break;
					case '^': m[i][j] = 11; v.push_back(make_pair(i, j)); break;
					case '>': m[i][j] = 12; v.push_back(make_pair(i, j)); break;
					case 'v': m[i][j] = 13; v.push_back(make_pair(i, j)); break;
				}
			}
		}

		// BFS
		int cnt = 0;
		while(que.size()) {
			pair<int, P> p = que.front(); que.pop();
			int c = p.first;
			P cur = p.second;

			// Rotate
			if (c > cnt) {
				for (P a: v) {
					m[a.first][a.second] = 10 + (((m[a.first][a.second] % 10) + 1) % 4);
				}
			}
			cnt = c;

			// Check Laser (up, down, left, right)
			bool _chk = false;
			for (int i = cur.first; i >= 0; i--) if (m[i][cur.second] > 0) {
				if (m[i][cur.second] == 13) _chk = true;
				break;
			}
			for (int i = cur.first; i < M; i++) if (m[i][cur.second] > 0) {
				if (m[i][cur.second] == 11) _chk = true;
				break;
			}
			for (int i = cur.second; i >= 0; i--) if (m[cur.first][i] > 0) {
				if (m[cur.first][i] == 12) _chk = true;
				break;
			}
			for (int i = cur.second; i < N; i++) if (m[cur.first][i] > 0) {
				if (m[cur.first][i] == 10) _chk = true;
				break;
			}
			if (c > 0 && _chk) continue;

			// Check Goal
			if (cur.first == gl.first && cur.second == gl.second) {
				res[t] = cnt;
				break;
			}

			// Move
			for (int i = 0; i < 4; i++) {
				int x = cur.second + dx[i];
				int y = cur.first + dy[i];
				if (x < 0 || x >= N || y < 0 || y >= M || ((chk[y][x] >> (cnt%4)) & 1) || m[y][x] > 0) continue;
				chk[y][x] = chk[y][x] | (1<<(cnt%4));
				que.push(make_pair(c+1, make_pair(y, x)));
			}
		}
	}
	// Output
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i+1 << ": ";
		if (res[i] > 0) cout << res[i];
		else cout << "impossible";
		cout << endl;
	}
	return 0;
}

