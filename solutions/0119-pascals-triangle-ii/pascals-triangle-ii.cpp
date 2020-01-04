// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
//
// Note that the row index starts from 0.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 3
// Output: [1,3,3,1]
//
//
// Follow up:
//
// Could you optimize your algorithm to use only O(k) extra space?
//


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pr = {1};
        for(int i=0;i!=rowIndex;++i){
            vector<int> vr = {1};
            for(auto it=pr.begin()+1;it!=pr.end();++it)
                vr.push_back(*it+*(it-1));
            vr.push_back(1);
            pr = vr;
        }
        return pr;
    }
};
