解题思路：
找到需要替换前后字符串的长度变化，从尾巴开始向前替换，用两个指针分别从旧尾部和新尾部向头部移动，直到相遇

v1.0：
class Solution {
public:
    string pathEncryption(string path) {
        // int numsOfPoint = 0;
        // for(inti = 0; i < path.size(); i++){
        //     if(path[i]=='.')numsOfPoint++;
        // }
        //本题大小不变 不需要path.resize(path.size() + numsOfPoint)
        for(int i = 0; i < path.size(); i++ ){
            if(path[i]=='.'){
                path[i] = ' ';
            }
        }
        return path;
    }
};

v2.0:
使用size_t pos接收.find的位置，当pos不为npos时，说明找到了，此时再调用replace，replace又需要使用pos来指引替换开始的位置，非常方便
class Solution {
public:
    string pathEncryption(string path) {
        size_t pos = path.find(".");
        while(pos != string::npos){
            path.replace(pos, 1, " ");
            pos = path.find(".");
        }
        return path;
    }
};