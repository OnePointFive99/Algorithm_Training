v1.0:使用集合来去重！涉及到unordered_set的声明和insert，以及用set初始化vector的方法
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int a[1000] = {0};
        unordered_set<int> result
        for(auto n:nums1){
            a[n]=1;
        }
        for(auto n:nums2){
            if(a[n]==1){
                result.insert(n);
            }
        }
        return vector<int>(result.begin(),result.end());


    }
};

v2.0:不用数组了，直接用unordered_set  会快很多
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int>num1(nums1.begin(),nums1.end());
        for(auto n:nums2){
            if(num1.find(n)!=num1.end()){
                result.insert(n);
            }
        }
        return vector<int>(result.begin(),result.end());
    }
};

v3.0: 哦忘记了用vector初始化set以及用set初始化vector的方法
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1;
    unordered_set<int> set2;
    vector<int> ret;
    for (int i : nums1)
    {
        set1.insert(i);
    }
    for (int i : nums2)
    {
        set2.insert(i);
    }
    for (int i : set1)
    {
        if (set2.count(i))
        {
            ret.emplace_back(i);
        }
    }
    return ret;
}
v4.0:
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> ret;
    
    for (int i : set1)
    {
        if (set2.count(i))
        {
            ret.emplace_back(i);
        }
    }
    return ret;
}