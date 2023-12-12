/*
1.拆成子问题：dp[s]  s是空串到s的遍历
2.子问题递推：dp[s] = for string in wordDict: dp[s - string] && finds
*/
记得 要使用在容器里面的find，使用set
使用substr 的方法也要记住


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us; 
        for(auto w:wordDict)
        {
            us.insert(w);
        }
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        for(int i = 1; i<= s.size();i++)
        {
            for(int j = 0; j<i;j++)
            {
                if(dp[j]&&us.find(s.substr(j, i-j))!=us.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};