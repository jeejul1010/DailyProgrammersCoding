#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
    int parent;
    int depth;
}node;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

int find(int i, vector<node>& g)
{
    while (i != g[i].parent)
    {
        i = g[i].parent;
    }

    return i;
}

void merge(int p, int q, vector<node>& g)
{
    if (g[p].depth == g[q].depth)
    {
        if (p < q)
        {
            g[q].parent = p;
            g[p].depth += 1;
        }
        else
        {
            g[p].parent = q;
            g[q].depth += 1;
        }
    }
    else if (g[p].depth < g[q].depth)
    {
        g[p].parent = q;
    }
    else
    {
        g[q].parent = p;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<node> group(n);
    for (int i = 0; i < n; i++)
    {
        group[i].parent = i;
        group[i].depth = 0;
    }

    sort(costs.begin(), costs.end(), cmp);

    int edgeCount = 0;
    int idx = 0;
    int p, q;

    while (edgeCount < n - 1)
    {
        p = find(costs[idx][0], group);
        q = find(costs[idx][1], group);

        if (p != q) //merge
        {
            merge(p, q, group);
            edgeCount++;
            answer += costs[idx][2];
        }

        idx++;
    }

    return answer;
}

void islandConnection()
{
    cout << solution(4, { {0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8} }) << endl;
}