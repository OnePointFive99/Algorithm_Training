class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        int m = array.size();
        if(m == 0) return {};
        int n = array[0].size();
        vector<int> ans;
        int startx = 0, starty = 0;
        int stepx = m-1;
        int stepy = n-1;
        int loop = min(m,n)/2;//max的话中间明显有一个单独的行或列
        while(loop--){
            int i,j;
            for(i = starty; i<stepy; i++){
                ans.push_back(array[startx][i]);
            }
            for(j = startx; j<stepx; j++){
                ans.push_back(array[j][i]);
            }
            for(; i>starty; i--){
                ans.push_back(array[j][i]);
            }
            for(;j>startx; j--){
                ans.push_back(array[j][starty]);
            }
            startx++;
            starty++;
            stepx--;
            stepy--;
        }
        if(min(m,n)%2){
            if(m<n){
                for(int i = starty; i<=stepy; i++){
                    ans.push_back(array[startx][i]);
                }
            }
            else{
                for(int i = startx; i<=stepx; i++){
                    ans.push_back(array[i][starty]);
                }
            }
        }
        return ans;

    }
};