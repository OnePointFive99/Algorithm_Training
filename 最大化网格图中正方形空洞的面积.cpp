周赛题，题目用例的数组其实可以排下序！然后vector是没有find的，需要用algroithm头文件，然后返回值也不能直接用

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

    int cH = 0, cV = 0;
    //int minBars = min(hBars.size(), vBars.size());//minBars>=1
    //计算最大连续量,比较大小，取小的平方即可
    for (int i = 0; i < hBars.size();i++)
    {
        int tmp = 1;
        int j = 1;
        while (find(hBars.begin(), hBars.end(), hBars[i]+j)!=hBars.end())
        {
            j++;
            tmp++;
        }
        if (tmp > cH)cH = tmp;  
    }
    for (int i = 0; i < vBars.size(); i++)
    {
        int tmp = 1;
        int j = 1;
        while (find(vBars.begin(), vBars.end(), vBars[i] + j) != vBars.end())
        {
            j++;
            tmp++;
        }
        if (tmp > cV)cV = tmp;
    }
    if (hBars.size() == 1)cH = 1;
    if (vBars.size() == 1)cV = 1;

    int minBars = min(cH, cV);
    
    return pow(minBars+1, 2);    

}
};

大佬写的： 我跟大佬的思路是完全一样的，就是我写复杂了，因为没排序
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        //排序
        int i,j,ax=1,ay=1;
        for(i=j=1;i<hBars.size();i++)
        {
            if(hBars[i]!=hBars[i-1]+1)j=0;
            ax=max(ax,++j);
        }
        for(i=j=1;i<vBars.size();i++)
        {
            if(vBars[i]!=vBars[i-1]+1)j=0;
            ay=max(ay,++j);
        }
        int ans=min(ax,ay)+1;
        return ans*ans;
    }
};