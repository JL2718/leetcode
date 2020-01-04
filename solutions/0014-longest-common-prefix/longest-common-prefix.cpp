// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
//
// Input: ["flower","flow","flight"]
// Output: "fl"
//
//
// Example 2:
//
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
// Note:
//
// All given inputs are in lowercase letters a-z.
//


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(not strs.size()) return string("");
        if(strs.size()==1) return strs[0];
        auto[a,b]= minmax_element(strs.begin(),strs.end());
        int i=0;while((i!=min((*a).size(),(*b).size())) and (*a)[i]==(*b)[i])i++;
        return (*a).substr(0,i);
    }
};
