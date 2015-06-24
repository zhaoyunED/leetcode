
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.






//基本都是贪心的思想
//方法1
 bool canJump(int A[], int n) {
        if(n==0||n==1){  
            return true;  
        }  
        int maxstep=A[0];  
        for(int i=1;i<n;i++){  
            if(maxstep==0) return false;  
            maxstep--;  
            if(maxstep<A[i]){  
                maxstep=A[i];  
            }  
            if(maxstep+i>=n-1){  
                return true;  
            }  
        }
    }

//方法2

bool canJump(vector<int>& nums) 
{
        int truepos=nums.size()-1;//the lowest starting point that you can reach the end 
        for(int i=nums.size()-2;i>=0;i--)
            truepos=(i+nums[i])>=truepos?i:truepos;
        return(truepos==0); 
}

//方法3

bool canJump(vector<int>& nums)
{
        if(nums.size()<=1) return true;

        int maxreach =0;
        for(int i=0;i<nums.size() && maxreach<nums.size()-1 && i<=maxreach;i++)
        {
            maxreach =max(i+nums[i],maxreach);
        }
        
        if(maxreach <nums.size()-1)
            return false;
        else
            return true;
}

