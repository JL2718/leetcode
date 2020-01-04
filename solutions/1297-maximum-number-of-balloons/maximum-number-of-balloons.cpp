// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
//
// You can use each character in text at most once. Return the maximum number of instances that can be formed.
//
//  
// Example 1:
//
//
//
//
// Input: text = "nlaebolko"
// Output: 1
//
//
// Example 2:
//
//
//
//
// Input: text = "loonbalxballpoon"
// Output: 2
//
//
// Example 3:
//
//
// Input: text = "leetcode"
// Output: 0
//
//
//  
// Constraints:
//
//
// 	1 <= text.length <= 10^4
// 	text consists of lower case English letters only.
//


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        multiset<char> S(begin(text),end(text));
        for(int i=0;true;++i)
            for(char c:string("balloon")){
                auto it=S.find(c);
                if(it!=end(S))
                    S.erase(it);
                else return i;
            }
        return 99;   
    }
};
