周赛题   记得s.find(x) != s.npos就行
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> result;
    int i = 0;
    for (auto s : words)
    {
        if (s.find(x) != s.npos)
        {
            result.push_back(i);
        }
        i++;
    }
    return result;
}
};