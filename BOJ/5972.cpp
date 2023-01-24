#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int MAX = 50000000;
int N, M;
vector<pair<int, int>>* map;
bool* visited;


int minCowsToEnd() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		pair<int, int> val = pq.top();
		pq.pop();
		if (val.second == N - 1) return val.first;
		visited[val.second] = true;
		vector<pair<int, int>> v = map[val.second];
		for (vector<pair<int, int>>::iterator iter = v.begin(); iter < v.end(); iter++) {
			if (!visited[(*iter).first]) pq.emplace(val.first + (*iter).second, (*iter).first);
		}
	}
}

int main(int argc, char const* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	map = new vector<pair<int, int>> [N];
	visited = new bool[N];

	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		A--;
		B--;
		map[A].emplace_back(B, C);
		map[B].emplace_back(A, C);
	}

	cout << minCowsToEnd();

	return 0;
}

