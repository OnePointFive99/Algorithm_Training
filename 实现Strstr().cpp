28. 找出字符串中第一个匹配项的下标
原始版本：
//todo：1，检查
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if(needle.size()> haystack.size()) return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            int j = 0;
            while (j < needle.size() && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};