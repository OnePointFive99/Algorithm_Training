逆序就是双指针交换即可，0-1数字反转只需要使用感叹号取反

class Solution {
public:
//子数组逆序+元素取反
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& v:image)
        {
            if(v.size() == 1)
            {
                v[0] = !v[0];
                continue;
            }
            for(int left = 0, right = v.size()-1; left<right;)
            {
                // int tmp = v[left];
                // v[left] = v[right];
                // v[right] = tmp;
                swap(v[left], v[right]);
                v[left] = !v[left];
                v[right] = !v[right];
                left++;
                right--;
                if(left==right)v[left]=!v[left];
            }
        }
        return image;
    }
};