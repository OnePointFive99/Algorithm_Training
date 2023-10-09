解题思路：
1. 先将整个字符串倒转过来
2. 再分别倒转每个单词
3. 因为要去掉多余的空格，所以最好在最开始就去掉

所以梳理实现流程为：
1. 删掉多余空格
2. 倒转整个字符串
3. 倒转每个单词


v1.0:
class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i <s.size() - 1; i++){
            if(s[i] == ' '&& s[i+1] == ' '){
                s.erase(s.begin() + i);
            }
            if(s.size()>0 && s[s.size() - 1]==' '){
                s.erase(s.end());
            }
            if(s.size()>0 && s[0]==' '){
                s.erase(s.begin());
            }
        }
        reverse(s.begin(), s.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]==' '){
                reverse(s.begin() + j, s.begin() + i - 1);
                j = i + 1;
            }
        }
        return s;
    }
};

v2.0:
1. erase时间复杂度为O(n)，所以for循环嵌套erase，时间复杂度为O(n^2)
改用双指针
2. 记住reverse是左闭右开区间
3. v1.0代码实际上非常容易错，因为随着erase，迭代器指代的不是我们希望的位置

class Solution {
public:
    string reverseWords(string s) {
        int fastIndex = 0, slowIndex = 0;
        //先去掉首部的空格
        while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' '){
            fastIndex++;
        }
        //去除中间多余的空格
        for(;fastIndex < s.size(); fastIndex++){
            if(fastIndex > 1 && s[fastIndex - 1] == ' '&&s[fastIndex]==' '){
                continue;
            }
            else{
                s[slowIndex] = s[fastIndex];
                slowIndex++;
            }
        }
        //去掉最后的空格，最后有三种情况：
        //1.没空格，此时慢指针就在最后一个元素上
        //2.有两个空格以上，此时慢指针不随快指针移动，停在最后一个元素上
        //3.有一个空格，此时慢指针会随快指针移动，停在最后一个空格上
        if(slowIndex > 1 && s[slowIndex - 1]==' '){
            s.resize(slowIndex-1);
        }
        else{
            s.resize(slowIndex);
        }
        //反转整个字符串
        reverse(s.begin(), s.end());
        //反转单词
        int j = 0;
        for(int i = 0; i <= s.size(); i++){
            if(s[i]==' ' || i == s.size()){
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }
        return s;
    }
};

v3.0:
1. 使用了一个删除数组元素的更加模板化的方法
2.将删除空格单独作为一个函数
class Solution {
public:
    void removeExtraSpaces(string &s){
        int slowIndex = 0, fastIndex = 0;
        for(; fastIndex < s.size();fastIndex++){
            if(s[fastIndex] != ' '){//只处理不包含空格的部分
                if(slowIndex != 0){
                    s[slowIndex++] = ' ';//首先加一个空格
                }
                while(s[fastIndex] != ' ' && fastIndex<s.size()){
                    s[slowIndex++] = s[fastIndex++];//剩下不是空格的部分都加进来
                }
            }

        }
        s.resize(slowIndex);
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s.begin(), s.end());

        int j = 0;
        for(int i = 0;i<=s.size();i++){
            if(s[i]== ' '|| i ==s.size()){
                reverse(s.begin()+j, s.begin()+i);
                j = i + 1;
            }
        }
        return s;

    }
};