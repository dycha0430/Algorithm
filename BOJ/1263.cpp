#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

int main(int argc, char const* argv[])
{
	int N;
	vector<pair<int, int>> jobs;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int t, s;
		cin >> t >> s;
		jobs.push_back(make_pair(t, s));
	}

	sort(jobs.begin(), jobs.end(), compare);

	int answer = jobs[0].second;
	for (vector<pair<int, int>>::iterator iter = jobs.begin(); iter != jobs.end(); iter++) {
		if (answer > (*iter).second) answer = (*iter).second - (*iter).first;
		else answer -= (*iter).first;
	}
	if (answer < 0) answer = -1;
	cout << answer << endl;
	
	return 0;
}