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


v2.0:
重温了一下，重点还是while循环里面，然后对于奇数要单独处理
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startX = 0, startY = 0, num = 1;
        int step = n-1;
        vector<vector<int >> result(n, vector<int>(n, 0));
        if(n%2!=0){
            result[n/2][n/2] = n * n;
        }
        int loop = n / 2;
        while(loop--){
            int i,j;
            for(i = startY; i < step; i++){
                result[startX][i] = num++;
            }
            for(j = startX; j<step; j++){
                result[j][i] = num++;
            }
            for(;i>startY;i--){
                result[j][i] = num++;
            }
            for(;j>startX;j--){
                result[j][startY] = num++;
            }
            startX++;
            startY++;
            step--;
        }
        return result;
    }
};