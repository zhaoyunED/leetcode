Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

// Worst case O(n)
bool search(vector<int>& A, int key) {
        
        int l = 0, r = A.size()-1;
        
        while (l <= r) {
            int m = l + (r - l)/2;
            if (A[m] == key) return true; //return m in Search in Rotated Array I
            if (A[l] < A[m]) { //left half is sorted
                if (A[l] <= key && key < A[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else if (A[l] > A[m]) { //right half is sorted
                if (A[m] < key && key <= A[r])
                    l = m + 1;
                else
                    r = m - 1;
            } else if(A[m] != A[r])
            {
                l=m+1;
            }else 
                l++;
        }
        return false;
}


//½âÊÍ
Yes, when there could be duplicates in the array, the worst case is O(n).

To explain why, consider this sorted array 1111115, which is rotated to 1151111.

Assume left = 0 and mid = 3, and the target we want to search for is 5. 
Therefore, the condition A[left] == A[mid] holds true, which leaves us with only two possibilities:

All numbers between A[left] and A[right] are all 1's.
Different numbers (including our target) may exist between A[left] and A[right].
As we cannot determine which of the above is true, 
the best we can do is to move left one step to the right and repeat the process again. 
Therefore, we are able to construct a worst case input which runs in O(n), for example: the input 11111111...115.

Besides,Basically, whenever you see A[m] == A[l] && A[m] != A[h], you know A[l] to A[m] must be identical, 
so you only need to search the right half. So is the case of A[m] != A[l] && A[m] == A[h]. 
The only case you need to search both half is when A[m] == A[l] == A[h].