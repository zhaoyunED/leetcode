Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.



//可以扩展到 duplicate K 的一般情况
int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length<=2)
            return length;
        int id=1;
        int count=1;
        for(int i=1;i<length;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[id++] = nums[i];
                count=1;
            }else if(count<2)
            {
                count++;
                nums[id++] = nums[i];
            }
        }
        
        return id;
    }