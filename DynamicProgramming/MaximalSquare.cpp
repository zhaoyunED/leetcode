Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.


int maximalSquare(vector<vector<char>>& matrix) {
        int nr = matrix.size(); if (nr == 0) return 0;
        int nc = matrix[0].size(); if (nc == 0) return 0;
    
        vector<int> dp(nc+1, 0);
    
        int maxsize = 0;
    
        int last_topleft = 0;  // This is 'pre[i-1]' for the current element
    
        for (int ir = 1; ir <= nr; ++ir) {
            for (int ic = 1; ic <= nc; ++ic) {
                int temp = dp[ic];      // This is 'pre[i-1]' for the next element                
                 if (matrix[ir-1][ic-1] == '0') dp[ic] = 0; 
                else {
                    dp[ic] = min(min(dp[ic], dp[ic-1]), last_topleft) + 1;
                    maxsize = max(maxsize, dp[ic]);
                }
                last_topleft = temp;  // update 'pre[i-1]'
            }
        }
        return maxsize * maxsize;
    }