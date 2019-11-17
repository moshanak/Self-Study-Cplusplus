#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getValue(int first, int last, vector<pair<pair<int, int>, int>>& lrv, int limit)
{
	int n = lrv.size() - 1;
	int l = lrv[last].first.first;
	int r = lrv[last].first.second;
	int s = lrv[last].second;
	for (int i = first; i < last; ++i)
	{
		if (l < lrv[i].first.first) {
			l = lrv[i].first.first;
		}
		if (lrv[i].first.second < r) {
			r = lrv[i].first.second;
		}
		if (limit <= (s - (r - l + 1))) {
			return 0;
		}
	}

	int ret = r - l + 1;
	if (ret < 0) {
		return 0;
	}
	else {
		return ret;
	}
}

int main()
{
	int n;
	cin >> n;
	

	vector<pair<pair<int, int>, int>> lrv(n);
	for (int i = 0; i < n; ++i) {
		cin >> lrv[i].first.first >> lrv[i].first.second;
		lrv[i].second = lrv[i].first.second - lrv[i].first.first + 1;
	}

	sort(lrv.begin(), lrv.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
	{
		return a.second > b.second;
	});

	// デバッグ
	//for (auto& i : lrv) {
	//	cout << i.first.first << " " << i.first.second << " " << i.second << endl;
	//}
	//system("pause");
	//return 0;

	// T1 + L1 をもとめる
	int last = n - 1;
	int ret = lrv[0].second + getValue(1, last, lrv, lrv[last].second);

	int count = 0;
	int roopCount = 1;
	int temp = 0;
	while ( (count + roopCount <= last) && (lrv[0].second == lrv[roopCount].second) ) {
		swap(lrv[0], lrv[roopCount]);
		temp = lrv[0].second + getValue(1, last, lrv, lrv[last].second);
		if (ret < temp) {
			ret = temp;
		}
		else {
			swap(lrv[0], lrv[roopCount]);
		}
		++roopCount;
	}

	++count;
	while (count < last) {
		// T2 + L1
		// T3 + L1
		// T1 + L1を超える可能性がある所まで繰り返す
		temp = lrv[count].second + lrv[last].second;
		if (ret < temp) {
			int limit = temp - ret;
			temp = getValue(0, count, lrv, limit) + getValue(count + 1, last, lrv, limit);
			if (ret < temp) {
				ret = temp;
			}
			roopCount = 1;
			while ((count + roopCount <= last) && (lrv[count].second == lrv[count + roopCount].second)) {
				swap(lrv[count], lrv[count+roopCount]);
				temp = getValue(0, count, lrv, limit) + getValue(count + 1, last, lrv, limit);
				if (ret < temp) {
					ret = temp;
				}
				else {
					swap(lrv[count], lrv[count + roopCount]);
				}
				++roopCount;
			}

			++count;
		}
		else {
			break;
		}
	}

	cout << ret << endl;

	return 0;
}


#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
	string s;
	cin >> s;

	s += '<';
	const int numS = s.size();
	vector<int> ret(numS,-1);
	//if (s[0] == '<') {
	//	ret[0] = 0;
	//}
	//if (s[numS-1] == '>') {
	//	ret.back() = 0;
	//}
	//for (size_t i = 0; i < numS - 1; ++i) {
	//	if (s[i] == '>' &&s[i + 1] == '<') {
	//		ret[i + 1] = 0;
	//	}
	//}

	bool isL = false;
	int firstL = 0;
	for (int i = 0; i < numS; ++i) {
		if (s[i] == '>') 
		{
			if (isL) {
				continue;
			}
			else {
				if (i != 0) {
					ret[i] = ret[i - 1] + 1;
				}
				firstL = i;
				isL = true;
				continue;
			}
		}
		else //if (s[i] == '<')
		{
			if (isL) {
				int diff = i - firstL;
				if (ret[firstL] < diff) {
					ret[firstL] = diff;
				}
				ret[firstL + 1] = diff - 1;
				for (int j = 2; j < diff; ++j) {
					ret[firstL + j] = ret[firstL + j - 1] - 1;
				}
				ret[i] = 0;
				isL = false;
				continue;
			}
			else {
				if (i == 0) {
					ret[i] = 0;
					continue;
				}
				ret[i] = ret[i - 1] + 1;
				continue;
			}
		}
	}

	long long sum = 0;
	for (auto& i : ret) {
		sum += i;
	}

	cout << sum << endl;

	return 0;
}
#endif