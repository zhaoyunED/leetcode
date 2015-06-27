You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



//˵�Ƕ���
//��ʵ ���� ��һ���� �Შ������f(n) ���õݹ� ���ߵ����ķ���
//�����ķ������
int climbStairs(int n)
{
        if(n==1) return 1;
        if(n==2) return 2;
        int pre1 =1;
        int pre2 =2;
        int result =0;
        
        for(int i=3; i<=n;i++)
        {
            result = pre1+pre2;
            pre1= pre2;
            pre2 =result;
        }
        
        return result;
}