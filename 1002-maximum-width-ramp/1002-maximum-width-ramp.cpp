class Solution {
public:
    class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (r < low || high < l)
            return INT_MIN;

        // complete overlap
        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<int> ind;
        for(int i=0;i<nums.size();i++){
            ind.push_back(temp[i].second);
        }
        SGTree s(nums.size()+1);
        s.build(0,0,nums.size()-1,ind);
        int ans=0;
        for(int i=0;i<temp.size();i++){
            int inx=s.query(0,0,nums.size()-1,i+1,nums.size()-1);
            if(inx>=0){
            ans=max(ans,inx-temp[i].second);
            }
        }
        return ans;
    }
};