
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2


//利用hash来保存 对应的index
vector<int> twoSum(vector<int>& nums, int target) 
{
        vector<int> result;
        unordered_map<int,int> hash;
        
        for(int i=0;i<nums.size();i++)
        {
            int findN = target -nums[i];
            if(hash.find(findN) != hash.end())
            {
                result.push_back(hash[findN]);
                result.push_back(i+1);
                return result;
            }
            hash[nums[i]] = i+1;
        }
        
        return result;
}