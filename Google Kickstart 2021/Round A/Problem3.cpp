#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef pair<int, int> pi;

#define int ll

#define all(x) (x).begin(), (x).end()

#define endl "\n"

#define pb push_back

#define mp make_pair

#define F first

#define S second

#define ar array

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

const int N = 305;
int a[N][N];
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool ok(int x, int y) {
    if (x > 0 and x <= n and y > 0 and y <= m) {
        return true;
    }
    return false;
}

void solve() {

    cin >> n >> m;
    set<ar<int, 3>> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            s.insert({a[i][j], i, j});
        }
    }

    int ans = 0;

    while (!s.empty()) {
        auto cur = *s.rbegin();
        s.erase(s.find(cur));
        int x = cur[1];
        int y = cur[2];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ok(nx, ny)) {
                if (a[nx][ny] + 1 < cur[0]) {
                    ans += cur[0] - 1 - a[nx][ny];
                    s.erase(s.find({a[nx][ny], nx, ny}));
                    a[nx][ny] = cur[0] - 1;
                    s.insert({a[nx][ny], nx, ny});
                }
            }
        }
    }

    cout << ans << endl;

}

int32_t main()
{
    IOS
    int T = 1;
    cin >> T;

    for (int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    return 0;
}
