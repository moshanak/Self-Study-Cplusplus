//#define D
#define E

#ifdef E
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> xy(m);
	{
		int temp;
		for (auto& i : xy) {
			cin >> i.first >> i.second >> temp;
		}
	}

	int ret = 0;
	vector<int> isFind(n + 1, 0);
	while(1)
	{
		vector<int> count(n + 1, 0);
		for (auto& i : xy) {
			++count[i.first];
			++count[i.second];
		}

		int index = 0;
		int max = 0;
		for (int i = 1; i <= n; ++i) {
			if (max < count[i]) {
				max = count[i];
				index = i;
			}
		}
		++ret;
		isFind[index] = 1;

		vector<pair<int, int>> xy2;
		xy2.reserve(m);
		for (auto& i : xy) {
			if (i.first == index) {
				isFind[i.second] = 1;
			}
			else if (i.second == index) {
				isFind[i.first] = 1;
			}
			else {
				xy2.push_back(i);
			}
		}

		if (xy2.empty()) {
			break;
		}

		xy.swap(xy2);
	}

	for (int i = 1; i <= n; ++i) {
		if (isFind[i] != 1) {
			++ret;
		}
	}

	cout << ret << endl;
	system("pause");
	return 0;
}
#endif

#ifdef D
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	vector<pair<int, int>> uv(n - 1);
	vector<int> isSame(n - 1, 0);
	for (int i = 0; i < n-1;++i) {
		cin >> uv[i].first >> uv[i].second >> isSame[i];
		if (isSame[i] % 2 == 0) {
			isSame[i] = 1;
		}
		else {
			isSame[i] = 0;
		}
	}
	vector<int> check(n - 1, 0);
	vector<int> ret(n+1, -1);
	ret[uv[0].first] = 0;
	if (isSame[0]==1) {
		ret[uv[0].second] = 0;
	}
	else {
		ret[uv[0].second] = 1;
	}

	bool isFinished = false;
	while (!isFinished)
	{
		isFinished = true;
		for (int i = 1; i < n - 1; ++i) 
		{
			if (check[i] == 1) {
				continue;
			}

			if (ret[uv[i].first] != -1) 
			{
				if (isSame[i] == 1) {
					ret[uv[i].second] = ret[uv[i].first];
				}
				else {
					ret[uv[i].second] = ret[uv[i].first] + 1;
					if (ret[uv[i].second] == 2) {
						ret[uv[i].second] = 1;
					}
				}
				check[i] = 1;
			}
			else if (ret[uv[i].second] != -1)
			{
				if (isSame[i] == 1) {
					ret[uv[i].first] = ret[uv[i].second];
				}
				else {
					ret[uv[i].first] = ret[uv[i].second] + 1;
					if (ret[uv[i].first] == 2) {
						ret[uv[i].first] = 1;
					}
				}
				check[i] = 1;
			}
			else 
			{
				isFinished = false;
			}
		}
	}

	for(int i = 1; i <= n; ++i )
	{
		cout << ret[i] << endl;
	}

	return 0;
}
#endif