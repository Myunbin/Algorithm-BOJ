#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_R = 3e4 + 1;
struct c{
	int x, y1, y2, s;
	bool operator < (const c &o) {
		return x < o.x;
	}
};

vector<pii> t(4 * MAX_R); //first = cnt, second = on/off
vector<c> a;
int n;

void update(int node, int le, int ri, int ql, int qr, int v) {
	if (qr < le || ri < ql) return;
	if (ql <= le && ri <= qr) t[node].first += v;
	else {
		int mid = le + ri >> 1;
		update(node * 2, le, mid, ql, qr, v);
		update(node * 2 + 1, mid + 1, ri, ql, qr, v);
	}
	
	if (t[node].first > 0) t[node].second = ri - le + 1; 
	else {
		if (le == ri) t[node].second = 0;
		else t[node].second = t[node * 2].second + t[node * 2 + 1].second;
	}
}

int main() {
	fio();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a.push_back({x1, y1, y2 - 1, 1});
		a.push_back({x2, y1, y2 - 1, -1});
	}
	sort(all(a));

	ll ans = 0;
	int l;
	for (int i = 0; i < 2 * n; i++) {
		if (i > 0) ans += 1LL * (a[i].x - l) * t[1].second; 
		update(1, 0, MAX_R, a[i].y1, a[i].y2, a[i].s);
		l = a[i].x;
	}
	
	cout << ans << '\n';
		
	return 0;
}
