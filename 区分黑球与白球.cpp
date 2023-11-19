周赛题：这题做了1h 主要是感觉循环没写好  跟大佬的一比很冗余

class Solution {
public:
    long long minimumSteps(string s) {
        int count_1 = 0, count_0 = 0;
        long long count = 0;
        for(int i = 0; i<s.size();i++)
        {
            while(s[i]=='1'&&i<s.size())
            {
                count_1++;
                i++;
            }
            while(s[i]=='0'&&i<s.size()&&count_1>0)
            {
                count_0++;
                i++;
            }
            if(i<s.size()&&count_0>0)
            {
                count+=(long long)count_1 * count_0;
                count_0 = 0;
                i--;
            }
            else
            {
                count+=(long long)count_1 * count_0;
            }
        }
        return count;
    }
};

大佬写的：说明想的很明白 ，感觉我主要是没想清楚直接开始写了

class Solution {
public:
    long long minimumSteps(string s) {
        int cnt = 0;
        long long ans = 0;
        for(char c : s) {
            if(c == '0') ans += cnt;
            else ++cnt;
        }
        return ans;
    }
};