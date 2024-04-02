int singleNumber(vector<int>& nums) {
    unordered_map<int, int> numMap;

    for (auto n : nums)
    {
        numMap[n]++;
    }

    for (auto iter = numMap.begin(); iter != numMap.end(); iter++)
    {
        if (iter->second == 1)
            return iter->first;
    }

    return 0;

}

更巧妙的方法是使用异或：
int singleNumber(int* nums, int numsSize){
    int i,temp=0;
for(i=0;i<numsSize;i++)
{
    temp ^=nums[i];
}
return temp;
}