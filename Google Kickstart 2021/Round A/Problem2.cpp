#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef pair<int, int> pi;

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

struct info {
    int l;
    int r;
    int u;
    int d;
};

void solve() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 5, vector<int>(m + 5));
    info dp[n + 5][m + 5];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= n + 2; i++) {
        for (int j = 0; j <= m + 2; j++) {
            dp[i][j].l = 0;
            dp[i][j].r = 0;
            dp[i][j].u = 0;
            dp[i][j].d = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                dp[i][j].l = dp[i][j - 1].l + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j > 0; j--) {
            if (a[i][j] == 1) {
                dp[i][j].r = dp[i][j + 1].r + 1;
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 1) {
                dp[i][j].u = dp[i - 1][j].u + 1;
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = n; i > 0; i--) {
            if (a[i][j] == 1) {
                dp[i][j].d = dp[i + 1][j].d + 1;
            }
        }
    }




    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 2; k <= dp[i][j].u; k++) {
                if (dp[i][j].r >= 2 * k) {
                    cnt++;
                }
                if (dp[i][j].l >= 2 * k) {
                    cnt++;
                }
            }

            for (int k = 2; k <= dp[i][j].r; k++) {
                if (dp[i][j].u >= 2 * k) {
                    cnt++;
                }
                if (dp[i][j].d >= 2 * k) {
                    cnt++;
                }
            }

            for (int k = 2; k <= dp[i][j].d; k++) {
                if (dp[i][j].r >= 2 * k) {
                    cnt++;
                }
                if (dp[i][j].l >= 2 * k) {
                    cnt++;
                }
            }
            for (int k = 2; k <= dp[i][j].l; k++) {
                if (dp[i][j].u >= 2 * k) {
                    cnt++;
                }
                if (dp[i][j].d >= 2 * k) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
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
