#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> x(n), y(n), c(n);
	char bw;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		cin >> bw;
		if (bw == 'W') {
			c[i] = 0;
		}
		else {
			c[i] = 1;
		}
	}

	int ret = 0;
	for (int i = -k; i < 0; ++i) {
		for (int j = -k; j < 0; ++j) {
			int count = 0;
			for (int l = 0; l < n; ++l) {
				if ((((x[l] - i) / k + (y[l] - j) / k) % 2) == c[l]) {
					++count;
				}
			}
			if (count < n - count) {
				count = n - count;
			}
			if (ret < count) {
				ret = count;
			}
		}
	}

	cout << ret << endl;
	return 0;
}

#if 0
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int pt = 0;
	int px = 0;
	int py = 0;
	bool yes = true;
	for (int i = 1; i <= n; ++i) 
	{
		int t, x, y;
		cin >> t >> x >> y;

		int difft = t - pt;
		int diffxy = abs(x - px + y - py);
		if (difft < diffxy || (difft - diffxy) % 2 != 0) {
			yes = false;
		}


		pt = t;
		px = x;
		py = y;
	}

	if (yes) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main() 
{
	int a, b;
	cin >> a >> b;
	int c;
	if (b < 10) {
		c = a * 10 + b;
	}
	else if (b < 100) {
		c = a * 100 + b;
	}
	else {
		c = a * 1000 + b;
	}

	for (int i = 1; i < c; ++i) {
		if (c == i * i) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;

}
#endif
#if 0
#include <iostream>
using namespace std;

int main() 
{
	int a, b;
	cin >> a >> b;

	if (a * b % 2 == 0) {
		cout << "Even" << endl;
	}
	else {
		cout << "Odd" << endl;
	}

	return 0;
}
#endif