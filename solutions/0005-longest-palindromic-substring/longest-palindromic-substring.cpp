// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        int m=-1,rj=0,rk=0;
        auto findpal = [&](int j,int k){
            while(j>=0 and k<size(s) and s[j]==s[k]){
                if(k-j>m){m=k-j;rj=j;rk=k;}
                --j;++k;
            }
        };
        for(int i=0;i<size(s);++i){
            findpal(i,i+1);
            findpal(i,i);
        }
        return s.substr(rj,rk-rj+1);
    }
};
