class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> m(matrix);
        for(int i = 0; i< matrix.size();i++)
        {
            for(int j = 0; j< matrix[0].size();j++)
            {
                if(matrix[i][j]==0){
                    m[i] = new vector<int>(m[i].size(), 0);
                    for(auto v:m)
                    {
                        v[j] = 0;
                    }
                }
            }
        }
        matrix = m;
    }
};