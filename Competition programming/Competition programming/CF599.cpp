//#define A
//#define B1
//#define B2
#define C
//#define D

#ifdef D
#include <iostream>
using namespace std;

int main()
{
	system("pause");
	return 0;
}
#endif

#ifdef C
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
	ll n;
	cin >> n;

	if (n % 2 == 0) {
		cout << 2 << endl;
		return 0;
	}
	else {
		ll root = static_cast<ll>(sqrt(static_cast<double>(n)));
		for (ll i = 3; i <= root; i += 2) {
			while (n % i == 0) {
				cout << i << endl;
				return 0;
			}
		}

		cout << n << endl;
		return 0;
	}
}
#endif

#ifdef B
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int testCaseMax;
	cin >> testCaseMax;
	vector<string> ret(testCaseMax);
	for (int tc = 0; tc < testCaseMax; ++tc)
	{
		// 差が２か所よりも多ければNO
		// 2箇所だった場合、４ケースためして同じになればYES、ならなければNO
		int n;
		cin >> n;
		string s;
		cin >> s;
		string t;
		cin >> t;
		string diff_s;
		string diff_t;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				diff_s += s[i];
				diff_t += t[i];
			}
		}

		if (diff_s.size() == 0) {
			ret[tc] = "Yes";
			continue;
		}
		else if (diff_s.size() == 2)
		{
			bool isSame = false;

			swap(diff_s[0], diff_t[0]);
			if (diff_s == diff_t) {
				isSame = true;
			}
			swap(diff_s[0], diff_t[0]);

			swap(diff_s[0], diff_t[1]);
			if (diff_s == diff_t) {
				isSame = true;
			}
			swap(diff_s[0], diff_t[1]);

			swap(diff_s[1], diff_t[0]);
			if (diff_s == diff_t) {
				isSame = true;
			}
			swap(diff_s[1], diff_t[0]);

			swap(diff_s[1], diff_t[1]);
			if (diff_s == diff_t) {
				isSame = true;
			}
			swap(diff_s[1], diff_t[1]);

			if (isSame) {
				ret[tc] = "Yes";
				continue;
			}
		}
		
		ret[tc] = "No";
	}

	for (auto& i : ret) {
		cout << i << endl;
	}

	return 0;
}
#endif

#ifdef A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int testCaseMax;
	cin >> testCaseMax;
	vector<int> ret(testCaseMax, 1);
	for (int testCase = 0; testCase < testCaseMax; ++testCase)
	{
		int n;
		cin >> n;
		vector<int> av(n);
		for (auto& i : av) {
			cin >> i;
		}
		
		sort(av.begin(), av.end(), greater<int>());

		for(int i = av[0]; 1 < i; --i){
			if (n < i) {
				continue;
			}
			int j = 0;
			for (; j < i; ++j) {
				if (av[j] < i) {
					break;
				}
			}
			if (j == i) {
				ret[testCase] = i;
				break;
			}
		}
	}

	for (auto& i : ret) {
		cout << i << endl;
	}

	return 0;
}
#endif
