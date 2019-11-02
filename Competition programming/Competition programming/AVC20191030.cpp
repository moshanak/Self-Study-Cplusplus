#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
	ll n, m;
	cin >> n >> m;

	vector<vector<pair<ll, ll>>> v(n+1);
	ll a, b, c;
	for (ll i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		v[a].push_back(pair<ll,ll>(b,c));
	}

	for (ll i = 1; i < n; ++i) {
		vector<ll> a(n+1,0);
		vector<pair<ll, ll>>& cv = v[i];
		if (cv.empty()) {
			continue;
		}
		if(a[cv])
		for (ll j = 0; j < cv.size(); ++j) {
			a[i] = 1;
		}

	}

	return 0;
}

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	long long k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (auto& i : v) {
		cin >> i.first >> i.second;
	}

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
	{
		return a.first < b.first;
	});

	int ret = 0;
	long long c = 0;
	for (auto& i : v) {
		c += i.second;
		if (k <= c) {
			ret = i.first;
			break;
		}
	}

	cout << ret << endl;

	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> ret(n,0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		++ret[a - 1];
		++ret[b - 1];
	}

	for (auto& i : ret) {
		cout << i << endl;
	}

	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main() 
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a <= c && c <= b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
#endif