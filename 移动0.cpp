v1.0:用快指针搜索所有不为0的项，再用0补满
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i]!=0){
                nums[slow++] = nums[i];
            }
        }
        for(;slow<nums.size();slow++){
            nums[slow] = 0;
        }

    }
};