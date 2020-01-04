// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
//
// Example 2:
//
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
//


class Solution {
private:
    int dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 or j<0 or i==size(grid) or j==size(grid[i]))return 0;
        if(grid[i][j]!='1') return 0;
        grid[i][j]='X';
        int IJ[4][2]={{i,j-1},{i,j+1},{i-1,j},{i+1,j}};
        for(auto[ii,jj]:IJ)
            dfs(ii,jj,grid);
        return 1;
    }
        
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!size(grid))return 0;
        int k=0;
        for(int i=0;i!=size(grid);++i)
            for(int j=0;j!=size(grid[i]);++j)
                k += dfs(i,j,grid);
        return k;
    }
};
