#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define MAX 100000000
using namespace std;

vector<pair<int, int>> road[1000];
int N, M, X;
int *min_time;
bool *visit;

void dijkstra(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (vector<pair<int, int>>::iterator iter = road[node].begin(); iter < road[node].end(); iter++)
    {
        pq.push(*iter);
    }
    for (int i = 0; i < N; i++)
    {
        visit[i] = false;
    }

    while (!pq.empty())
    {
        int next_node = pq.top().second;
        int time = pq.top().first;
        pq.pop();
        if (visit[next_node])
            continue;
        visit[next_node] = true;
        if (node == X - 1)
            min_time[next_node] += time;
        else if (next_node == X - 1)
        {
            min_time[node] += time;
            break;
        }

        for (vector<pair<int, int>>::iterator iter = road[node].begin(); iter < road[node].end(); iter++)
        {
            if (!visit[iter->second])
            {
                pq.push({time + iter->first, iter->second});
            }
        }
    }
}

int main(void)
{
    cin >> N >> M >> X;
    min_time = new int[N];
    visit = new bool[N];
    for (int i = 0; i < N; i++)
    {
        min_time[i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        int start, end, T;
        cin >> start >> end >> T;
        road[start - 1].push_back({T, end});
    }

    for (int i = 0; i < N; i++)
    {
        dijkstra(i);
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        answer = max(answer, min_time[i]);
    }

    cout << answer << endl;
}