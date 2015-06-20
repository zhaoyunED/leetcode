Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

//����1
int search(vector<int>& nums, int target) 
{
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) { //����Ҳ�� ���ֲ��� ����Ҫ��������ж� ����ͼ �ͱȽ��������
            int mid =lo+(hi-lo)/2;
            if (nums[mid] == target) return mid;
    
            if (nums[lo] <= nums[mid]) { //��Ϊrotatded�� ���Բ�һ���ĸ���
                if (target >= nums[lo] && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return nums[lo] == target ? lo : -1;
}

//����2
int search(vector<int>& nums, int target) 
{
        int lo=0,hi=nums.size()-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid;
        }//���ҵ��յ㣬Ȼ�����ô�ͳ�Ķ��ֲ��ҷ���
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=nums.size()-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int realmid=(mid+rot)%nums.size();
            if(nums[realmid]==target)return realmid;
            if(nums[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
}