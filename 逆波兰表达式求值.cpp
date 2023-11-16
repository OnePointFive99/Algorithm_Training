v1.0:其实并不难   主要是string向整数转换：stoll不知道，这下学会了，再一个就是明明可以用char，却用的string
class Solution {
public:
    stack<long long> stk;

    void calculate(string calSymbol)
    {   
        long long num1 = 0, num2 = 0;
        if(!stk.empty())
        {
            num2 = stk.top();
            stk.pop();
            num1 = stk.top();
            stk.pop();
        }
        if(calSymbol=="+")
        {
            stk.push(num1+num2);
        }
        else if(calSymbol=="-")
        {
            stk.push(num1-num2);
        }
        else if(calSymbol=="*")
        {
            stk.push(num1*num2);
        }
        else if(calSymbol=="/")
        {
            stk.push(num1/num2);
        }
    }

    int evalRPN(vector<string>& tokens) {
        
        for(auto s:tokens)
        {
            if(s=="+"||s=="-"||s=="*"||s=="/")
            {
                calculate(s);
            }
            else{
                stk.push(stoll(s));
            }
        }
        return stk.top();
    }
};