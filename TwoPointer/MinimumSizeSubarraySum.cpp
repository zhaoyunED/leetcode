Given an array of n positive integers and a positive integer s, 
find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).



//two pointer 
int minSubArrayLen(int s, vector<int>& nums)
{
        int start =0;
        int end =0;
        
        int minS=0;
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            end =i;
            sum+= nums[i];
            if(sum >= s)
            {
                while(start <= end && sum>=s)
                {
                    if(minS == 0 ||  (end -start+1)<minS )
                        minS = end -start+1;
                    start++;
                    sum -= nums[start-1];
                }
            }
        }
        
        return minS;
}


//分之方法
int minSubArrayLen(int s, vector<int>& nums)
{
        return findMinArray(s,0,nums.size()-1,nums);
}
    
int findMinArray(int s,int start,int end,vector<int>& nums)
{
        if(start >end) return 0;
        int mid = start + (end -start)/2;
        int minLeft = findMinArray(s,start,mid-1,nums);
        int minRight = findMinArray(s,mid+1,end,nums);
        int minS=0;
        
        minS=min(minLeft,minRight);
        if(minLeft ==0)
            minS = minRight;
        if(minRight ==0)
            minS = minLeft;
         
         
         
         
        int indexleft = mid -minS+1;
        int indexright =mid+minS-1;
         //panduan zhongjian quyu
         if(minS == 0)
        {
            indexleft = start;
            indexright = end;
        }
        
        
       
        int si= indexleft; int r = indexleft;
        int sum =0;
        for(int i=indexleft;i<=indexright;i++)
        {
            r = i;
            sum+= nums[i];
            if(sum>= s)
            {
                 while( si<=r && sum >=s )
                {
					if((minS ==0 || (r-si+1) < minS))
							 minS = r-si+1;
                    si++;
                    sum -= nums[si-1];
                }
            }
        }
        
        return minS;
}