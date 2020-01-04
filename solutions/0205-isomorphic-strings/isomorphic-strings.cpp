// Given two strings s and t, determine if they are isomorphic.
//
// Two strings are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
// Example 1:
//
//
// Input: s = "egg", t = "add"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
//
//
// Input: s = "paper", t = "title"
// Output: true
//
// Note:
// You may assume both s and t have the same length.
//


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(size(s)!=size(t))return false;
        vector<bool> o(size(s),false);
        map<char,char> ms;
        set<char> st;
        for(int i=0;i<size(s);++i){
            const char a = s[i],b=t[i];
            if(ms.count(a)){
                if(ms[a]!=b)return false;
                else continue;
            }
            if(st.count(b)) return false;
            st.insert(b);
            ms[a]=b;
        }
        return true;
    }
};
