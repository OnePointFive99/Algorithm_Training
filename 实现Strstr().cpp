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

v2.0:
使用KMP算法，KMP的看家本领是找出一个串里是否有指定的子串
核心工具就是前缀表prefix table，相当于一个存档，当不满足条件时，尽量利用已有的信息。
前缀表的任务是当前位置匹配失败，找到之前已经匹配上的位置，再重新匹配，
此也意味着在某个字符失配时，前缀表会告诉你下一步匹配中，模式串应该跳到哪个位置。
关于最长相等前后缀：字符串a的最长相等前后缀为0。 字符串aa的最长相等前后缀为1。 字符串aaa的最长相等前后缀为2。 等等.....。
注意前缀不包含最后一个字符，后缀不包含第一个字符
吭哧吭哧写了半天，发现主要是没理解next数组的构建  可以多写几次，避免挫败感
class Solution {
public:
    vector<int> getNext(string s){
        vector<int> prefixTable(s.size(), 0);//其实可以不用这么搞，直接传进来一个数组就行，不用构造局部变量
        prefixTable[0] = 0;//前缀表开始就是0
        int j = 0;//j负责计算最长前后缀，其实前缀一定是从下标0开始的
        for(int i = 1; i <s.size(); i++){
            while(j>0 && s[i]!=s[j]){//当j没回退到最开始的0，而且又确实不相等时，就回退
               j = prefixTable[j-1];//j回退 
           }
           //当j回退到0或者有相等出现时，j累加
           if(s[i]==s[j]){//
               j++;
           }
           //一轮判断结束（相等或不相等，因为不相等会产生迭代，所以应该先判断不相等），更新前缀表
           prefixTable[i] = j;
           

        }
        return prefixTable;
    }
    int strStr(string haystack, string needle) {
        vector<int> prefixTable = getNext(needle);//拿到子串的前缀表
        int j = 0;
        for(int i = 0; i < haystack.size();i++){
            //其实跟构建前缀表的思想很像，也是先看当j没回退到最开始的0，而且又确实不相等时，就回退
           while(j>0 &&haystack[i]!=needle[j]){
               j = prefixTable[j - 1];
           }
           //当j回退到0或者有相等出现时，j累加
           if(haystack[i]==needle[j]){
               j++;
           }
           //如果到了字串末尾说明匹配成功了，返回下标（可以验算一下）
           if(j==needle.size()){
               return i - needle.size() + 1;
           }
        }
        return -1;//原串比对完了说明没有，返回-1

    }
};

v3.0：
1. 优化获得子串的函数
2. 避免特殊情况：字串为空返回0；
3. 避免重复计算：将needle.size()提前计算，并在循环中使用它的值，而不是每次都重新计算。

class Solution {
public:
    void getNext(string s, vector<int> &prefixTable){
        prefixTable[0] = 0;
        int j = 0;//j负责计算最长前后缀
        for(int i = 1; i <s.size(); i++){
            while(j>0 && s[i]!=s[j]){
               j = prefixTable[j-1];//j回退 
           }
           if(s[i]==s[j]){
               j++;
           }
           prefixTable[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if(n==0)return 0;
        vector<int> prefixTable(n,0);
        getNext(needle, prefixTable);
        int j = 0;
        for(int i = 0; i < haystack.size();i++){
           while(j>0 &&haystack[i]!=needle[j]){
               j = prefixTable[j - 1];
           }
           if(haystack[i]==needle[j]){
               j++;
           }
           if(j==n){
               return i - n + 1;
           }
        }
        return -1;

    }
};