初版代码：根据自己思路实现的，确保pop时一个队列为空，然后将另一个队列的元素都移动到该队列，只留下最后一个元素

```cpp
v1.0
class MyStack {
public:
    queue<int, deque<int>> q1;
    queue<int, deque<int>> q2;

    MyStack() {

    }
    
    void push(int x) {
        if(q1.empty())
        {
            q2.push(x);
        }
        else
        {
            q1.push(x);
        }
    }
    int q2q(queue<int> &q1, queue<int> &q2){
        int ret, size = q1.size()-1;
        //将q1的元素移到q2，仅剩队尾元素留在q1,返回队尾元素的值
        while(size--)
            {
                q2.push(q1.front());
                q1.pop();
            }
            ret = q1.front();
        return ret;
    }
    
    int pop() {
        int num;
        if(q1.empty())
        {
            num = q2q(q2, q1);
            q2.pop();
            return num;
        }
        else
        {
            num = q2q(q1, q2);
            q1.pop();
            return num;
        }
    }
    
    int top() {
        int num = this->pop();
        this->push(num);
        return num;
    }
    
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

v2.0：

第二版代码，使用了q1 = q2；再清空q2的做法，避免了很多q1和q2来回交换的做法，明确了q1和q2的职责

```cpp
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
    queue<int, deque<int>> q1;
    queue<int, deque<int>> q2;//辅助队列

    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() 
    {
        int num, size = q1.size()-1;
        //将q1的元素移到q2，仅剩队尾元素留在q1,返回队尾元素的值
        while(size--)
        {
            q2.push(q1.front());
            q1.pop();
        }
        num = q1.front();
        q1.pop();
        q1 = q2;
        while(!q2.empty()){
            q2.pop();
        }
        return num;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

v3.0:第三版代码，去掉了队列2的使用，将队列除了尾部元素之外重新入队，即可将原本的队尾元素移动到队首，从而去掉该元素。
class MyStack {
public:
    queue<int, deque<int>> q1;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() 
    {
        int num = q1.back(), size = q1.size()-1;
        //将q1的元素移到q1尾部，仅剩原本的队尾元素留在q1头部,再pop
        while(size--)
        {
            q1.push(q1.front());
            q1.pop();
        }
        q1.pop();
        return num;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */