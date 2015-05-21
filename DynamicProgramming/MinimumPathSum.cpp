Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


//���͵Ķ�̬�滮��Ŀ O(n2)�Ŀռ临�Ӷ�
int minPathSum(vector<vector<int>>& grid) 
	{
        if(grid.size()==0 || grid[0].size()==0)
            return 0;
        int m =grid.size();
        int n = grid[0].size();
        
        int minPath[m][n];
        minPath[0][0] = grid[0][0];
        
        for(int i=1;i<m;i++)
            minPath[i][0] = minPath[i-1][0]+grid[i][0];
        for(int i=1;i<n;i++)
            minPath[0][i] = minPath[0][i-1]+grid[0][i];
            
        for(int i=1 ;i<m;i++)
        for(int j=1; j<n;j++)
        {
            minPath[i][j] = min(minPath[i-1][j],minPath[i][j-1])+grid[i][j];
        }
        
        return minPath[m-1][n-1];
}


//���͵Ķ�̬�滮��Ŀ O(n)�Ŀռ临�Ӷ� 
//��ʼ�����µ�һ�е�minPath��ʱ�� ֻ��Ҫ��һ�е����� ����ֻ��ҪO(n)�Ŀռ临�Ӷ�
//
int minPathSum(vector<vector<int>>& grid) 
{
	if(grid.size()==0 || grid[0].size()==0)
            return 0;
        int m =grid.size();
        int n = grid[0].size();
        
        int minPath[n];
        minPath[0] =grid[0][0];
        
        for(int i=1;i<n;i++)
            minPath[i] = minPath[i-1]+grid[0][i];
        
         for(int i=1;i<m;i++)
         {
             minPath[0] += grid[i][0];
             for(int j=1;j<n;j++)
             {
				 //               minPath[j]��ʾ��Ӧ��minPath[i-1][j]  minPath[j-1]��ʾ��Ӧ�� minPath[i][j-1]
                 minPath[j] = min(minPath[j],minPath[j-1])+grid[i][j];
             }
         }
        return minPath[n-1];
}