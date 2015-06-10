Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)



//类似 two sum
//要注意 去重复元素的边界问题，这个纠结了好久
vector<vector<int>> threeSum(vector<int>& nums) 
{
        
        vector<vector<int>> result;
        
        sort(nums.begin(),nums.end());
        
        for (int i = 0; i < nums.size(); i++) 
        {
            int target = -nums[i];
            
            int front = i+1;
            int end = nums.size()-1;
            while(front<end)
            {
                int sum = nums[front]+nums[end];
                if(sum ==target)
                {
                   vector<int> temp;
                   temp.push_back(nums[i]);
                   temp.push_back(nums[front]);
                   temp.push_back(nums[end]);
                   
                   result.push_back(temp);
                   front++;
                   
                   
                }else if(sum >target)
                {
                    end--;
                }else{
                    front++;
                }
                
                while(front<end && front>i+1 && nums[front-1] == nums[front]) front++;
                while(front<end && end<nums.size()-1 && nums[end+1] == nums[end]) end--;
            }
            
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                    i++;
        }
        
        return result;
}