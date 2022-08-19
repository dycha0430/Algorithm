#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map <ll, ll> map;
ll N, P, Q, X, Y;
ll solve(ll i) {
	if (i <= 0) return 1;
	if (map.find(i) != map.end()) return map[i];
	
	return map[i] = solve(i/P - X) + solve(i/Q - Y);
}

int main(int argc, char const* argv[])
{
	cin >> N >> P >> Q >> X >> Y;
	
	cout << solve(N) << endl;
	return 0;
}