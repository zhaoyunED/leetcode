Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.



//同理Search in Rotate array 2
//只有 mid left right 都相等的时候 才无法判断 left ++
int findMin(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;
        while(left < right)
        {
            if(nums[left] < nums[right])
                return nums[left];
            int mid = left + (right -left)/2;
            
            if(nums[mid] >nums[left])
                left = mid+1;
            else if( nums[mid] <nums[left])
                right = mid;
            else if(nums[right] != nums[mid])//[mid] == [left]
                left = mid+1;
            else //都相等
                left++;
        }
        
        return nums[left];
}