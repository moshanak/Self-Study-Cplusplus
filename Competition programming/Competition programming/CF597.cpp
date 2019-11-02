#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ull unsigned long long

ull process(int i) {

	ull ret = 1;
	while (1) {
		for()
	}

}

int main()
{
	string s;
	cin >> s;
	size_t n = s.size();
	ull ret = 0;
	vector<int> counter(100001,0);
	bool isu = false;
	bool isn = false;
	ull count = 0;
	for (size_t i = 0; i < n; ++i) {
		if (s[i] == 'w' || s[i] == 'm') {
			ret = 0;
			break;
		}
		if (s[i] == 'u') {
			isu = true;
			++count;
			continue;
		}
		if (isu) {
			isu = false;
			if (1 < count) {
				++counter[count];
			}
			count = 0;
		}
		if (s[i] == 'n') {
			isn = true;
			++count;
			continue;
		}
		if (isn) {
			isn = false;
			if (1 < count) {
				++counter[count];
			}
			count = 0;
		}
	}

	if (isu) {
		isu = false;
		if (1 < count) {
			++counter[count];
		}
		count = 0;
	}
	if (isn) {
		isn = false;
		if (1 < count) {
			++counter[count];
		}
		count = 0;
	}

	for (int i = 0; i < 100001; ++i) {
		if (counter[i] == 0) {
			continue;
		}

	}


	system("pause");
	return 0;
}


#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<string> ret1(t);
	vector<string> ret2(t);
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> rps(3);
		cin >> rps[0] >> rps[1] >> rps[2];
		string s;
		cin >> s;

		vector<int> temp(3,0);
		for (int j = 0; j < n; ++j) {
			if (s[j] == 'R') {
				++temp[0];
			}
			else if (s[j] == 'P') {
				++temp[1];
			}
			else {
				++temp[2];
			}
		}

		int bcount = 0;
		if (rps[0] <= temp[2]) {
			bcount += rps[0];
		}
		else {
			bcount += temp[2];
		}

		if (rps[1] <= temp[0]) {
			bcount += rps[1];
		}
		else {
			bcount += temp[0];
		}

		if (rps[2] <= temp[1]) {
			bcount += rps[2];
		}
		else {
			bcount += temp[1];
		}

		int check = n / 2;
		if (n % 2 == 1) {
			++check;
		}

		if (check <= bcount) {
			ret1[i] = "YES";
			for (int j = 0; j < n; ++j) {
				if (s[j] == 'R' && 0 < rps[1]) {
					ret2[i] += 'P';
					--rps[1];
				}
				else if (s[j] == 'P' && 0 < rps[2]) {
					ret2[i] += 'S';
					--rps[2];
				}
				else if (s[j] == 'S' && 0 < rps[0]){
					ret2[i] += 'R';
					--rps[0];
				}
				else {
					ret2[i] += 'X';
				}
			}

			for (int j = 0; j < n; ++j) {
				if (ret2[i][j] != 'X') {
					continue;
				}

				if (0 < rps[1]) {
					ret2[i][j] = 'P';
					--rps[1];
				}
				else if (0 < rps[2]) {
					ret2[i][j] = 'S';
					--rps[2];
				}
				else if (0 < rps[0]) {
					ret2[i][j] = 'R';
					--rps[0];
				}
			}
		}
		else {
			ret1[i] = "NO";
		}
	}

	for (int i = 0; i < t; ++i) {
		cout << ret1[i] << endl;
		if (ret1[i] == "YES") {
			cout << ret2[i] << endl;
		}
	}

	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define u32 unsigned int

int main() 
{
	u32 t;
	cin >> t;
	vector<string> ret(t);
	for (u32 i = 0; i < t; ++i) {
		u32 a, b;
		cin >> a >> b;

		while (b != 0) {
			u32 r = a % b;
			a = b;
			b = r;
		}

		if (a != 1) {
			ret[i] = "Infinite";
		}
		else {
			ret[i] = "Finite";
		}
	}

	for (auto& i : ret) {
		cout << i << endl;
	}

	return 0;
}
#endif