There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).


//不断筛掉 不符合的区域段
double findKth(vector<int>& nums1, int s1,int e1,vector<int>& nums2, int s2, int e2, int k)  
{
       if(e1-s1 > e2-s2) //总是保持nums1的区域段比nums2的区域段小
        return findKth(nums2,s2,e2,nums1,s1,e1,k);
       if(e1<s1)
            return nums2[s2+k-1];
       if(k==1)
            return min(nums1[s1],nums2[s2]);
        
       int i= min(k/2,e1-s1+1);
       int j= k-i;
       if(nums1[s1+i-1]<nums2[s2+j-1])
            return findKth(nums1,s1+i,e1,nums2,s2,e2,k-i);
       else if(nums1[s1+i-1]>nums2[s2+j-1])
            return findKth(nums1,s1,e1,nums2,s2+j,e2,k-j);
       else 
            return nums1[s1+i-1];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
         int m=nums1.size();
         int n=nums2.size();
         
         int total =m+n;
         if(total & 0x1)
            return findKth(nums1,0,m-1,nums2,0,n-1,total/2+1);
         else
         {
			 double r1= findKth(nums1,0,m-1,nums2,0,n-1,total/2);
			 double r2= findKth(nums1,0,m-1,nums2,0,n-1,total/2+1);
             return (r1+r2)/2.0;
         }
}