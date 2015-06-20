Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].






vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if(n <= 0)
            return res;

        int leftIndex = lSearch(A, n, target);
        int rightIndex = rSearch(A, n, target);

        res.push_back(leftIndex);
        res.push_back(rightIndex);
        return res;
    }
    
    int lSearch(int A[], int n, int target) {
        int low = 0, high = n-1;
        while(low <= high) { // q1
            int mid = low+(high-low)/2;
            if(A[mid] < target) { // q2
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        if(A[low] != target)
            return -1;
        return low; // q3   若只有一个元素 最终A[low]= target and low>high
    }
    
    int rSearch(int A[], int n, int target) {
        int low = 0, high = n-1;
        while(low <= high) { // q1
            int mid = low+(high-low)/2;
            if(A[mid] > target) { // q2
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        if(A[high] != target)
            return -1;
        return high; // q3 若只有一个元素 最终A[high]= target and low>high 返回high
    }