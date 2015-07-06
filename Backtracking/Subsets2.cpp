Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int> > result;
        if(nums.size()<=0)
            return result;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        getSubsets(result,nums,0,temp);
        
        return result;
    }
    
void getSubsets(vector<vector<int>> &result,vector<int>& nums,int start,vector<int>& temp)
{
         result.push_back(temp);
        
         for(int i=start;i<nums.size();i++)
         {
                 if(i>start && nums[i-1] == nums[i]) continue;
                 temp.push_back(nums[i]);
                 getSubsets(result,nums, i + 1,temp);
                 temp.pop_back();
         }
}