//#define A
//#define B
#define C
//#define D

#ifdef C
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b,a%b);
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> tv(n);
	for (auto& i : tv) {
		cin >> i.first >> i.second;
		int temp = gcd(i.first, i.second);
		i.first /= temp;
		i.second /= temp;
	}

	pair<int, int> ret(tv[0].first, tv[0].second);
	for (int i = 1; i < n; ++i) {
		if (tv[i].first < ret.first ||
			tv[i].second < ret.second) 
		{
			int temp1 = ret.first / tv[i].first;
			if (ret.first % tv[i].first != 0) {
				++temp1;
			}
			int temp2 = ret.second / tv[i].second;
			if (ret.second % tv[i].second != 0) {
				++temp2;
			}
			if (temp1 < temp2) {
				temp1 = temp2;
			}
			ret.first = temp1 * tv[i].first;
			ret.second = temp1 * tv[i].second;
		}
		else {
			ret.first = tv[i].first;
			ret.second = tv[i].second;
		}
		//int count = 1;
		//while (1) {
		//	if (count*tv[i].first < ret.first ||
		//		count * tv[i].second < ret.second) 
		//	{
		//		++count;
		//		continue;
		//	}
		//	else {
		//		ret.first = count * tv[i].first;
		//		ret.second = count * tv[i].second;
		//		break;
		//	}
		//}
	}

	cout << ret.first + ret.second << endl;

	return 0;
}
#endif

#ifdef B
#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	long long ret = k;
	while (0 < --n) {
		ret *= (k - 1);
	}

	cout << ret << endl;

	return 0;
}
#endif

#ifdef A
#include <iostream>
using namespace std;

int main() 
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		cout << 1 << endl;
	}
	else if (a == b || b == c || c == a) {
		cout << 2 << endl;
	}
	else {
		cout << 3 << endl;
	}

	return 0;
}
#endif