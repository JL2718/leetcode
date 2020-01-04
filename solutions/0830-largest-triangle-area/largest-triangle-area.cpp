// You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.
//
//
// Example:
// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2
// Explanation: 
// The five points are show in the figure below. The red triangle is the largest.
//
//
//
//
// Notes: 
//
//
// 	3 <= points.length <= 50.
// 	No points will be duplicated.
// 	 -50 <= points[i][j] <= 50.
// 	Answers within 10^-6 of the true value will be accepted as correct.
//
//
//  
//


class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        if(size(points)<3)return false;
        double m=0.0;
        const auto bp = begin(points);
        const auto ep = end(points);
        for(auto it=bp;it!=ep-2;++it)
            for(auto jt=it+1;jt!=ep-1;++jt)
                for(auto kt=jt+1;kt!=ep;++kt){
                    m=max(m,0.5*abs((*it)[0]*(*jt)[1]+(*jt)[0]*(*kt)[1]+(*kt)[0]*(*it)[1]-(*it)[0]*(*kt)[1]-(*jt)[0]*(*it)[1]-(*kt)[0]*(*jt)[1]));
                }
        return m;
    }
};
