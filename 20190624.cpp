#include <iostream>
#include <vector>
#include <string>
using namespace std;

string create(string x, string y, int op) {
	if (op == 0) { //+
		return x + "+" + y;
	}
	else if (op == 1) { // -
		return x + "-" + y;
	}
	else{ // nasi
		return x + y;
	}
}

int main()
{
	vector<int> opCase(8, 0);
	string num = "123456789";
	while(opCase[7] != 3)
	{
		string siki = num.substr(0,1);
		for (int i = 1; i < 9; ++i) {
			siki = create(siki, num.substr(i, 1), opCase[i-1]);
		}		

		long long sum = 0;
		size_t cpos = 0;
		char bop = '\0';
		size_t bpos = 0;
		int bnum = 0;
		while (cpos < siki.size())
		{
			if (siki[cpos] == '+') {
				string s = siki.substr(bpos, cpos - bpos);
				if(bop == '-') {
					sum -= atoll(s.c_str());
				}
				else {
					sum += atoll(s.c_str());
				}
				bpos = cpos + 1;
				bop = '+';
			}
			else if (siki[cpos] == '-') {
				string s = siki.substr(bpos, cpos - bpos);
				if (bop == '-') {
					sum -= atoll(s.c_str());
				}
				else{
					sum += atoll(s.c_str());
				}

				bpos = cpos + 1;
				bop = '-';
			}
			++cpos;
		}
		{
			string s = siki.substr(bpos, cpos - bpos);
			if (bop == '-') {
				sum -= atoll(s.c_str());
			}
			else{
				sum += atoll(s.c_str());
			}
		}

		if (sum == 100) {
			cout << siki << endl;
		}

		++opCase[0];
		for (int i = 0; i < 8; ++i) {
			if (opCase[i] == 3) {
				if (i != 7) {
					opCase[i] = 0;
					++opCase[i + 1];
				}
			}
		}
	}

	system("pause");
	return 0;
}

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> numSVec;
	string input;
	cin >> input;

	size_t bpos = 0;
	size_t cpos = 0;
	while (1)
	{
		cpos = input.find(",", bpos);
		if (cpos != string::npos) {
			string s = input.substr(bpos, cpos - bpos);
			numSVec.push_back(s);
			bpos = cpos + 1;
		}
		else {
			string s = input.substr(bpos);
			numSVec.push_back(s);
			break;
		}
	}

	sort(numSVec.begin(), numSVec.end(), [](const string& x, const string& y) {
		int i = 0;
		while (1) {
			char xt = x[i];
			char yt = y[i];
			if (atoi(&xt) < atoi(&yt)) {
				return false;
			}
			else if (atoi(&xt) > atoi(&yt)) {
				return true;
			}
			else{
				++i;
				if (x == y) {
					return x > y;
				}
				else if (x.size() == i || y.size() == i) {
					return x.size() < y.size();
				}
			}
		}
	});

	for (auto& s : numSVec) {
		cout << s;
	}
	cout << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<unsigned long long> ret(100);
	ret[0] = 0;
	ret[1] = 1;
	for (int i = 2; i < 100; ++i) {
		ret[i] = ret[i-2] + ret[i-1];
	}
	for (int i = 0; i < 99; ++i) {
		cout << ret[i] << ",";
	}
	cout << ret[99];

	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> input(2);
	cin >> input[0];
	cin >> input[1];

	vector<vector<string>> sVec(2);

	for(int count = 0; count < 2; ++count){
		size_t bpos = 0;
		size_t cpos = 0;
		while (1)
		{
			cpos = input[count].find(",", bpos);
			if (cpos != string::npos) {
				string s = input[count].substr(bpos, cpos - bpos);
				sVec[count].push_back(s);
				bpos = cpos + 1;
			}
			else {
				string s = input[count].substr(bpos);
				sVec[count].push_back(s);
				break;
			}
		}
	}

	size_t maxSize = sVec[0].size();
	if (maxSize < sVec[1].size()) {
		maxSize = sVec[1].size();
	}

	string ret;
	for (size_t i = 0; i < maxSize; ++i) {
		if (i < sVec[0].size()) {
			ret += sVec[0][i] + ",";
		}
		if (i < sVec[1].size()) {
			ret += sVec[1][i] + ",";
		}
	}
	
	cout << ret.substr(0, ret.size() - 1) << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

double sumFunc(double sum, vector<double>::iterator& i, vector<double>::iterator& end) {
	sum += *i++;
	return (i != end) ? sumFunc(sum, i, end) : sum;
}

int main()
{
	double sumF = 0, sumW = 0, sumR = 0;
	vector<double> numVec;
	string input;
	cin >> input;

	size_t bpos = 0;
	size_t cpos = 0;
	while(1)
	{
		cpos = input.find(",", bpos);
		if (cpos != string::npos) {
			string s = input.substr(bpos, cpos - bpos);
			double i = atof(s.c_str());
			numVec.push_back(i);
			bpos = cpos+1;
		}
		else {
			string s = input.substr(bpos);
			double i = atof(s.c_str());
			numVec.push_back(i);
			break;
		}
	}

	for (auto& i : numVec) {
		sumF += i;
	}

	{
		auto i = numVec.begin();
		while (i != numVec.end()) {
			sumW += *i++;
		}
	}
	{
		auto i = numVec.begin();
		auto e = numVec.end();
		sumR = sumFunc(0, i, e);
	}

	cout << sumF << "  " << sumW << "  " << sumR << endl;

	system("pause");
	return 0;
}
#endif