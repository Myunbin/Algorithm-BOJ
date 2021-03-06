#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
const int MOD = 1000000007;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 10;
const int MAXR = 2e5 + 10;
int dp[MAXN];
int go(int x) {
	if (x == 2 || x == 5) return 1;
	if (x < 0) return INF;
	int &ret = dp[x];
	if (ret != -1) return ret;
	return ret = min(go(x-2)+1, go(x-5)+1);
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	cout << (go(n) >= INF ? -1 : go(n)) << endl;
	return 0;
}
