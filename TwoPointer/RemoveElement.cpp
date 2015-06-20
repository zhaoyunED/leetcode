Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.



//典型的two pointer 题目 和 removeDuplicateElements一样的思路
int removeElement(vector<int>& nums, int val) 
{
    int index=0;//用来维护实际的元素数目
    for(int i=0;i<nums.size();i++)
       if(nums[i] != val)
          nums[index++] = nums[i];
    return index;
}