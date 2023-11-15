

v1.0:
30分钟写出来的，主要是api不是很了解，重点是pop的逻辑，
要检查输出栈的内容，避免插队
class MyQueue {
public:
        stack<int, deque<int>> s1;
        stack<int, deque<int>> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int num;

        if(!s2.empty())
        {
            num = s2.top();
            s2.pop();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            num = s2.top();
            s2.pop();
        }
        return num;
    }
    
    int peek() {
        if(!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return s2.empty()&&s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

v2.0:pop和peek有很高的代码重用率，在工业级别代码开发中，最忌讳的就是 实现一个类似的函数，直接把代码粘过来改一改就完事了。

这样的项目代码会越来越乱，一定要懂得复用，功能相近的函数要抽象出来，不要大量的复制粘贴，很容易出问题！（踩过坑的人自然懂）

工作中如果发现某一个功能自己要经常用，同事们可能也会用到，自己就花点时间把这个功能抽象成一个好用的函数或者工具类，不仅自己方便，也方便了同事们。
class MyQueue {
public:
        stack<int, deque<int>> s1;
        stack<int, deque<int>> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int num;

        if(!s2.empty())
        {
            num = s2.top();
            s2.pop();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            num = s2.top();
            s2.pop();
        }
        return num;
    }
    
    int peek() {
        int num = this->pop();
        s2.push(num);
        return num;
    }
    
    bool empty() {
        return s2.empty()&&s1.empty();
    }
};
