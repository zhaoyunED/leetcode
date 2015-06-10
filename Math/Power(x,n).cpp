
Implement pow(x, n).

// ���õ��� �ɸ���������ģ���㷨 
// �� �� ת��Ϊ ������ 
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