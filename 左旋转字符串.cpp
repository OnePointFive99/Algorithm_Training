解题思路：
使用整体反转+局部反转就可以实现反转单词顺序的目的。
而使用局部反转+整体反转就可以实现反转字母顺序的目的


v1.0：
class Solution {
public:
    string dynamicPassword(string password, int target) {
        reverse(password.begin(), password.begin() + target);
        reverse(password.begin() + target, password.end());
        reverse(password.begin(), password.end());
        return password;
    }
};

值得注意的一点是reverse是左闭右开