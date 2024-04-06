//一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内,说明重复数字最少的情况下只有1个数有重复
//且：【nums[nums[i]] 一定不会越界】！所以我们可以借助这一特点，用快慢指针对数组进行遍历，如果出现数值相等且index不等
//说明有重复！
//设慢指针走了n步，则快指针走了2n步
//那么快指针-慢指针 = n 
//假设到环走了m步，环周长是c
//那么n = m + j * c j是圈数
//2n = m + k * c k是圈数
//可知 n = (k - j) * c 必是n的整数倍  套圈了 俩人在直线上不可能套圈，所以与m无关
//那么慢指针在环里走了 n - m 步
//即还有m步到环入口
//此时从起点与慢指针同时出发，即可在环入口相遇
int findDuplicate(vector<int>& nums) {
    int maxSize = nums.size();
    int slow = 0, fast = 0;
    slow = nums[slow];
    fast = nums[nums[fast]];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    int finder = 0;
    while (finder != slow)
    {
        slow = nums[slow];
        finder = nums[finder];
    }
    //找到了入口的值
    return finder;
}