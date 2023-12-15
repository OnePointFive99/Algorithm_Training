class Solution {
public:
    int trap(vector<int>& height) {
        int imh = 0,currenth = 0, water = 0, ret = 0;
        for(int i = 0; i < height.size(); i++)
        {   
            if(height[i]<currenth)
            {
                water+=height[i] - currenth;
            }else{
                imh = i;
                currenth = height[i];
                ret+=water;
                water = 0;
            }
        }
        water = 0;
        currenth = 0;
        for(int i = height.size()-1; i>imh;i--)
        {
            if(height[i]<currenth)
            {
                water+=height[i] - currenth;
            }else{
                imh = i;
                currenth = height[i];
                ret+=water;
                water = 0;
            }
        }
        return ret;
    }
};