这道题跟三数之和一个思路，只是外层多一层循环，以此类推五数之和、六数之和都是这样做
但是需要注意的是，这里的target不是固定的，所以剪枝的时候要确定值大于等于0
v1.0:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size();i++){
            //不要判断nums[k] > target 就返回了，
            //三数之和 可以通过 nums[i] > 0 就返回了，因为 0 已经是确定的数了
            //四数之和target是任意值。
            //比如：数组是[-4, -3, -2, -1]，target是-10，不能因为-4 > -10而跳过。
            if(nums[i]>target&&nums[i]>=0){
                return result;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size();j++){
                if(nums[j] + nums[i]>target&&nums[j] + nums[i]>=0){
                    break;//这里不能直接return result，因为外层还有循环！
                }
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int left = j + 1;
                int right = nums.size()-1;
                while(left<right){
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]>target){
                        right--;
                    }
                    else if((long)nums[i]+nums[j]+nums[left]+nums[right]<target){
                        left++;
                    }
                    else{
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(left<right&&nums[left]==nums[left+1]){
                            left++;
                        }
                        while(left<right&&nums[right]==nums[right-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }

        }
        return result;
    }
};