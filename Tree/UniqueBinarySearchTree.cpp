Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


//动态规划方法

int numTrees(int n)
{
      int dp[n+1];
      dp[0] = dp[1] = 1;
      for (int i=2; i<=n; i++)
      {
            dp[i] = 0;
            for (int j=1; j<=i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
            }
      }
      return dp[n];
}






//卡特兰数

int numTrees(int n) {
    //cantalan树
    //C(2n,n)/(n+1)
    long long ans =1;
    for(int i=n+1;i<=2*n;i++){
        ans = ans*i/(i-n);
    }
    return ans/(n+1);
}