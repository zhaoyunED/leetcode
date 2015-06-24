Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

//����1 ÿ���ҵ�i�㷶Χ�� �ܴﵽ��Զ������Ǹ�index
int jump(vector<int>& nums) 
{
        int n = nums.size();
        if(n ==1) return 0;
        int ret=0;
        int j=1;
        int max_index=0;
        for(int i=0;i<n-1 && i+nums[i] <n-1;)
        {
            max_index =j;
            for(;j<=i+nums[i];j++)
            {
                max_index = max_index+nums[max_index] > j+nums[j] ? max_index:j;
            }
            
            i= max_index;
            ret++;
        }
        
        return ++ret;
}

//������  ÿ���ж�һ���µ�index�Ƿ��� curRch��Χ��
//curRch��ʾÿһ�������ߵ�����Զ�ĵط�
int jump(int A[], int n)
{
         int ret = 0;
        int curMax = 0;
        int curRch = 0;
        for(int i = 0; i < n; i ++)
        {
            if(curRch < i)
            {
                ret ++;
                curRch = curMax;
            }
            curMax = max(curMax, A[i]+i);
        }
        return ret;
}
