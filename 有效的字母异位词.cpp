
v1.0:暴力  算是取了点巧  直接一个数组统计数字出现的次数
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int a[200] = {0};
        for(auto c: s){
            a[static_cast<int>(c)]++;
        }
        for(auto c: t){
            a[static_cast<int>(c)]--;
        }
        for(int i:a){
            if(i!=0) return false;
        }
        return true;

    }
};
