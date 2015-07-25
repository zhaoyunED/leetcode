Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the difference between i and j is at most k.



//距离为k之内的 数据不允许重复
//大于K之后把之前的数据从set里面删除掉
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
        unordered_set<int> s;

       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;

       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }

       return false;
}