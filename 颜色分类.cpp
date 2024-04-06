class Solution {
public:
    void sortColors(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    for(int i = 0; i <= right; i++)
    {
        //如果while的是==0的情况，那么就会出问题，一直在0循环
        while (i <= right && nums[i] == 2)
        {
            swap(nums[right--], nums[i]);//while的目的是，防止2被换到i的位置被跳过！
        }

        // 2换完了，i的位置是1或0
        if (nums[i] == 0)
        {
            swap(nums[left++], nums[i]);
        }
        //本质上是:i的位置要经过0 和 1 的双重考验
        //防止出现i被交换成1之后，直接测试i+1，导致0之间夹着1的情况
    }
}
};