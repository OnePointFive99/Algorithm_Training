v1.0:先用一个栈来删除连续项，然后再用一个栈把顺序倒过来，再把第二个栈的数据放到string里面返回
时间空间都比较拉
class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> stk;
        for(int i = 0; i<s.size();i++)
        {
            if(!stk.empty()&&stk.top()==s[i]){
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }
        stack<int> stk2;
        while(!stk.empty())
        {
            stk2.push(stk.top());
            stk.pop();
        }
        string result;
        while(!stk2.empty())
        {
            result.push_back(stk2.top());
            stk2.pop();
        }
        return result;

    }
};

v2.0:可以用string的reverse来倒转，这样少声明一个栈
class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> stk;
        for(int i = 0; i<s.size();i++)
        {
            if(!stk.empty()&&stk.top()==s[i]){
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }
        string result;
        while(!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
};

v3.0:直接用string当栈就行，避免声明新的栈，牛

class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(auto c:s)
        {
            if(result.empty()||c!=result.back())
            {   
                result.push_back(c);
            }
            else
            {
                result.pop_back();
            }
        }
        return result;

    }
};