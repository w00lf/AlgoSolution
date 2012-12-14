#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

int main() {
	int n;
	double x, y, r;

	while (scanf("%lf%lf%lf%d", &x, &y, &r, &n) == 4 && r > 0) {
		int ans = 0, cnt = 0;
		vector<double> v;

		for (int i = 0; i < n; ++i) {
			double xx, yy;

			scanf("%lf%lf", &xx, &yy);
			xx -= x;
			yy -= y;
			if (xx == 0 && yy == 0) {
				++ans;
			} else if (hypot(xx, yy) < r + EPS) {
				v.push_back(atan2(yy, xx));
			}
		}
		sort(v.begin(), v.end());
		n = v.size();
		for (int i = 0; i < n; ++i) {
			v.push_back(v[i] + 2 * M_PI);
		}
		for (int i = 0, j = 0; i < n; ++i) {
			while (v[j] < v[i] + M_PI + EPS) {
				++j;
			}
			cnt = max(cnt, j - i);
		}
		ans += cnt;
		printf("%d\n", ans);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806223 	2290 	Transmitters 	Accepted 	C++ 	0.012 	2011-05-24 10:13:23
/*
id => 1174061
pid => 2290
pname => Transmitters
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:17:31
*/
