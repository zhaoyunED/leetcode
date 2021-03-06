Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]


// 稍微复杂点的深度搜索加回溯
vector<vector<int>> combinationSum3(int k, int n) 
{
        vector<vector<int>> result;
        vector<int> temp;
        if(k<0 || n<0 || k>n)
            return result;
        combination(result,n,temp,1,k);
        return result;
}
    
void combination(vector<vector<int>>& result,int sum,vector<int>& tempRes,int start,int k)
{
        if(sum == 0 && k==0)
        {
            result.push_back(tempRes);
        }else if(k>0)
        {
            for(int i=start; i<=9 && sum >= i * k + k * (k - 1) / 2; i++)
            {
                    tempRes.push_back(i);
                    combination(result,sum-i,tempRes,i+1,k-1); //important
                    tempRes.pop_back();
            }
        }
}