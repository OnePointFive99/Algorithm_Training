class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            int sum = 0;
            while(n){
                int d = n%10;
                sum+=d*d;
                n/=10;
            }
            if(s.find(sum)!=s.end()){
                return false;
            }
            n = sum;
            s.insert(sum);
        }
        return true;
    }
};

v2.0:好像声明了多余的tmp了
bool isHappy(int n) {
    unordered_set<int> set1;
    while (n != 1)
    {
        int tmp = n;
        int sum = 0;
        while (tmp != 0)
        {
            int t = tmp % 10;
            sum += t * t;
            tmp /= 10;
        }
        n = sum;
        if (set1.count(n))
            return false;
        set1.insert(n);
    }
    return true;
}
v3.0:
bool isHappy(int n) {
    unordered_set<int> set1;
    while (n != 1)
    {
        set1.insert(n);
        int sum = 0;
        while (n != 0)
        {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        n = sum;
        if (set1.count(n))
            return false;
    }
    return true;
}