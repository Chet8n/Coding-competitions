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

void solve() {

    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    int mid = (n - 2) / 2;
    int cnt = 0;
    for (int i = 0; i <= mid; i++) {
        if (s[i] != s[n - 1 - i]) {
            cnt++;
        }
    }

    cout << abs(k - cnt) << endl;

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
