//定义最终为f[0][s.size() - 1]
//f[i][j]为i到j的子串是否为回文串
//这种题主要是不知道怎么找边界条件！
//这道题的边界条件是长度为1和2的子串，要提前赋值

string longestPalindrome(string s) {
    int start = 0, max_length = 1; //最长回文子串的开始和最大长度
    int n = s.size();
    vector<vector<bool>> f(n, vector<bool>(n));

    //处理初始边界值
    for (int i = 0; i < n; i++)
    {
        f[i][i] = true; // 一个字母是回文串
        if (i < n - 1 && s[i] == s[i + 1])
        {
            f[i][i + 1] = true;
            max_length = 2;
            start = i;
        }
            
    }

    for (int l = 3; l <= n; l++)//以不同长度遍历,存在即下一种长度即可
    {
        for (int i = 0; i + l - 1 < n; i++)// i + l - 1是末尾索引
        {
            f[i][i + l - 1] = f[i + 1][i + l - 2] && s[i] == s[i + l - 1];
            if (f[i][i + l - 1])
            {
                max_length = l;
                start = i;
            }
       }
    }

    return s.substr(start, max_length);
}
