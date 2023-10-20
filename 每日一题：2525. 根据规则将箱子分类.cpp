class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        //todo:
        // 1. 计算需要检查的量  
        // 2. 检查质量
        // 3. 检查一个维度
        // 4. 检查体积

        if(mass>=100){
            if(length>=1e4||width>=1e4||height>=1e4||(long long)length*width*height>=1e9){
                return "Both";
            }else{
                return "Heavy";
            }
        }else{
            if(length>=1e4||width>=1e4||height>=1e4||(long long)length*width*height>=1e9){
                return "Bulky";
            }
            else{
                return "Neither";
            }
        }

    }
};