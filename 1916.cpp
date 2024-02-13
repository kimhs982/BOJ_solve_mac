#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int dijkstra(const vector<pair<int, int>> *, int, int, int);

int main()
{
    int N, M, sp, ep;
    cin >> N >> M;
    auto *costs = new vector<pair<int, int>>[N];
    for (int i = 0; i < M; i++)
    {
        int start, dest, cost;
        cin >> start >> dest >> cost;
        costs[start - 1].push_back(make_pair(cost, dest - 1));
    }
    cin >> sp >> ep;
    cout << dijkstra(costs, N, sp - 1, ep - 1) << '\n';
    delete[] costs;
}

int dijkstra(const vector<pair<int, int>> *map, int n, int s, int e)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_city = pq.top().second;
        if (cur_cost > dist[cur_city])
            continue;
        for (int i = 0; i < map[cur_city].size(); i++)
        {
            int next_city = map[cur_city][i].second;
            int next_cost = cur_cost + map[cur_city][i].first;
            pq.pop();
            if (dist[next_city] > next_cost)
            {
                pq.push(make_pair(next_cost, next_city));
                dist[next_city] = next_cost;
            }
        }
    }
}