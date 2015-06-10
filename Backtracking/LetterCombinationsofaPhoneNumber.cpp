Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.






//方法1
vector<string> letterCombinations(string digits) 
{
        vector<string> res;
        if(digits.size()==0) return res;
        string local;
        vector<vector<char>> table(2,vector<char>());
        table.push_back(vector<char>{'a','b','c'}); // index 2
        table.push_back(vector<char>{'d','e','f'}); // 3
        table.push_back(vector<char>{'g','h','i'});
        table.push_back(vector<char>{'j','k','l'}); // 5
        table.push_back(vector<char>{'m','n','o'});
        table.push_back(vector<char>{'p','q','r','s'}); // 7
        table.push_back(vector<char>{'t','u','v'});
        table.push_back(vector<char>{'w','x','y','z'}); // 9

        backtracking(table,res,local,0,digits);
        return res;
}
//典型的backtracking方式
void backtracking(const vector<vector<char>>& table, vector<string>& res, string& local, int index, const string& digits) 
{
        if(index==digits.size())
            res.push_back(local);
        else
            for(int i=0;i<table[digits[index]-'0'].size();i++) {
                local.push_back(table[digits[index]-'0'][i]);
                backtracking(table, res, local, index+1, digits);
                local.pop_back();
            }
 }





//方法2 简单粗暴的dfs 其实也是包含回溯 只不过形参是 非引用 消耗的内存多一些
 private:
    map<char,vector<char>> dict;
    vector<string> ret;
public:

      void createDict()
      {
          dict.clear();
          dict['2'].push_back('a');
         dict['2'].push_back('b');
         dict['2'].push_back('c');
         dict['3'].push_back('d');
         dict['3'].push_back('e');
         dict['3'].push_back('f');
         dict['4'].push_back('g');
         dict['4'].push_back('h');
         dict['4'].push_back('i');
         dict['5'].push_back('j');
         dict['5'].push_back('k');
         dict['5'].push_back('l');
         dict['6'].push_back('m');
         dict['6'].push_back('n');
         dict['6'].push_back('o');
         dict['7'].push_back('p');
         dict['7'].push_back('q');
         dict['7'].push_back('r');
         dict['7'].push_back('s');
         dict['8'].push_back('t');
         dict['8'].push_back('u');
         dict['8'].push_back('v');
         dict['9'].push_back('w');
         dict['9'].push_back('x');
         dict['9'].push_back('y');
         dict['9'].push_back('z');
     }
     
void dfs(int dep,int maxDep, string &s, string ans)
{
    if(dep == maxDep)
    {
        ret.push_back(ans);
       return;
    }
    for(int i=0;i<dict[s[dep]].size();i++)
        dfs(dep+1,maxDep,s,ans+dict[s[dep]][i]);
}
     
vector<string> letterCombinations(string digits) 
{
        if(digits =="" || digits.size()==0)
            return ret;
        ret.clear();
        createDict();
        dfs(0,digits.size(),digits,"");
        return ret;
 }