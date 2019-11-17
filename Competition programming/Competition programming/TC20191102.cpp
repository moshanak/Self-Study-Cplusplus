#include <iostream>
#include <string>
using namespace std;

class AB
{
public:
	string createString(int N, int K)
	{
		string s = string(N/2, 'B') + string(N-N/2,'A');
		s[N - 1] = 'A';

		if (K == 0) {
			return s;
		}

		int count = 0;
		bool existBA = true;
		while (existBA) {
			existBA = false;
			for (int i = 0; i < N - 1; ++i) {
				if (s[i] == 'B' &&s[i + 1] == 'A') {
					swap(s[i], s[i + 1]);
					if (++count == K) {
						return s;
					}
					existBA = true;
				}
			}
		}

		return "";
	}
};

int main() 
{
	system("pause");
	return 0;
}