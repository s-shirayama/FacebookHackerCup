#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002;
const int MAXT = 200;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	std::ifstream in("input.txt");
	std::cin.rdbuf(in.rdbuf());

	int T, N;
	cin >> T;
	// 0: ., 1:X, 2:A
	int m[2][MAXN], res[MAXT];
	m[0][0] = 1;
	m[1][0] = 1;
	char c;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> c;
			m[0][i] = (c == 'X') ? 1 : 0;
		}
		for (int i = 1; i <= N; i++) {
			cin >> c;
			m[1][i] = (c == 'X') ? 1 : 0;
		}
		m[0][N+1] = 1;
		m[1][N+1] = 1;

		int idx = 0, cnt = 0;
		bool loop = true;
		while(loop) {
			loop = false;
			for (int idx = 0; idx < 2; idx++) {
				for (int i = 1; i <= N; i++) {
					if (m[idx][i-1] == 1 && m[idx][i] == 0 && m[idx][i+1] == 1 && m[idx^1][i] == 0) {
						loop = true;
						cnt++;
						m[idx][i] = 2;
						m[idx^1][i] = 2;
						for (int j = 1; m[idx^1][i+j] != 1; j++) m[idx^1][i+j] = 2;
						for (int j = 1; m[idx^1][i-j] != 1; j++) m[idx^1][i-j] = 2;
					}
				}
			}
		}
		for (int idx = 0; idx < 2; idx++) {
			for (int i = 1; i <= N; i++) {
				if (m[idx][i] == 0) {
					cnt++;
					m[idx][i] = 2;
					if (m[idx^1][i] == 0) m[idx^1][i] = 2;
					for (int j = 1; m[idx][i+j] != 1; j++) m[idx][i+j] = 2;
				}
			}
		}
		res[t] = cnt;
	}
	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << res[i] << endl;
	return 0;
}

/*
1
15
.X..........X..
.X...XX.X.X....

5
8
...X.X..
.......X
5
.X.X.
.XXX.
7
.....X.
.X.....
9
..X.X.X..
..X...X.X
15
.X..........X..
.X...XX.X.X....
*/