Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321


Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.



//方法1
int reverse(int x) 
{
    long long val = 0;
    do 
    {
        val = val * 10 + x % 10;
        x /= 10;
    } while (x);

    return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}


//方法二
int reverse(int x) 
{
     int sign = 1;
     if (x<0) 
	 {
            sign = -1;
            x = -x; // make it positive
            if (x<0) // x was numeric_limits<int>::min() -2^31
                return 0;
     }
        
     int res = 0;
     int compare = numeric_limits<int>::max() / 10;
     while (x) 
	 {
            if (res > compare)
                return 0;
            res = res*10 + x% 10;
            x /= 10;
     }

     return res*sign;
}


