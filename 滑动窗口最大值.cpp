v1.0:直接双指针 固定滑动窗口 暴力超时
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        
        for(int left = 0, right = left + k - 1;right<nums.size();left++, right++)
        {
            int maxNum = nums[left];
            for(int i = left;i<=right;i++)
            {
                if(nums[i]>maxNum)
                {
                    maxNum = nums[i];
                }
            }
            result.push_back(maxNum);
        }
        return result;
    }
};

v2.0:使用定义的单调队列，单调队列需要用deque进行定义，因为需要从队列尾部取出元素，普通队列做不到这一点
在遍历时，先取出窗口外的元素，如果是队头元素则去除，这里如果不是队头元素就先留里面
如果是新元素与单调队列头进行比较，大于则清空队列，队列头改为新元素，小于则再比较是否大于单调队列尾
如果也不大于尾就加进来，大于尾就从尾部去掉小于新元素的值，再把新元素加进来
class Solution {
public:
    struct MyQueue
    {
        public:
        dequeuint> q;

        void pop(int value)
        {
            if(!q.empty()&&value==q.front())
            {
                q.pop_front();
            }
        }
        void push(int value)
        {
            while(!q.empty()&&value>q.back())
            {
                q.pop_back();
            }
            q.push_back(value);
        }

        int getMax()
        {
            return q.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> result;
        for(int i = 0; i<k;i++)
        {
            q.push(nums[i]);
        }
        result.push_back(q.getMax());
        for(int i = k; i< nums.size();i++)
        {
            q.pop(nums[i-k]);
            q.push(nums[i]);
            result.push_back(q.getMax());
        }
        return result;
    }
};