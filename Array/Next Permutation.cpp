Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1


//�ٸ����ӿ��ܻ���������
void nextPermutation(vector<int>& nums) 
{
        int end = nums.size()-1;
        int pivot = end;
        while(pivot>0)
        {
            if(nums[pivot] > nums[pivot-1] )  //�Ӻ��ҵ�һ�����������
                break;
            pivot--;
        }
        
        if(pivot>0)
        {
            pivot--;
            int large = end;
            while(nums[large] <= nums[pivot]) large--;  //�ҵ���һ����nums[pivot]�����
            swap(nums[large],nums[pivot]);
            reverse(nums.begin()+pivot+1,nums.end());
        }else
        {
            reverse(nums.begin(),nums.end());
        }
}