Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

//KMP算法 将s反转之后拼到后面，算最后的字符串中 既是前缀子串又是后缀子串中的最长串
//即是 最长的不需要变动的部分
string shortestPalindrome(string s)
{
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
}




//方法2 Manacher's 算法
//已总结过
public:
    string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret(2*n+3, '#');
  ret[0] = '^';ret[2*n+1] = '$';
  for (int i = 1; i <= n; i++)  ret[2*i]=s[i-1];

  return ret;
}

string shortestPalindrome(string s) {

  int len = s.size();
  if(len<=1) return s;
  string T = preProcess(s);
  const int n = T.length();
  int P[n], i_mirror;
  int C = 0, R = 0;

  for (int i = 1; i < n-1; i++) {
    i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Just changed this part, 
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (1==i-P[i]) maxLen = P[i];
  }
  string temp = s.substr(maxLen);
  reverse(temp.begin(),temp.end());
  return temp+s;

}