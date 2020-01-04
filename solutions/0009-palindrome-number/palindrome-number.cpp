// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
// Example 1:
//
//
// Input: 121
// Output: true
//
//
// Example 2:
//
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
//
// Example 3:
//
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
//
// Follow up:
//
// Coud you solve it without converting the integer to a string?
//


class Solution {
public:
    bool isPalindrome(int x) {
        if(not x)return true;
        if(x<0 or x%10==0)return false;
        int r=0;
        while(r<x){
            r=10*r+x%10;x/=10;
        }
        return x==r or x==r/10;
    }
};
