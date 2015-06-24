Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].




//典型的DFS加回溯 的题目
vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        if (num.size() == 0)
            return result;
        //sort(num.begin(), num.end()); 不需要排序
        permute(num, 0, result);
        return result;
    }
    
    void permute(vector<int> &num, size_t start, vector<vector<int>> &result)
    {
        if(start == num.size())
        {
            result.push_back(num);
            return;
        }
        
        for(size_t i = start; i < num.size(); i++)
        {
            swap(num[i],num[start]);
            permute(num,start+1,result);
            swap(num[i],num[start]);
        }
    }