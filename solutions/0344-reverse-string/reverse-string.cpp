// Write a function that reverses a string. The input string is given as an array of characters char[].
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// You may assume all the characters consist of printable ascii characters.
//
//  
//
//
// Example 1:
//
//
// Input: ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
//
//
//
// Example 2:
//
//
// Input: ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
//
//
//


class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.empty())return;
        auto it=begin(s);
        auto jt=rbegin(s);
        while(it<jt.base()-1)swap(*it++,*jt++);
    }
};
