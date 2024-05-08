
v1.0:
没想到一下子写不出来，忘记什么是二分法了，这里回顾一下：
「二分查找 binary search」是一种基于分治策略的高效搜索算法。
它利用数据的有序性，每轮减少一半搜索范围，直至找到目标元素或搜索区间为空为止。

注意，前提是：①有序；②不重复；③连续空间；④较大量数据；
整体思想就是控制搜索的范围，先是[left, right)，然后[left, mid)，[mid, right)，
需要去根据mid的值与target的大小关系来确定下一步的搜索区间。
时间复杂度是logN 空间复杂度是1

小数据量下，线性查找性能更佳。在线性查找中，每轮只需要 1 次判断操作；而在二分查找中，需要 1 次加法、1 次除法、1 ~ 3 次判断操作、1 次加法（减法），共 4 ~ 6 个单元操作；因此，当数据量 
 较小时，线性查找反而比二分查找更快。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left<right){
            int middle = left + (right - left)/2;
            if(nums[middle]>target){
                right = middle;
            }
            else if(nums[middle]<target){
                left = middle+1;
            }
            else{
                return middle;
            }
        }
        return -1;
    }
};

补充：
另一种写法：
int BinarySearch(vector<int> v, int target)
{
    int i = 0, j = v.size() - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (v[mid] < target)
        {
            i = mid + 1;
        }
        else if (v[mid] > target)
        {
            j = mid - 1;
        }
        else {
            return mid;
        }

    }
    return -1;
}
# 关键点

## while的条件为什么是i≤j而不是i<j

想清楚，因为i≤j依旧可以从i到j中找到一个数

## 为什么是i = mid + 1而不是 i= mid？

要明确i到j的区间究竟是什么？

是target可能的值的区间，所以不要把不可能是target的数字包含进来