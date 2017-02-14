#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long int LL;
typedef long double LD;

const int MAXT = 1000;
const LD ESP = 1e-6;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	// res 0: white, 1: black
	int T, P, X, Y, res[MAXT];
	memset(res, 0, sizeof(res));
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> P >> X >> Y;
		// Move (-50, -50), Switch X <-> Y
		int x =  Y - 50, y = X - 50;
		if (x * x + y * y > 2500 || P == 0) {
			res[t] = 0;
		} else if (x == 0 && y == 0) {
			res[t] = (P > 0)?1:0;
		} else {
			LD ang = atan2l((double)y, (double)x);
			if (ang < 0) ang += 2 * M_PI;
			res[t] = (ang <= M_PI*2*P/100 || (abs(ang - M_PI*2*P/100) < ESP))?1:0;
		}
	}

	for (int i = 0; i < T; i++) cout << "Case #" << i+1 << ": " << ((res[i]==0)?"white":"black") << endl;
	return 0;
}