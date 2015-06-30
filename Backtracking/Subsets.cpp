Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]




//方法1 DFS+BACKTRACKING
 vector<vector<int> > subsets(vector<int> &S) 
    {
        
        vector<vector<int> > result;
        if(S.size()<=0)
            return result;
        sort(S.begin(), S.end());
        result.clear();
        vector<int> a;
        dfs(result, S,  a, 0);
         
        return result;
    }

void dfs(vector<vector<int> > &result,vector<int> &vec, vector<int> &a, int start)
{
        
        result.push_back(a);
        
        for(int i=start;i<vec.size();i++)
        {
             a.push_back(vec[i]);
             dfs(result,vec, a, i + 1);
             a.pop_back();
        }
}


//方法2 ITERATIVE 方法

vector<vector<int> > subsets(vector<int> &S)
{
    vector<vector<int> > res(1, vector<int>());
    sort(S.begin(), S.end());

    for (int i = 0; i < S.size(); i++) {
        int n = res.size();
        for (int j = 0; j < n; j++) {
            res.push_back(res[j]);
            res.back().push_back(S[i]);
        }
    }

    return res;
  }

//位操作

vector<vector<int> > subsets(vector<int> &S)
{
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
}