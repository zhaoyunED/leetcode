Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.


//典型的DP题目
//V[i][j]  表示 s1(i,n1)与s2(j,n2) 能否拼装成 s3(i+j,n3)
//V[i][j] = ((s1[i] == s3[i+j]) && V[i+1][j]) | ((s2[j] == s3[i+j]) && V[i][j+1]);
bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1+n2 != n3) return false;

        vector<vector<bool>> V(n1+1, vector<bool>(n2+1, false));
        
        V[n1][n2] =true;
        
        for(int i=n1-1 ; i>=0 ;i--)
            V[i][n2] = V[i+1][n2] && (s3[n2+i] == s1[i]) ;
        
        for(int i= n2-1 ;i>=0;i--)
            V[n1][i] = V[n1][i+1] && (s3[n1+i] == s2[i]);
            
        for(int i=n1-1;i>=0;i--)
            for(int j=n2-1;j>=0;j--)
            {
                V[i][j] = ((s1[i] == s3[i+j]) && V[i+1][j]) | ((s2[j] == s3[i+j]) && V[i][j+1]);
            }
        
        return V[0][0];
    }