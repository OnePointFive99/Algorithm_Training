
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

v2.0：
嘛  既然知道是97~122了，可以缩减下数组大小
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int a[26] = {0};
        const int m = 97;
        for(auto c: s){
            a[static_cast<int>(c)-m]++;
        }
        for(auto c: t){
            a[static_cast<int>(c)-m]--;
        }
        for(int i:a){
            if(i!=0) return false;
        }
        return true;

    }
};

v3.0：只需要-'a'就行了...不用记ascii码

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int a[26] = {0};
        for(auto c: s){
            a[c-'a']++;
        }
        for(auto c: t){
            a[c-'a']--;
        }
        for(int i:a){
            if(i!=0) return false;
        }
        return true;

    }
};
v4.0:直接map
bool isAnagram(string s, string t) {
    if (s == t)return false;
    unordered_map<char,int> owned;
    for (char c : s)
    {
        owned[c]++;
    }
    for (char c : t)
    {
        owned[c]--;
    }
    for (auto i : owned)
    {
        if (i.second != 0)
            return false;
    }
    return true;
}