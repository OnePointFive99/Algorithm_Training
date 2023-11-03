
v1.0：
暴力方法：
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