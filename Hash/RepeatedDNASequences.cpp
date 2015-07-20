All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

//We can simply use s[i] & 7 to get the last digit which are just the last 3 bits
//A:01000001
//T:01010100
//C:01000011
//G:01000111
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    for (int t = 0, i = 0; i < s.size(); i++)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
            r.push_back(s.substr(i - 9, 10));
    return r;
}