
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