
v1.0:第一道岛屿题！深度优先搜索！
class Solution {

    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j)
    {
        if(cur_i<0||cur_j<0||cur_i==grid.size()||cur_j == grid[0].size()||grid[cur_i][cur_j]!=1)return 0;
        grid[cur_i][cur_j]=0;//标记为访问过
        int area = 1;
        int delta_i[4] = {0,0,1,-1};//四个方向
        int delta_j[4] = {1,-1,0,0};
        for(int i = 0; i< 4;i++)
        {
            int next_i = cur_i + delta_i[i];
            int next_j = cur_j + delta_j[i];
            area += dfs(grid, next_i, next_j);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                result = max(result, dfs(grid, i, j));
            }
        }
        return result;
    }
};