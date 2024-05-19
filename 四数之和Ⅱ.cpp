v1.0:直接超时，完全可以把0 - nums1[i]-nums2[j]作为一组，避免了三重循环！
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n; j++){
                for(int k = 0;k<n;k++){
                    int key = 0 - nums1[i]-nums2[j]-nums3[k];
                    map[key]++;
                    }
                }
            }
            int count = 0;
        for(int l=0;l<n;l++){
            if(map.find(nums4[l])!=map.end()){
                count+=map[nums4[l]];
            }
        }
        return count;

    }
        
};

v2.0:直接改进 nums[i]和nums[j]一组，避免三重循环
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n; j++){
                    int key = 0 - nums1[i]-nums2[j];
                    map[key]++;
            }
        }
        int count = 0;
        for(int k = 0;k<n;k++){
            for(int l=0;l<n;l++){
                if(map.find(nums3[k]+nums4[l])!=map.end()){
                    count+=map[nums3[k]+nums4[l]];
                }
            }
        }        
        return count;
    }
};

v3.0:改用rangefor循环加速
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        for(int i:nums1){
            for(int j :nums2){
                    int key = 0 - i - j;
                    map[key]++;
            }
        }
        int count = 0;
        for(int k:nums3){
            for(int l:nums4){
                if(map.find(k+l)!=map.end()){
                    count+=map[k+l];
                }
            }
        }        
        return count;
    }
};

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> umap;
    for (int i : nums1)
    {
        for (int j : nums2)
        {
            umap[0 - i - j]++;
        }
    }
    int ret = 0;
    for (int i : nums3)
    {
        for (int j : nums4)
        {
            ret += umap[i + j];
        }
    }
    return ret;
}
