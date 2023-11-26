传智杯： 不会动态规划，只能这样了，感觉还挺巧妙的 

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;cin>>n;
    string str;cin>>str;
    unordered_map<char,int> mp1;//记录此字符还有多少个
    unordered_map<char,int> mp2;//记录此字符已经出现了多少个
    for(char c:str){
        mp1[c]++;//先记录总的字符数
    }
    long res = 0;
 
    for(int i = 0;i<n;i++){
        char c = str[i];
        mp1[c]--;//遇到的字符则还有的数量-1
        mp2[c]++;
        if(mp1[c]>0) res+= (i+1-mp2[c]) * mp1[c];//(i+1-mp2[c])得到不同于字母b的数量，mp1[c]是可能的字母b数量
    }
    cout<<res<<endl;
    return 0;
}
