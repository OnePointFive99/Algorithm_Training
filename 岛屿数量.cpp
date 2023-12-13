岛屿数量、岛屿面积这些题都是网格DFS，是有模板的

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0||j<0||i==grid.size()||j==grid[0].size()||grid[i][j]=='0')
        {
            return;
        }
        int updown[4] = {0,0,-1,1};
        int leftright[4] = {-1,1,0,0};
        if(grid[i][j]=='1'){
            grid[i][j]='0';
            for(int k = 0; k <4;k++)
            {
                dfs(grid, i + updown[k], j + leftright[k]);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j <grid[0].size(); j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid, i, j);//把邻近的1都变为0
                }  
            }
        }
        return count;
    }
};