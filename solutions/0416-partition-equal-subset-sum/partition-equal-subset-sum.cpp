// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
// Note:
//
//
// 	Each of the array element will not exceed 100.
// 	The array size will not exceed 200.
//
//
//  
//
// Example 1:
//
//
// Input: [1, 5, 11, 5]
//
// Output: true
//
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
//  
//
// Example 2:
//
//
// Input: [1, 2, 3, 5]
//
// Output: false
//
// Explanation: The array cannot be partitioned into equal sum subsets.
//
//
//  
//


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t = accumulate(begin(nums),end(nums),0);
        int m = *max_element(begin(nums),end(nums));
        int h = t/2;
        if((t%2) or (m>h) or (size(nums)<2)) return false;
        sort(begin(nums),end(nums),greater<int>());
        set<int> S={0};//all sums
        for(int n:nums){
            vector<int> V;//intermediate sums
            for(int s:S){
                int v = s+n;
                if(v==h)return true;
                if(v<h) V.push_back(v);
            }
            for(int v:V)
                S.insert(v);
        }
        return false;
    }
};
