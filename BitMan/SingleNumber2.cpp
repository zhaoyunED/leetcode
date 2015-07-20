Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


int singleNumber(vector<int>& nums)
{
        int three=0,two=0,one=0;
        
        for(auto num:nums)
        {
            three = two&num;
            two = two | one&num;
            one = one | num;
            
            two = two & ~three;
            one = one & ~three;
            
        }
        return one;
}