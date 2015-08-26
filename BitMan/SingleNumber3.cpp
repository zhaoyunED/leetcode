Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

//先求得 a^b
// 找到a与b最低不相同的位
// 按照这位 值 的0或者1 分成两组 
//异或 一遍 即可求得a与b
vector<int> singleNumber(vector<int>& nums) {
         int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> rets(2, 0);
        for (int num : nums)
            rets[!(num & diff)] ^= num;
        return rets;
    }