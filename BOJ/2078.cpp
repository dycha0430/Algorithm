#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
	int A, B;
	cin >> A >> B;

	int L = 0, R = 0;
	while (true) {
		if (A > B) {
			L += A / B;
			A %= B;
			if (A == 0) {
				L -= 1;
				break;
			}
		}
		else {
			R += B / A;
			B %= A;
			if (B == 0) {
				R -= 1;
				break;
			}
		}
	}

	cout << L << " " << R;
	return 0;
}