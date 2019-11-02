//#define A
//#define B
#define C
//#define D
//#define E
//#define F

#ifdef A
#include <iostream>
using namespace std;

int main()
{
	system("pause");
	return 0;
}
#endif
#ifdef B
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
using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long ret = n - 1;
	long long max = sqrt(n);
	long long temp = 0;
	for (long long i = 2; i <= max; ++i) {
		if (n % i == 0) {
			temp = n / i + i - 2;
			if (temp < ret) {
				ret = temp;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
#endif

#ifdef D
#include <iostream>
using namespace std;

int main()
{
	system("pause");
	return 0;
}
#endif
#ifdef E
#include <iostream>
using namespace std;

int main()
{
	system("pause");
	return 0;
}
#endif
#ifdef F
#include <iostream>
using namespace std;

int main()
{
	system("pause");
	return 0;
}
#endif