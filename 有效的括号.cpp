v1.0:比较憨憨，括号匹配不是直接==..
class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(auto c:s){
            if(!stk.empty()&&stk.top()=='('&&c==')')
            {
                stk.pop();
            }
            else if(!stk.empty()&&stk.top()=='{'&&c=='}')
            {
                stk.pop();
            }
            else if(!stk.empty()&&stk.top()=='['&&c==']')
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        return stk.empty();

    }
};

v2.0:这样直接push要匹配的确实也挺聪明
class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(auto c:s){
            if(c=='{')
            {
                stk.push('}');
            }
            else if(c=='(')
            {
                stk.push(')');
            }
            else if(c=='[')
            {
                stk.push(']');
            }
            else if(!stk.empty()&&c==stk.top())
            {
                stk.pop();
            }
            else{
                return false;
            }
        }
        return stk.empty();

    }
};