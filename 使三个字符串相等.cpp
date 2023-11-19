周赛题，写了12分钟，想法就是直接模拟
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if(s1[0]!=s2[0]||s1[0]!=s3[0]||s2[0]!=s3[0])
        {
            return -1;
        }
        int count = 0;
        int length = min(s1.size(), min(s2.size(), s3.size()));
        for(int i = 0; i<length; i++)
        {
            if(s1[i]==s2[i]&&s2[i]==s3[i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        return s1.size()+s2.size()+s3.size()-count*3;
    }
};

大佬写的：
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if(s1[0] != s2[0] || s1[0] != s3[0] || s2[0] != s3[0]) return -1;
        int n = min({s1.size(), s2.size(), s3.size()});
        for(int i = 0; i < n; ++i) {
            if(s1[i] == s2[i] && s1[i] == s3[i] && s2[i] == s3[i]);
            else return s1.size() + s2.size() + s3.size() - 3 * i;
        }
        return s1.size() + s2.size() + s3.size() - 3 * n;
    }
};
