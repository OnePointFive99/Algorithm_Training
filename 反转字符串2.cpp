解题思路：
因为for循环的循环出现了规律，所以一定要在for循环中体现出来。
将题目的规则模拟出来即可。


v1.0:
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k){
            if(i + k > s.size() - 1){
                reverse(s.begin() + i, s.end());
            }
            else{
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};

v2.0:
1. 参考reverse的实现定义了自己的reverseSubStr函数，在reverseStr函数中调用
2. 关于reverseSubStr的--last和first++，因为s.end()返回的是最后一个字符的下一个位置，所以要先--
3. 关于s.begin()和s.end()查看网址：https://img-blog.csdn.net/20180518122234389?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3lzcTk2/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70
class Solution {
public:
    template <class BidirectionalIterator>
    void reverseSubStr(BidirectionalIterator first, BidirectionalIterator last){
        while(first != last && first != --last){//确定两者的值是否相邻或相等
            iter_swap(first++, last);
        }
    }
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k){
            if(i + k > s.size() - 1){
                reverseSubStr(s.begin() + i, s.end());
            }
            else{
                reverseSubStr(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};

v3.0:
使用反转字符串.cpp的方法
class Solution {
public:
    void reverseString(vector<char>& s, int first, int last) {
        while(first < last){
            swap(s[first++], s[last--]);
        }
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k <= s.size() - 1) reverseString(s, i, i + k - 1);
            else reverseString(s, i, s.size() - 1);
        }
        return s;
    }
};

v4.0
1. 去掉if-else提速
class Solution {
public:
    void reverseString(string &s, int first, int last) {
        while(first < last){
            swap(s[first++], s[last--]);
        }
    }

    string reverseStr(string s, int k) {
        if(k==1) return s;
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            reverseString(s, i, i + min<int>(k - 1, s.size() - i - 1));
        }
        return s;
    }
};