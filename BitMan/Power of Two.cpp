Given an integer, write a function to determine if it is a power of two.

//类似求 二进制中1的个数
bool isPowerOfTwo(int n)
{
        if(n == INT_MIN)
            return false;
        int res=0;
        while(n)
        {
            n = n&(n-1);
            res++;
        }
        
        return res == 1;
}