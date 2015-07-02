The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.



//����1
vector<int> grayCode(int n) {
        int size = 1<<n;
        vector<int> grayCodes;
        grayCodes.resize(size);

        for (int i = 0; i < size; i++){
            int gCode = i ^ i>>1;
            grayCodes[i] = gCode;
        }

        return grayCodes;
    }


//����2
vector<int> grayCode(int n) {
        vector<int> result(1, 0);        
    for (int i = 0; i < n; i++) {
        int curCount = result.size();
        // push back all element in result in reverse order
        while (curCount) {
            curCount--;
            int curNum = result[curCount];
            curNum += (1<<i);
            result.push_back(curNum);
        } 
    }
    return result;
}