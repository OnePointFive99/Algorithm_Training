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