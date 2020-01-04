// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
// This is case sensitive, for example "Aa" is not considered a palindrome here.
//
// Note:
// Assume the length of given string will not exceed 1,010.
//
//
// Example: 
//
// Input:
// "abccccdd"
//
// Output:
// 7
//
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
//
//


class Solution {
public:
    int longestPalindrome(string s) {
        int sc[128]={0};
        int q=0,r=0;
        for(char c:s)sc[c]++;
        for(int c:sc){q+=c/2;r+=c%2;}
        return 2*q+(r?1:0);
    }
};
