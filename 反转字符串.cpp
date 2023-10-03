解题思路：
数组双指针法：使用两个数组索引子来交换元素，调用自定义的swapElement函数或库函数swap都可以
注意：
1. 数组元素交换时，不能直接使用“=”号，因为这样只是将指针指向了同一个地址，而没有交换元素
2. 库函数swap只能用于基本数据类型，不能用于自定义数据类型
3. 库函数swap的参数类型必须一致，否则会报错
4. 库函数swap的参数类型不能是常量、引用、数组、指针，否则会报错
5. 双指针for循环的边界条件要注意，不能写成i < stringLen - 1，因为这样会漏掉最后一个元素，最好是带入检查一下
 
v1.0:
class Solution {
public:
    void swapElement(auto *x, auto *y){
        auto temp = *x;
        *x = *y;
        *y = temp;
    }
    void reverseString(vector<char>& s) {
        int stringLen = s.size();
        for(int i = 0, j = stringLen - 1; i < stringLen/2; i++, j--){
            swapElement(&s[i], &s[j]);
        }
    }
};

v2.0:
1. 参考了swap库函数的实现来实现swapElement函数
2. 避免申请stringLen大小的临时变量，直接在原数组上交换元素,减少空间复杂度
3. 发现自己搞混了一些东西，引用不是不可以赋值，而是不能更改引用的对象，所以对swapElement的参数列表进行了修改
class Solution {
public:
    void swapElement(auto &x, auto &y){
        auto temp = x;
        x = y;
        y = temp;
    }
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--){
            swapElement(s[i], s[j]);
            //swap(s[i], s[j]);
        }
    }
};