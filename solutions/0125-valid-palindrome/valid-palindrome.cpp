// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


static int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        auto p = begin(s);
        auto q = end(s)-1;
        while(q-p>0){
            while(p<q and !isalnum(*p))++p;
            while(q>p and !isalnum(*q))--q;
            if(tolower(*p)!=tolower(*q))return false;
            ++p;--q;
        }
        return true;
    }
};
