v1.0：想先用排序来解决一下，在网上看到了如何把map转换为vector进行排序：创建一个以pair为元素的vector，再使用自定义的sort进行排序即可  

class Solution {
public:
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        
        for(auto num:nums)
        {
            umap[num]++;
        }
        vector<pair<int, int>> forSort(umap.begin(), umap.end());
        sort(forSort.begin(), forSort.end(), cmp);
        vector<int> result;
        while(k--)
        {
            result.push_back(forSort[k].first);
        }
        return result;
    }
};

v2.0：使用`priority_queue`，这家伙居然要三个参数：元素类型、所适配的容器类型、cmp规则


class Solution {
public:
    bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto num:nums)
        {
            umap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pri_que(cmp);

        for(unordered_map<int, int>::iterator it = umap.begin(); it!=umap.end(); it++)
        {
            pri_que.push(*it);
            if(pri_que.size()>k)
            {
                pri_que.pop();
            }
        }
        vector<int> result;
        while(k--)
        {
            result.push_back(pri_que.top().first);
            pri_que.pop();
        }
        return result;
    }
};

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}
class Solution {
public:
    

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    for (int i : nums)
    {
        umap[i]++;
    }
    vector<pair<int, int>> forSort(umap.begin(), umap.end());
    sort(forSort.begin(), forSort.end(), cmp);
    vector<int> ret;
    for (int i = 0; i < k; i++)
    {
        ret.emplace_back(forSort[i].first);
    }
    return ret;
}
};