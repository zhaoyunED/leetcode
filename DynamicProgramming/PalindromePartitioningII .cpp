Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.


//dp
//����Ҫ���� ����һ�� dp���� 
//�� ͬһ��˫��forѭ���� �Ϳ��� ��� ��Сֵ �� �Ƿ��� �����Ӵ�
int minCut(string s)
{
        if(s.size()<=0)
            return 0;
        
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),false));
        vector<int> count(s.size(),INT_MAX);
        int min= INT_MAX;
        
        for(int i=0;i<s.size();i++)
            for(int j=0;j<=i;j++)
            {
                if(i ==j || ( (s[i] == s[j]) && (i==j+1 || dp[i-1][j+1]) ))
                {
                    dp[i][j]= true;
                    int tempcount = j==0? 1: count[j-1]+1;
                    if(tempcount< count[i])
                        count[i] = tempcount;
                }
            }
        return count[s.size()-1]-1;
}