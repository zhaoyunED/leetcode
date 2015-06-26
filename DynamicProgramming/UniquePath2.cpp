Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.






// 同样的思路 只不过 考虑 阻碍点 路径数目设为1
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> cur(m, 0);
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] != 1)
            cur[i] = 1;
        else break;
    }
    for (int j = 1; j < n; j++) {
        bool flag = false;
        if (obstacleGrid[0][j] == 1)
            cur[0] = 0;
        else flag = true;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][j] != 1) {
                cur[i] += cur[i - 1];
                if (cur[i]) flag = true;
            }
            else cur[i] = 0;
        }
        if (!flag) return 0;
    }
    return cur[m - 1];
}