

周赛题：最后几分钟写了下这个逻辑，直接模拟的，然后说是res的范围不够大
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long max = 0;
        for(long long x = 0; x <(long long)pow(2,n);x++)
        {
            unsigned long long res = (unsigned long long)(a ^ x) * (b ^ x);
            if(res > max)max = res;
        }
        return max %(long long)(pow(10,9)+7);
    }
};

v2.0：把long long 换成了__int128，够大了但是超时了，说明直接模拟是不行的
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        __int128 max = 0;
        for(long long x = 0; x <(long long)pow(2,n);x++)
        {
            __int128 res = (__int128)(a ^ x) * (b ^ x);
            if(res > max)max = res;
        }
        return max %(long long)(pow(10,9)+7);
    }
};

v3.0:大佬写的
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const int mod = 1000000007;
        __int128 best = __int128(a) * b;
        for(int i = n - 1; i >= 0; --i) {
            long long u = 1LL << i;
            __int128 now = __int128(a ^ u) * (b ^ u);
            if(now > best) {
                a ^= u;
                b ^= u;
                best = now;
            }
        }
        return best % mod;
    }
};

v4.0:
总体来说是个贪心算法，for循环遍历的是位次，每次最大值更新后将产生贡献的位置1
这是由于x是个仅有1位为1的二进制数字，所以置1可以使得x的0和a的1异或输出1，相当于记录了贡献
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        __int128 max = __int128(a) * b;
        for(int x = 0; x <n; x++)
        {
            long long u = 1LL <<x;//只有1位为1
            __int128 res = (__int128)(a ^ u) * (b ^ u);
            if(res > max)
            {
                max = res;
                a ^= u;//将该位置为1，使其参与后续异或运算
                b ^= u;
            }
        }
        return max %(__int128)(1e9+7);
    }
};