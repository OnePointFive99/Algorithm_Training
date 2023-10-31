每日打个卡  重新开始刷题！！！

螺旋矩阵，因为不好控制循环此时，使用while循环，然后就是模拟，比较考验基本功，核心思想就是收缩！

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n, vector(n, 0));
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int mid = n/2;
        int margin = 1;//收缩边界用
        int i, j;
        int count = 1;
        if(n %2 != 0){
                result[mid][mid] = n * n;
            }
        int loop = n;
        while(loop--){
            i = startx;
            j = starty;
            for(j = starty; j < n - margin;j++){
                result[startx][j] = count++;
            }
            for (i = startx; i<n - margin;i++){
                result[i][j] = count++;
            }
            for(;j > starty;j--){
                result[i][j] = count++;
            }
            for(;i > startx;i-- ){
                result[i][starty] = count++;
            }
            startx++;
            starty++;
            margin++;
        }
        return result;


    }
};