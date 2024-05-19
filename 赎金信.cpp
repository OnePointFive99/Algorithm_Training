class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size())return false;
        int chars[26] = {0};
        for(char c: magazine)
        {
            chars[c-'a']++;
        }
        for(char c: ransomNote)
        {
            chars[c-'a']--;
            if(chars[c-'a']<0)
            {
                return false;
            }
        }
        return true;

    }
};

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<int, int> umap;
    for (auto c : magazine)
    {
        umap[c]++;
    }
    for (auto c : ransomNote)
    {
        umap[c]--;
        if (umap[c] == -1)
            return false;
    }
    return true; 
}