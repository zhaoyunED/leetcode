Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.



//���͵�two pointer ��Ŀ �� removeDuplicateElementsһ����˼·
int removeElement(vector<int>& nums, int val) 
{
    int index=0;//����ά��ʵ�ʵ�Ԫ����Ŀ
    for(int i=0;i<nums.size();i++)
       if(nums[i] != val)
          nums[index++] = nums[i];
    return index;
}