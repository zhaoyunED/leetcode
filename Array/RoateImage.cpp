You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?


//方法1 异或的操作值得学习哈
 void rotate(vector<vector<int> >& matrix) {
        //reverse
        for(int i = 0; i < matrix.size() / 2; i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                matrix[i][j] ^= matrix[matrix.size() - 1 - i][j];
                matrix[matrix.size() - 1 - i][j] ^= matrix[i][j]; 
                matrix[i][j] ^= matrix[matrix.size() - 1 - i][j];
            }
        }

        //swap
        for(int i = 0; i < matrix.size() - 1; i++)
        {
            for(int j = i + 1; j < matrix.size(); j++)
            {
                matrix[j][i] ^= matrix[i][j];       
                matrix[i][j] ^= matrix[j][i];       
                matrix[j][i] ^= matrix[i][j];       
            }
        }
    }

//方法2 其实是一个思路
void rotate(vector<vector<int> > &matrix)
{
        
     reverse(matrix.begin(), matrix.end());
     for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
     }
}

//方法3
void rotate(vector<vector<int>>& matrix) 
{
        
        int n =matrix.size();
        for (int i=0; i<n/2; ++i)
        {
            for (int j=i; j<n-1-i; ++j)
            {
                int z = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = z;
            }
        }
}