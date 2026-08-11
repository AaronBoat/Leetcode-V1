class Solution
{
private:
    // bool cmp(vector<int> &Ta, vector<int> &Tb)
    // {
    //     assert(Ta.size() >= 1);
    //     assert(Tb.size() >= 1);

    //     return Ta[0] < Tb[0];
    //     // no shifting T
    // }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &Ta, const vector<int> &Tb)
             { return Ta[0] < Tb[0]; });

        assert(intervals.size() >= 1);

        // int now_l = intervals[0][0];
        // int now_r = intervals[0][1];
        vector<vector<int>> ans;
        ans.reserve(intervals.size());
        vector<int> now_lr(2);
        now_lr = {intervals[0][0], intervals[0][1]};
        for (auto& it : intervals)
        {
            const int &l = it[0];
            const int &r = it[1];
            int &now_l = now_lr[0];
            int &now_r = now_lr[1];
            if (l > now_r)
            {
                ans.push_back(now_lr);
                now_l = l;
                now_r = r;
            }
            else
            {
                now_r = max(now_r, r);
            }
        }
        ans.push_back(now_lr);
        // get in the last now_lr
        return ans;
    }
};