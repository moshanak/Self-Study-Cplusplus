#include <iostream>
#include <vector>
using namespace std;

int checkTime(int currentTime, int currentStat, vector<int>& cv, vector<int>& sv, vector<int>& fv) {
	if (currentTime < sv[currentStat]) {
		currentTime = sv[currentStat];
	}

	int temp = (currentTime - sv[currentStat]) % fv[currentStat];
	if (temp != 0) {
		currentTime += fv[currentStat] - temp;
	}

	currentTime += cv[currentStat];
	return currentTime;
}

int main() {
	int n;
	cin >> n;
	vector<int> cv(n - 1);
	vector<int> sv(n - 1);
	vector<int> fv(n - 1);

	for (int i = 0; i < n - 1; ++i) {
		cin >> cv[i] >> sv[i] >> fv[i];
	}

	vector<int> ret(n, 0);
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i; j < n - 1; ++j) {
			ret[i] = checkTime(ret[i], j, cv, sv, fv);
		}
	}

	for (auto& i : ret) {
		cout << i << endl;
	}

	return 0;
}

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	int n;
	cin >> n;
	vector<int> av(n);
	for (auto& i : av) {
		cin >> i;
	}

	vector<vector<int>> ret(h, vector<int>(w));
	int colorNum = 1;
	int currentH = 0;
	int currentW = 0;
	int move = 1;
	for (auto& i : av) {
		for (int j = 0; j < i; ++j) {
			ret[currentH][currentW] = colorNum;
			currentW += move;
			if (move == 1 && currentW == w) {
				++currentH;
				currentW = w - 1;
				move = -1;
			}
			else if (move == -1 && currentW == -1) {
				++currentH;
				currentW = 0;
				move = 1;
			}
		}
		++colorNum;
	}

	for (auto& i : ret) {
		for (auto& j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
#endif
#if 0
#include <iostream>
#define ll long long
using namespace std;

int main()
{
	ll k, a, b;
	cin >> k >> a >> b;

	ll ret = 0;
	if (b - a <= 2) {
		ret = k + 1;
	}
	else {
		ll surplusOperation = k - (a - 1);
		if (surplusOperation < 0) {
			ret = k + 1;
		}
		else {
			if (surplusOperation % 2 == 1) {
				ret = 1;
			}
			ret += (surplusOperation / 2) * (b - a) + a;
		}
	}

	cout << ret << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	array<int,3> rgb;
	cin >> rgb[0] >> rgb[1] >> rgb[2] >> n;

	sort(rgb.begin(), rgb.end(), greater<int>());

	int maxI = n / rgb[0];
	int maxJ = n / rgb[1];
	int ret = 0;
	for (int i = 0; i <= maxI; ++i) {
		for (int j = 0; j <= maxJ; ++j) {
			int diff = n - (i * rgb[0] + j * rgb[1]);
			if (0 <= diff && diff % rgb[2] == 0) {
				++ret;
			}
		}
	}

	cout << ret << endl;

	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int a, b;
	string s;
	cin >> a >> b;
	cin >> s;
	
	string checker = "0123456789";
	bool isYes = true;
	for (int i = 0; i < a + b + 1; ++i) {
		if (i == a){
			if (s[i] != '-') {
				isYes = false;
				break;
			}
			continue;
		}

		bool isNum = false;
		for (auto& j : checker) {
			if (j == s[i]) {
				isNum = true;
				break;
			}
		}

		if (!isNum) {
			isYes = false;
			break;
		}
	}

	if (isYes) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
#endif