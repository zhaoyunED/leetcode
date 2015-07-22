Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.


Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3


//DFS
void contaminate(vector<vector<char> > &grid, int i, int j)
{
        if(i>0&&grid[i-1][j]=='1'){
            grid[i-1][j]='0';
            contaminate(grid, i-1, j);
        }
        if(j>0&&grid[i][j-1]=='1'){
            grid[i][j-1]='0';
            contaminate(grid, i, j-1);
        }
        if(i<grid.size()-1&&grid[i+1][j]=='1'){
            grid[i+1][j]='0';
            contaminate(grid, i+1, j);
        }
        if(j<grid[0].size()-1&&grid[i][j+1]=='1'){
            grid[i][j+1]='0';
            contaminate(grid, i, j+1);
        }
}

int numIslands(vector<vector<char>> &grid)
{
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();

        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    contaminate(grid, i, j);
                }
            }
        }
        return cnt;
}


//BFS
//广度优先搜索 用一个队列来保存 
int numIslands(vector<vector<char>> &grid)
{
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int res = 0;
        for(int i = 0; i < grid.size(); ++ i)
            for(int j = 0; j < grid[0].size(); ++ j)
                if(grid[i][j] == '1')
                {
                    ++ res;
                    BFS(grid, i, j);
                }
        return res;
}

private:
void BFS(vector<vector<char>> &grid, int x, int y)
{
        queue<vector<int>> q;
        q.push({x, y});
        grid[x][y] = '0';

        while(!q.empty())
        {
            x = q.front()[0], y = q.front()[1];
            q.pop();

            if(x > 0 && grid[x - 1][y] == '1')
            {
                q.push({x - 1, y});
                grid[x - 1][y] = '0';
            }
            if(x < grid.size() - 1 && grid[x + 1][y] == '1')
            {
                q.push({x + 1, y});
                grid[x + 1][y] = '0';
            }
            if(y > 0 && grid[x][y - 1] == '1')
            {
                q.push({x, y - 1});
                grid[x][y - 1] = '0';
            }
            if(y < grid[0].size() - 1 && grid[x][y + 1] == '1')
            {
                q.push({x, y + 1});
                grid[x][y + 1] = '0';
            }
        }
}