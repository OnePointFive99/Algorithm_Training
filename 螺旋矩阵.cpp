
v1.0:这道题跟螺旋矩阵Ⅱ的思路一致，但是需要分别考虑m和n，这里就需要拆分清楚循环的圈数
把独特的一行或一列单独拿出来，看看什么情况下会产生，又该怎么处理
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        vector<int> ans;
        int startx = 0, starty = 0;
        int stepx = m-1;
        int stepy = n-1;
        int loop = min(m,n)/2;//max的话中间明显有一个单独的行或列
        while(loop--){
            int i,j;
            for(i = starty; i<stepy; i++){
                ans.push_back(matrix[startx][i]);
            }
            for(j = startx; j<stepx; j++){
                ans.push_back(matrix[j][i]);
            }
            for(; i>starty; i--){
                ans.push_back(matrix[j][i]);
            }
            for(;j>startx; j--){
                ans.push_back(matrix[j][starty]);
            }
            startx++;
            starty++;
            stepx--;
            stepy--;
        }
        if(min(m,n)%2){
            if(m<n){
                for(int i = starty; i<=stepy; i++){
                    ans.push_back(matrix[startx][i]);
                }
            }
            else{
                for(int i = startx; i<=stepx; i++){
                    ans.push_back(matrix[i][starty]);
                }
            }
        }
        return ans;

    }
};