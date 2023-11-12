v1.0 哈希表真是好文明，注意他的用法

为什么会想到用哈希表：因为需要查找“是否已经有这个值”，而哈希表查看是否有这个值很便利
哈希表为什么用map：因为要存数值和下标，是一个键值对，所以不能用set
本题map是用来存什么的：{value, iter}
map中的key和value用来存什么的:key存数值，value存下标
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i< nums.size();i++){
            auto iter = m.find(target - nums[i]);
            if(iter !=m.end()){
                return {iter->second, i};
            }
            m.insert(pair<int, int>{nums[i], i});
        }
        return {};
    }
};