#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

int defected[10001];
bool finished[10001];
int inf = 100000001;
int main(int argc, char const* argv[])
{
	int tc;
	cin >> tc;
	for (int test_case = 0; test_case < tc; test_case++) {
		int n, d, c;
		int ans_num = 0, ans_time = 0;
		cin >> n >> d >> c;

		unordered_map<int, list<pair<int, int>>> map;

		for (int i = 0; i <= n; i++) {
			defected[i] = inf;
			finished[i] = false;
		}

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			map[b].push_back(make_pair(a, s));
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		q.push(make_pair(0, c));
		defected[c] = 0;
		while (!q.empty()) {
			int prev_time = q.top().first;
			int computer = q.top().second;
			q.pop();
			if (finished[computer]) continue;
			finished[computer] = true;
			if (map.find(computer) == map.end()) continue;
	
			list<pair<int, int>> adj = map.at(computer);
			
			for (list<pair<int, int>>::iterator iter = adj.begin(); iter != adj.end(); iter++) {
				int adj_com = (*iter).first;
				int time = (*iter).second;
				defected[adj_com] = min(defected[adj_com], time + prev_time);
				q.push(make_pair(defected[adj_com], adj_com));
			}
		}

		for (int i = 1; i <= n; i++) {
			if (defected[i] != inf) {
				ans_num++;
				ans_time = max(ans_time, defected[i]);
			}
		}

		cout << ans_num << " " << ans_time << endl;
	}
	return 0;
}