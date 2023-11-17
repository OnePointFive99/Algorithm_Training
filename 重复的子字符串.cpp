
v1.0：
暴力方法：一个一个试不同长度的子串
感觉暴力也挺巧妙的，子串反正都是从头开始，所以第一个循环找子串的落点，循环条件因为i从1开始并且子串肯定在原串一半长度以下。
然后因为字串的长度需要满足能被原串整除，所以可以减少一部分遍历，在这里对于每种子串情况定义一个match，
从落点开始（本来应该是i+1，但是i是从1开始的，所以j=i）到原串末尾，如果有不匹配的情况就跳出循环并且将match置为false，
如果没有跳出过循环，说明出现了满足情况的子串，如果外层循环都结束了说明不满足情况。
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1;i<=s.size()/2;i++){
            if(s.size()%i==0){
                bool match = true;
                for(int j = i;j<s.size();j++){
                    if(s[j-i]!=s[j]){
                        match =  false;
                        break;
                    }
                }
                if(match){
                    return true;
                    }

            }
            
        }
        return false;

    }
};

v2.0:比较巧妙的方法，由子串构成说明要么是ABAB,要么是ABABAB，此时会发现，由于原始串可以由子串重复构成，
当多个原始串拼起来时，前面有相同的子串，后面有相同的子串，后面的子串做前串，前面的子串做后串，
就一定还能组成一个原始串
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s+s;
        ss.erase(ss.begin());
        ss.erase(ss.end()-1);
        if(ss.find(s)!=string::npos)
        {
            return true;
        }
        return false;
    }
};

使用C++17:contains
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s+s;
        ss.erase(ss.begin());
        ss.erase(ss.end()-1);
        if(contains(ss,s))
        {
            return true;
        }
        return false;
    }
};

v3.0：使用KMP代替.find寻找子串
class Solution {
public:
    void getNext(string s, vector<int> &next)
    {
        int j = 0;//计算公共前后缀
        for(int i = 1; i< s.size();i++)
        {
            while(j>0&&s[j]!=s[i])
            {
                j = next[j-1];
            }
            if(s[j]==s[i])
            {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n==0)return false;
        vector<int> next(n,0);
        getNext(s, next);
        string ss = s+s;
        ss.erase(ss.begin());
        ss.erase(ss.end()-1);
        for(int i = 0, j = 0; i< ss.size(); i++)
        {
            while(j>0&&s[j]!=ss[i])
            {
                j = next[j-1];
            }
            if(s[j]==ss[i])
            {
                j++;
            }
            if(j==n)
            {
                return true;
            }
        }
        return false;

    }
};

v4.0:唐，有了前缀表，是不是可以利用前缀表看看子串？
好确实有点不好理解，当我们有了next数组，因为最长公共前后缀必然不会包含原串
所以对于满足题意的原串，一定是n*sub_str最长公共前后缀必然为(n-1)*sub_str
所以如果有最小子串，设原串长度是L,则一定有L可以整除子串的长度L - next[L-1]
这里next[L-1]就是原串的最大公共前后缀
class Solution {
public:
    void getNext(string s, vector<int> &next)
    {
        int j = 0;//计算公共前后缀
        for(int i = 1; i< s.size();i++)
        {
            while(j>0&&s[j]!=s[i])
            {
                j = next[j-1];
            }
            if(s[j]==s[i])
            {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n==0)return false;
        vector<int> next(n,0);
        getNext(s, next);
        if(next[n-1] > 0 && n % (n - next[n-1]) == 0)
        {
            return true;
        }
        return false;

    }
};