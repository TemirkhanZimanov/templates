#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define ppp pop_back
#define pii pair<int,int>
#define fi first
#define se second

typedef complex<ll> point;
#define x() real()
#define y() imag()

ll dot(point a, point b) {
	return (conj(a) * b).x();
}

ll cross(point a, point b) {
	return (conj(a) * b).y();
}

bool cmp(point& a, point& b) {
	if (a.y() < b.y()) return 1;
	if (a.y() > b.y()) return 0;
	return a.x() < b.x();
}

bool cmp_angle(point& a, point& b) {
	ll s = cross(a, b);
	if (s > 0) return 1;
	if (s < 0) return 0;
	return cmp(a, b);
}

vector<point> convex_hull(vector<point> a) {
	vector<point> hull;
	sort(a.begin(), a.end(), cmp);
	point shift = a[0];
	for (point& A : a) {
		A -= shift;
	}
	sort(a.begin(), a.end(), cmp_angle);
	for (point A : a) {
		while (hull.size() >= 2) {
			point B = hull.back();
			point C = hull[hull.size()-2];
			if (cross(C, B) + cross(B, A) <= cross(C, A)) {
				hull.ppp();
			}
			else break;
		}
		hull.pb(A);
	}
	for (point& A : hull) {
        A += shift;
	}
	return hull;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	
	return 0;
}
