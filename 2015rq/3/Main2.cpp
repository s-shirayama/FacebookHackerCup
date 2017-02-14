#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < int(n); ++i)

using namespace std;

namespace {

struct Pt { int r, c; };  // A point (row,column) on the grid.
Pt operator+(const Pt &p, const Pt &q) { return Pt{p.r + q.r, p.c + q.c}; }
bool operator<(const Pt &p, const Pt &q) { return p.r < q.r || (p.r == q.r && p.c < q.c); }
bool operator==(const Pt &p, const Pt &q) { return p.r == q.r && p.c == q.c; }

const Pt dirs[4] = {
    { -1,  0 },  // up
    {  0, +1 },  // right
    { +1,  0 },  // down
    {  0, -1 }   // left
};

int getTurretDir(char ch) {
    if (ch == '^') return 0;  // up
    if (ch == '>') return 1;  // right
    if (ch == 'v') return 2;  // down
    if (ch == '<') return 3;  // left
    return -1;  // shouldn't happen!
}

vector<string> addBorder(const vector<string> &maze, char ch) {
    vector<string> res;
    int width = maze[0].size();
    res.push_back(string(width + 2, ch));
    for (const string &row : maze) res.push_back(ch + row + ch);
    res.push_back(string(width + 2, ch));
    return res;
}

}  // namespace

int main() {
    int T = 0;
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    cin >> T;
    for (int caseNo = 1; caseNo <= T; ++caseNo) {
        // Read input.
        int H = 0, W = 0;
        cin >> H >> W;
        vector<string> maze(H);
        REP(r, H) cin >> maze[r];
    
        // Ensure grid has walls on the edges.
        maze = addBorder(maze, '#');
        H += 2, W += 2;

        // Find start/goal location.
        Pt Start, Goal;
        REP(r, H) REP(c, W) {
            if (maze[r][c] == 'S') {
                Start = Pt{r, c};
                maze[r][c] = '.';
            } else if (maze[r][c] == 'G') {
                Goal = Pt{r, c};
                maze[r][c] = '.';
            }
        }

        // Find cells blocked by lasers at time t modulo 4
        vector<string> blocked[4];
        REP(t, 4) {
            blocked[t] = maze;
            REP(r, H) REP(c, W) {
                if (maze[r][c] == '.' || maze[r][c] == '#') continue;  // not a turret
                Pt dir = dirs[(getTurretDir(maze[r][c]) + t)%4];
                for (Pt p = Pt{r,c} + dir; maze[p.r][p.c] == '.'; p = p + dir)
                    blocked[t][p.r][p.c] = '~';
            }
        }

        // Breadth-first search for solution
        set<Pt> visited[4];  // places visited at each time mod 4
        vector<pair<int, Pt>> queue;  // states (time, place) to process
        queue.push_back(make_pair(0, Start));  // initial state
        size_t pos;
        for (pos = 0; pos < queue.size(); ++pos) {
            int time = queue[pos].first;
            Pt place = queue[pos].second;
            if (place == Goal) break;
            REP(dir, 4) {
                Pt q = place + dirs[dir];
                int u = (time + 1)%4;
                if (blocked[u][q.r][q.c] == '.' && visited[u].insert(q).second)
                    queue.push_back(make_pair(time + 1, q));
            }
        }
        std::cout << "Case #" << caseNo << ": ";
        if (pos < queue.size()) std::cout << queue[pos].first;
        else std::cout << "impossible";
        std::cout << endl;
    }
}