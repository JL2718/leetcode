// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
private:
    void fun(vector<int>& v,int i,vector<vector<int>>& R){
        if(i==size(v)-1){R.push_back(v);return;}
        fun(v,i+1,R);
        for(int j=i+1;j!=size(v);++j){
            swap(v[i],v[j]);
            fun(v,i+1,R);
            swap(v[i],v[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> R;
        fun(nums,0,R);
        return R;
    }
};
