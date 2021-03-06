// Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself.  If a cell has less than 8 surrounding cells, then use as many as you can.
//
// Example 1:
//
// Input:
// [[1,1,1],
//  [1,0,1],
//  [1,1,1]]
// Output:
// [[0, 0, 0],
//  [0, 0, 0],
//  [0, 0, 0]]
// Explanation:
// For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
// For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
// For the point (1,1): floor(8/9) = floor(0.88888889) = 0
//
//
//
// Note:
//
// The value in the given matrix is in the range of [0, 255].
// The length and width of the given matrix are in the range of [1, 150].
//
//


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(size(M)==0)return M;
        vector<vector<int>> R(size(M),vector<int>(size(M[0])));
        for(int i=0;i!=size(R);++i)
            for(int j=0;j!=size(R[i]);++j){
                int n=0,t=0;
                for(int k=i-1;k<=i+1;++k)
                    for(int l=j-1;l<=j+1;++l)
                        if(k>=0 and l>=0 and k<size(R) and l<size(R[k])){
                            ++n;
                            t+=M[k][l];
                        }
                //for(int a:{i,j,t,n})cout<<a<<' ';cout<<endl;
                R[i][j]=t/n;
            }
        return R;
    }
};
