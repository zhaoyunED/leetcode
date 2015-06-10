
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


//方法1
string convert(string s, int numRows) 
{
        if (s == "" || numRows == 1) return s;
        vector<string> vecstr(numRows);
        string res;
        int bounce = 0, direct = 1;
        for (int i = 0; i<=s.size()-1; ++i) {
            vecstr[bounce].push_back(s[i]);
            if (bounce == numRows-1) direct = -1;
            else if (bounce == 0) direct = 1;
            bounce += direct;
        }
        for (int i = 0; i<=numRows-1; ++i) res += vecstr[i];
        return res;
}

//方法2

///nRows:2
///1,   3,  5   step: 2
///2,   4,  6   step: 2
///
///nRows:3
///1,       5,      9   step:   4
///2,   4,  6,  8,  10  step:2      2
///3,       7,      11  step:   4
///
///nRows:4
///1,           7,          13  step:   6
///2,       6,  8,      12, 14  step:4      2
///3,   5       9,  11,     15  step:2      4
///4,           10,         16  step:   6
///
///nRows:5
///1,               9,              17  step:   8
///2,           8,  10,         16, 18  step:6      2
///3,       7,      11,     15,     19  step:4      4
///4,   6,          12, 14,         20  step:2      6
///5,               13,             21  step:    8
///
class Solution {
public:
    string convert(string s, int nRows) {
        size_t len = s.size();
        if (nRows <= 1 || nRows >= len) { // Handle Special Case.
            return s;
        }
        const char* str = s.c_str();
        string* retval = new string();
        size_t maxStep = (nRows - 1) * 2;
        for (int r = 0; r < nRows; ++r) {
            size_t pos = r;
            if (0 == r || nRows - 1 == r) { // First Row And Last Row.
                while (pos < len) {
                    retval->push_back(str[pos]);
                    pos += maxStep;
                }
            } else { // Rows In The Middle.
                size_t step = 2 * r;
                while (pos < len) {
                    retval->push_back(str[pos]);
                    step = maxStep - step;
                    pos += step;
                }
            }
        }
        return *retval;
    }
};