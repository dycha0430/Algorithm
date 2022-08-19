#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
	int N, K;
	cin >> N >> K;

	string str = "";
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		str.append(tmp);
	}

	string answer = str;
	sort(answer.begin(), answer.end());

	queue<pair<string, int>> q;
	unordered_map<string, bool> hashmap;
	q.push(make_pair(str, 0));
	if (str == answer) {
		cout << 0 << endl;
		return 0;
	}

	while (!q.empty()) {
		string s = q.front().first;
		int level = q.front().second;
		q.pop();

		if (hashmap.find(s) != hashmap.end()) continue;
		hashmap.insert({ s, true });

		for (int i = 0; i < N - K + 1; i++) {
			string new_s = "";
			new_s.append(s.substr(0, i));
			string reverse_s = s.substr(i, K);
			reverse(reverse_s.begin(), reverse_s.end());
			new_s.append(reverse_s);
			new_s.append(s.substr(i + K));

			q.push(make_pair(new_s, level + 1));

			if (new_s == answer) {
				cout << level + 1 << endl;
				return 0;
			}
		}
	}
	
	cout << -1 << endl;
	return 0;
}
