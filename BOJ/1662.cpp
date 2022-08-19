#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main(int argc, char const* argv[])
{
	string S;
	cin >> S;
	int answer = 0;
	stack<int> stack, num_stack;

	int tmp_sum = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			stack.push(S[i - 1] - '0');
			num_stack.push(tmp_sum - 1);
			tmp_sum = 0;
		}
		else if (S[i] == ')') {
			int mul = stack.top();
			stack.pop();
			int num = num_stack.top();
			num_stack.pop();
			tmp_sum = tmp_sum * mul + num;
		}
		else {
			tmp_sum++;
		}
	}

	cout << tmp_sum;

	return 0;
}