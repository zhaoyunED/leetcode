Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.




//类似快速排序的思想
int partition(vector<int>& nums, int i, int j)
    {
        if (i == j) return i;

        int pivot = nums[i];
        std::swap(nums[i], nums[j]);

        int i0 = i;
        for(int k = i; k < j; k ++)
        {
            if(nums[k] <= pivot)
            {
                std::swap(nums[k], nums[i0 ++]);
            }
        }
        std::swap(nums[i0], nums[j]);
        return i0;
    }
    
    int findKthEle(vector<int>& nums, int i, int j,int k)
    {
        int index = partition(nums,i,j);
        int length = j-index+1;
        if(length == k)
            return nums[index];
        else if(length > k)
            return findKthEle(nums,index+1,j,k);
        else if(length <k)
            return findKthEle(nums,i,index-1,k-length);
    }
    
int findKthLargest(vector<int>& nums, int k) 
{
    size_t len = nums.size();

    return findKthEle(nums,0,len-1,k);
}