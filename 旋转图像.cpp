
硬编码写出来的，先倒序数组再轴对称
原因是这种方法得到的等式与旋转的等式是一致的：
水平翻转：matrix[r][c] = matrix[n-1-r][c];
主对角线翻转：matrix[r][c] = matrix[c][r];
即matrix[r][c] = matrix[c][n-1-r];
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int left = 0, right = matrix.size()-1; left<right;)
        {
            swap(matrix[left], matrix[right]);
            left++;
            right--;
        }
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                if(i<j)swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

所以这道题的正确解法是：先根据流转的方式写出矩阵元素的转换方式，再一个个轮换即可
需要注意奇偶的问题 虽然是On^2但是n^2的系数很小
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n/2;i++)
        {
            for(int j = 0; j <(n+1)/2; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};