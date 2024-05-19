
v1.0:
这道题只需要返回数值而不是下标，所以可以先对数组进行排序
使用三指针方法：最外层一个for循环，i是最小的值
然后对i进行判断，如果i>0直接返回，不用在找了
再使用两个指针，一个指向i+1，一个指向数组最后，分别是中间值和最大值，
然后固定i的情况下移动left和right指针，和大了就把right变小（左移），小了就把left变大（右移）
最后找到了符合的值后，将结果压入result数组，然后再对left和right可能重复的情况进行排除，例如：
-2,-1,-1,-1,2,2,2,2这种情况
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());//sort默认是从小到大排序
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]>0)return result;//如果最小的数已经大于0，那么不可能等于0
            //这里需要排除重复的三元组而不是重复的元素，所以找的是i是否已经等于过某个数
            //如果使用nums[i]==nums[i+1]，那么会把left=i+1时满足三数和等于0的情况漏掉
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                    }
                else if(nums[i]+nums[right]+nums[left]<0){
                    left++;
                }
                else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right>left&&nums[right]==nums[right-1]){
                        right--;
                    }
                    while(right>left&&nums[left]==nums[left+1]){
                        left++;
                    }
                    right--;
                    left++;
                }
            } 
        }
        return result;
    }
};

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            return ret;

        if (i > 0 && nums[i - 1] == nums[i])//不用nums[i+1]，因为是跟走过循环的元素比，所以是i-1
            continue;

        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[i] + nums[left] + nums[right] == 0)
            {
                ret.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                right--;
                left++;
                //不加下面两个while的错误用例：[-2,0,0,2,2]
                while (left < nums.size() && nums[left] == nums[left - 1])
                    left++;
                while (right > i && nums[right] == nums[right + 1])
                    right--;
            }
            else if (nums[i] + nums[left] + nums[right] < 0)
            {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return ret;
}