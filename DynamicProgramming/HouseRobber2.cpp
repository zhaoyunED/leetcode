After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.



//方法1 O（1）空间 O(n)时间
//构成环的环的话考虑两种情况，一种选最后一个；一种不选最后一个
int rob(vector<int>& nums)
{
       if(nums.size() == 0)
        return 0;
        if(nums.size() == 1)
            return nums[0];
    
        int pre2=0,pre1 = 0, cur1 = 0;
        for(int i = 0; i < nums.size() - 1; ++ i)
        {
            pre2 = pre1;
            pre1 = cur1;
            cur1 = max(pre2 + nums[i], pre1);
        }
    
        int pre3=0,pre4 = 0, cur2 = 0;
        for(int i = 1; i < nums.size(); ++ i)
        {
            pre4 = pre3;
            pre3 = cur2;
            cur2 = max(pre4 + nums[i], pre3);
        }
    
        return max(cur1, cur2);
 }

 //方法2
 //感觉写的比较简练 思路是一样的
 private int rob(int[] num, int lo, int hi) {
    int include = 0, exclude = 0;
    for (int j = lo; j <= hi; j++) {
        int i = include, e = exclude;
        include = e + num[j];
        exclude = Math.max(e, i);
    }
    return Math.max(include, exclude);
}

public int rob(int[] nums) {
    if (nums.length == 1) return nums[0];
    return Math.max(rob(nums, 0, nums.length - 2), rob(nums, 1, nums.length - 1));
}

