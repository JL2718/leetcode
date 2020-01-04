// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rvv;
        if(not numRows) return rvv;
        rvv.push_back(vector<int>{1});
        for(int i=1;i<numRows;++i){
            vector<int> rv={1};
            vector<int> pv=rvv.back();
            for(auto it=pv.begin()+1;it<pv.end();++it)
                rv.push_back(*it+*(it-1));
            rv.push_back(1);
            rvv.push_back(rv);
        }
        return rvv;
    }
};
