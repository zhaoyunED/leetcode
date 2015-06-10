
Implement pow(x, n).

// 利用的是 蒙哥马利快速模乘算法 
// 将 幂 转换为 二进制 
 double myPow(double x, int n) {

	if(n<0)
	 {
		if(n == INT_MIN)
			return 1.0/(myPow(x,INT_MAX))*x;
		else
			return 1.0/myPow(x,-n);
	 }

	 if(n==0)
		 return 1.0;

	 double result =1.0;
	 double ass =1.0;

	 for( ;n>0;n >>= 1)
	 {
		if(n & 0x1)
			result *=ass;
		ass *=ass;
	 }
	 return result;
 }