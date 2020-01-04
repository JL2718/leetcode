// Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the x and y axes.
//
// If there isn't any rectangle, return 0.
//
//  
//
// Example 1:
//
//
//
//
// Input: [[1,2],[2,1],[1,0],[0,1]]
// Output: 2.00000
// Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
//
//
//
// Example 2:
//
//
//
//
// Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
// Output: 1.00000
// Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
//
//
//
// Example 3:
//
//
//
//
// Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
// Output: 0
// Explanation: There is no possible rectangle to form from these points.
//
//
//
// Example 4:
//
//
//
//
// Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
// Output: 2.00000
// Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
//
//
//
//  
//
//
//
// Note:
//
//
// 	1 <= points.length <= 50
// 	0 <= points[i][0] <= 40000
// 	0 <= points[i][1] <= 40000
// 	All points are distinct.
// 	Answers within 10^-5 of the actual value will be accepted as correct.
//
//


static auto x = []()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        if(size(points)<4) return 0;
        long min_area2=LONG_MAX;
        set<pair<int,int>> S;
        for(auto p:points)S.insert({p[0],p[1]});
        for(auto p=begin(S);p!=prev(prev(end(S)));++p)
            for(auto q=next(p);q!=prev(end(S));++q)
                for(auto r=next(q);r!=end(S);++r){
                    const auto& [x0,y0] = *p;
                    const auto& [x1,y1] = *q;
                    const auto& [x2,y2] = *r;
                    const int dx0 = x0-x1;
                    const int dx1 = x0-x2;
                    const int dy0 = y0-y1;
                    const int dy1 = y0-y2;
                    if(dx0*dx1+dy0*dy1) continue;
                    if(!S.count({x2+x1-x0,y2+y1-y0})) continue;
                    long area2 = (long)(dx0*dx0+dy0*dy0)*(long)(dx1*dx1+dy1*dy1);
                    min_area2 = min(min_area2,area2);
                }
        return (double)(min_area2==LONG_MAX?0:sqrt((double)min_area2));
    }
};
