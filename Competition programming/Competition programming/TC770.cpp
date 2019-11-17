#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LayeredGlass
{
public:
	int minDefects(vector<string> a, vector<string> b)
	{
		size_t max = a.size();
		vector<vector<int>> ia(max, vector<int>(max,0));
		vector<vector<int>> ib(max, vector<int>(max, 0));

		for (size_t i = 0; i < max; ++i) {
			for (size_t j = 0; j < max; ++j) {
				if (a[i][j] == 'X') {
					ia[i][j] = 1;
				}
				if (b[i][j] == 'X') {
					ib[i][j] = 1;
				}
			}
		}

		int minCount = getCount(ia,ib);

		vector<vector<int>> tib = ib;
		rotateB(tib, ib);
		int count = getCount(ia, ib);
		if (count < minCount) {
			minCount = count;
		}

		tib = ib;
		rotateB(tib, ib);
		count = getCount(ia, ib);
		if (count < minCount) {
			minCount = count;
		}

		tib = ib;
		rotateB(tib, ib);
		count = getCount(ia, ib);
		if (count < minCount) {
			minCount = count;
		}

		tib = ib;
		flipB(tib, ib);
		count = getCount(ia, ib);
		if (count < minCount) {
			minCount = count;
		}

		tib = ib;
		rotateB(tib, ib);
		count = getCount(ia, ib);
		if (count < minCount) {
			minCount = count;
		}

		tib = ib;
		rotateB(tib, ib);
		count = getCount(ia, ib);
		if (count < minCount) {
			minCount = count;
		}

		tib = ib;
		rotateB(tib, ib);
		count = getCount(ia, ib);
		if (count < minCount) {
			minCount = count;
		}

		return minCount;
	}

private:
	int getCount(vector<vector<int>>& ia, vector<vector<int>>& ib) {
		int count = 0;
		size_t max = ib.size();
		for (size_t i = 0; i < max; ++i) {
			for (size_t j = 0; j < max; ++j) {
				if (ia[i][j] == 1 || ib[i][j] == 1) {
					++count;
				}
			}
		}
		return count;
	}
	void rotateB(vector<vector<int>>& tib, vector<vector<int>>& ib)
	{
		size_t max = tib.size();
		for (size_t i = 0; i < max; ++i) {
			for (size_t j = 0; j < max; ++j) {
				ib[i][j] = tib[max-j-1][i];
			}
		}
	}
	void flipB(vector<vector<int>>& tib, vector<vector<int>>& ib)
	{
		size_t max = tib.size();
		for (size_t i = 0; i < max; ++i) {
			for (size_t j = 0; j < max; ++j) {
				ib[i][j] = tib[i][max-1-j];
			}
		}
	}
};

int main()
{
	vector<string> a(2);
	a[0] = "X.";
	a[1] = "..";
	vector<string> b(2);
	b[0] = "..";
	b[1] = ".X";

	LayeredGlass aaa;
	cout << aaa.minDefects(a, b) << endl;
	

	system("pause");
	return 0;
}

#if 0
#include <iostream>
using namespace std;

class MaximumMoves
{
public:
	long long getMaximumMoves(long long P, long long Q)
	{
		long long diff = Q - P;
		if (diff <= 1) {
			return -1;
		}
		return diff / 2;
	}
};

int main() 
{
	system("pause");
	return 0;
}
#endif