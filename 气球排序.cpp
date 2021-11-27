#include <iostream>
#include <cstring>
using namespace std;
const int N = 20010;
int a[N];
int f[N];
int q[N];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		memset(f, 0, sizeof f);
		int len = 0;
		q[0] = -2e9;
		int t = n / 2;
		if (n % 2 == 0)
			t = (n - 1) / 2;
		for (int i = 0; i < t; i++) {
			int l = 0, r = len;
			if (a[i] < a[t]) {
				while (l < r) {
					int mid = r + l + 2 >> 1;
					if (q[mid] < a[i])
						l = mid;
					else
						r = mid - 1;
				}
				len = max(len, r + 1);
				q[r + 1] = a[i];
			}
		}
		int ans = n - len;
		len = 0;
		q[0] = -2e9;
		for (int i = t + 1; i < n; i++) {
			int l = 0, r = len;
			if (a[i] > a[t]) {
				while (l < r) {
					int mid = r + l + 2 >> 1;
					if (q[mid] < a[i])
						l = mid;
					else
						r = mid - 1;
				}
				len = max(len, r + 1);
				q[r + 1] = a[i];
			}
		}
		ans = ans - len;
		ans -= 1;
		printf("%d\n",ans);
	}
	return 0;
}
