#include <iostream>
#define ll long long
using namespace std;

ll mod = 1000000007;

ll mul(ll a, ll b) {
	return ((a % mod) * (b % mod)) % mod;
}

ll power(ll x, ll y) {
	if (y == 0) {
		return 1;
	}
	else if (y == 1) {
		return x % mod;
	}
	else if (y % 2 == 0) {
		return power(x, y / 2)* 2 % mod;
	}
	else {
		return power(x, y / 2)* 2 * x % mod;
	}
}

ll divv(ll a, ll b){
	return mul(a, power(b, mod - 2));
}

int main()
{
	ll x, y;
	cin >> x >> y;

	ll max = x;
	ll min = y;
	if (x < y) {
		max = y;
		min = x;
	}

	ll num12 = (max - 2 * (max - min)) / 3;
	ll num21 = num12 + max - min;

	if ((max != num12 + num21 * 2) || (min != num21 + num12 * 2)) {
		cout << 0 << endl;
		system("pause");
		return 0;
	}

	ll sum = num12 + num21;
	ll a = 1;
	ll b = 1;
	for (ll i = 1; i <= num12; ++i) {
		//a = (a * sum) % 1000000007;
		a = mul(a, sum);
		sum--;
		b = mul(b, i);
		//b = (b * i) % 1000000007;
	}

	cout << divv(a, b) << endl;

	system("pause");
	return 0;
}

#if 0
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

double gCount = 0.0;
double gSum = 0.0;

void calcSum(double sum, int n, vector<int> isFinish, int s, int e,const vector<double>& x, const vector<double>& y)
{
	sum += sqrt((x[e] - x[s])*(x[e] - x[s]) + (y[e] - y[s])*(y[e] - y[s]));
	for (int i = 0; i < n; ++i) {
		if (isFinish[i] == 0) {
			isFinish[i] = 1;
			calcSum(sum, n, isFinish, e, i, x, y);
			isFinish[i] = 0;
		}
	}

	int i = 0;
	for (; i < n; ++i) {
		if (isFinish[i] == 0) {
			break;
		}
	}
	if (i == n) {
		gSum += sum;
		gCount += 1.0;
	}
}

int main()
{
	int n;
	cin >> n;

	vector<double> x(n);
	vector<double> y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			vector<int> isFinish(n, 0);
			isFinish[i] = 1;
			isFinish[j] = 1;
			double sum = 0.0;
			calcSum(sum, n, isFinish, i, j, x, y);
		}
	}

	cout << fixed << setprecision(10);
	cout << gSum / gCount << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;

	cin >> n;
	cin >> s;

	bool yes = false;
	if (n % 2 == 0) {
		string t = s.substr(n / 2);
		if (s == t + t) {
			yes = true;
		}
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
	int r;
	cin >> r;

	cout << r * r << endl;

	return 0;
}
#endif