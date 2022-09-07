//#include <iostream>
//#include<vector>
//
//using namespace std;
//
//const int INF = 987654321;
//
//int minCount = INF;
//
//void dfs(const int& x, const int& y, const int& n, const int& m, const int& totalCount, const vector<vector<int>>& maps, vector<vector<int>> visited)
//{
//    if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
//    {
//        return;
//    }
//
//    if (maps[x][y] == 0 || visited[x][y] == 1)
//    {
//        return;
//    }
//
//    visited[x][y] = 1;
//
//    if (x == n - 1 && y == m - 1)
//    {
//        if (totalCount < minCount)
//        {
//            minCount = totalCount;
//            
//        }
//    }
//    else
//    {
//        dfs(x - 1, y, n, m, totalCount + 1, maps, visited);
//        dfs(x + 1, y, n, m, totalCount + 1, maps, visited);
//        dfs(x, y + 1, n, m, totalCount + 1, maps, visited);
//        dfs(x, y - 1, n, m, totalCount + 1, maps, visited);
//    }
//    
//}
//
//int solution(vector<vector<int>> maps)
//{
//    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0));
//
//    minCount = INF;
//
//    dfs(0, 0, maps.size(), maps[0].size(), 1, maps, visited);
//
//    if (minCount == INF)
//    {
//        return -1;
//    }
//
//    return minCount;
//}
//
//void gameMapShortest()
//{
//    cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}) << endl;
//    cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}} ) << endl;
//}