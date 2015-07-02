Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.





//DP 方法 
This solution is so clever that I think so hard to understand it. height 
counts the number of successive '1's above (plus the current one). 
The value of left & right means the boundaries of the rectangle which contains the current point with a 
height of value height.
int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()) return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int left[n], right[n], height[n];
    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
    int maxA = 0;
    for(int i=0; i<m; i++) {
        int cur_left=0, cur_right=n; 
        for(int j=0; j<n; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++; 
            else height[j]=0;
        }
        for(int j=0; j<n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(int j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
            else {right[j]=n; cur_right=j;}    
        }
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    return maxA;
}


// stack 方法 和 求histogram的方法一样
//O(n)的空间复杂度
int maximalRectangle(vector<vector<char>>& matrix)
{
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
        return 0;

        int m = matrix.size();
        int n = matrix[0].size()+1; //最后一个元素是0 方便让所有的元素出栈
        int h = 0, w = 0, ret = 0;
        vector<int> height(n, 0);
    
        for (int i = 0; i < m; ++i) {
            stack<int> s;
            for(int j=0;j<n;j++)
            {
                if(j<n-1)
                {
                    if(matrix[i][j] == '1')
                        height[j] ++;
                    else
                        height[j]=0;
                }
                
                
                while(!s.empty() && height[s.top()]>= height[j]) //计算所有高于最低点的可能的面积 但最终也计算了包含最低点的面积
                {
                    int idx = s.top();
                    s.pop();
                    int width = s.empty()? j: j-1-s.top();
                    ret = max(ret,width*height[idx]);
                }
                
                s.push(j);
            }
        }
    
        return ret;
}