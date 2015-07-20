Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.


//方法1
//exactly O(n)time O(1) space
void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)return;
        k = k % n;
    
        //initialize
        int i = 0;
        int nowIndex = 0;
        int tmp = nums[0],stmp;
    
        //exactly n steps, n times loop
        for(int j = 0; j < n; j++)
        {
            //next index to exchange
            nowIndex = (nowIndex + k) % n;
    
            //exchange
            stmp = nums[nowIndex];
            nums[nowIndex] = tmp;
            tmp = stmp;
    
            //finish a circle,move to another circle
            if(nowIndex == i)
            {
                nowIndex = ++i;
                tmp = nums[nowIndex];
            }
        }
}

//方法2
void rotate(vector<int>& nums, int k)
{
        if(nums.size()<=1 || k<0)
            return;
        k = k%nums.size();
        
        reverse(nums.begin(),nums.begin()+nums.size()-k);
        
        reverse(nums.begin()+nums.size()-k,nums.end());
        
        reverse(nums.begin(),nums.end());
}
