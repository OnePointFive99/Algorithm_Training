class Solution {
public:
    int uniquePaths(int m, int n) {
    long long result = 1;

    //for (int i = m - 1, t = m + n - 2; i > 0; i--, t--)
    for(int i = 1, t = n; i < m; i++, t++)//这里排列数组合数要从小到大算，不然也会被丢精度！ 测试：m = 3， n = 2会丢精度
    {
        //result *= t / i; 这两句的结果都不一样哦，因为*=是默认t/i为整体，此时由于t和i都是整数，除不尽就会丢数据精度，少用
        result = result * t / i;
    }

    return result;
}
};

力扣官方题解链接：https://leetcode.cn/problems/unique-paths/solutions/514311/bu-tong-lu-jing-by-leetcode-solution-hzjf/

int uniquePaths(int m, int n) {
    vector<vector<int>> f(m, vector<int>(n));//声明一个m * n初始化为0的动态规划辅助数组

    //可以先把一些确定的特殊情况的值指定好
    for (int i = 0; i < m; i++)
    {
        f[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        f[0][j] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }

    return f[m - 1][n - 1];
}