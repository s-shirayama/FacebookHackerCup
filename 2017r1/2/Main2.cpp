//CONTEST SOURCE
#include <cstring>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
#define ll long long
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define all(s) (s).begin(),(s).end()
#define L(s) (int)(s).size()
#define inf 1000000000
int t, n, R;
pair<int, int> a[55];
ll ins[55][55];
int main() {
  //srand(1);
//  freopen("input.txt", "r", stdin);
//  freopen("output2.txt", "w", stdout);
  cin >> t;
  //t = 50;
  for(int tc = 1; tc <= t; ++tc) {
    cerr << tc << endl;
    cin >> n >> R;
    //n = 50;
    //R = 1000000000;
    for(int i = 0; i < n; ++i) {
      cin >> a[i].x >> a[i].y;
      //a[i].x = rand() % 1000000000;
      //a[i].y = rand() % 1000000000;
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        ins[i][j] = 0;
        for(int k = 0; k < n; ++k) {
          if (a[k].x >= a[i].x && a[k].x <= a[i].x + R &&
              a[k].y >= a[j].y && a[k].y <= a[j].y + R) {
            ins[i][j] += (1LL << k);
          }
        }
      }
    }
    int ans = 0;
    for(int l = 0; l < n; ++l) {
      for(int u = 0; u < n; ++u) {
        for(int r = 0; r < n; ++r) {
          for(int d = 0; d < n; ++d) {
            ll val = ins[l][u] | ins[r][d];
            ans = max(ans, __builtin_popcountll(val));
          }
        }
      }
    }
    cout << "Case #" << tc << ": " << ans << endl;
  }
}
