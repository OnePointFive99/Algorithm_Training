void nextPermutation(vector<int>& nums) {
    if (nums.size() == 1)
        return;

    int numsSize = nums.size();
    int left = numsSize - 2, right = numsSize - 1;
    int localMin = 100;  //记录已处理值的最小值

    //从尾部检查有序（小到大），有序则返回最小的两个元素交换的结果，无序则排成有序备用
    //left需要记录一下
    while (left >= 0)
    {
        if (nums[left] >= nums[right])
        {
            if (left == 0)
            {
                int end = numsSize - 1;
                swap(nums[left], nums[end--]);
                while (right < end)
                {
                    swap(nums[right++], nums[end--]);
                }
                return;
            }
            if (nums[right] < localMin)
                localMin = nums[right];
            left--;
            right--;
        }

        if (nums[left] < nums[right])
        {
            if (nums[left] < localMin)//nums【left】 == localMin时，说明应该找个比nums[left]大的
                                      //应该走nums[left] > localMin的逻辑，而不是只用排序left右边的数
            {
                swap(nums[left], nums[numsSize - 1]);//left之后的都已有序，直接换即可
                int end = numsSize - 1;
                while (right < end)
                {
                    swap(nums[right++], nums[end--]);
                }
                return;
            }
            else
            {
                int end = numsSize - 2;
                while (end >= left)
                {
                    if (nums[end] <= nums[left])//现在要找一个比left位置大的数，=也不行
                        end--;
                    if (nums[end] > nums[left])
                    {
                        swap(nums[end], nums[left]);
                        break;
                    }
                }
                end = numsSize - 1;
                while (right < end)
                {
                    swap(nums[right++], nums[end--]);
                }
                return;
            } 
        }
    }
}

void nextPermutation(vector<int>& nums) {
    if (nums.size() == 1)
        return;

    int numsSize = nums.size();
    int left = numsSize - 2, right = numsSize - 1;

    //从尾部检查有序（小到大），有序则返回最小的两个元素交换的结果，无序则排成有序备用
    while (left >= 0 && nums[left] >= nums[right])
    {
        left--;
        right--;
    }
    if (left == -1)
    {
        int end = numsSize - 1;
        while (right < end)
        {
            swap(nums[right++], nums[end--]);
        }
        return;
    }

    int end = numsSize - 1;
    while (end >= right && nums[end] <= nums[left])
    {
        end--;
    }
    swap(nums[end], nums[left]);
    end = numsSize - 1;
    while (right < end)
    {
        swap(nums[right++], nums[end--]);
    }
}