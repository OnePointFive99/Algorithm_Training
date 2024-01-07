要求返回n个数据中的众数，且众数的出现次数要大于floor(n/2)
尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
数组中至少有一个元素
数组元素值-10e9 <= nums[i] <= 10e9
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int num:nums)
        {
            ump[num]++;
            if(ump[num]>nums.size()/2)return num;
        }
        return -1;
    }
};

候选人算法：核心原理就是众数的出现次数多，在最后总能把--count小于0，可以验证：
nums = [2,2,1,1,1,2,2]
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(int num:nums)
        {
            if(num==candidate)count++;
            else if(--count<0)
            {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};