赫鲁丝网络面试题，看成了接雨水....
下来自己做发现暴力超时了...
v1.0:暴力双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int slow = 0, max = 0;
        for(;slow <height.size()-1;slow++)
        {
            for(int fast = slow+1; fast < height.size();fast++)
            {
                int area = min(height[fast], height[slow]) * (fast-slow);
                if (area > max)max = area;
            }
        }
        return max;
    }
};

v2.0 聪明双指针：我主要是没想到双指针收缩的条件，其实条件很简单，就是更换较矮的那一根垂线
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, max = 0;
        while(left<right)
        {
            int area = min(height[left], height[right]) * (right-left);
            if(area > max)
            {
                max = area;
            }
            if(height[left]<height[right])
            {
                left++;
            }else{
                right--;
            }
        }
        return max;
    }
};