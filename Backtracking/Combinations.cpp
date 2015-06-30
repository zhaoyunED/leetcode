Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]



//方法1 dfs加 backtracking
vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        if(k>n)
            return result;
        getcombine(n,k,result,temp,1);
        
        return result;
    }
    
void getcombine(int n, int k,vector<vector<int>> &result,vector<int> temp,int cur)
 {
        if(temp.size() == k)
        {
            result.push_back(temp);
        }else if(n-cur+1+temp.size() >=k) //进行减枝
        {
           for(int i=cur ;i<=n ;i++)
           {
               temp.push_back(i);
               getcombine(n,k,result,temp,i+1);
               temp.pop_back();
           }
        }
        
}

//方法2   C(n,k) = C(n-1, k-1) U n + C(n-1,k)  类似动态规划的方法
vector<vector<int> > combine(int n, int k) 
{

        vector<vector<int> > result;
        if (n < 1 || k <1 || k > n)
        {
            return result;
        }

        result = combine(n-1, k-1);

        if(result.empty())
        {
            result.push_back(vector<int>{n});
        }
        else
        {
            for (vector<vector<int> >::iterator it = result.begin();
                    it!= result.end(); it++)
            {
                it->push_back(n);
            }
        }
        vector<vector<int> > result2 = combine(n-1, k);
        result. insert(result.end(), result2.begin(), result2.end());

        return result;
}