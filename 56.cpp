class Solution
{
private:
    bool cmp(vector<int> &Ta, vector<int> &Tb)
    {
        assert(Ta.size() >= 1);
        assert(Tb.size() >= 1);

        return Ta[0] < Tb[0];
        // no shifting T
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);

        assert(intervals.size() >= 1);

        int now_l = intervals[0][0];
        int now_r = intervals[0][1];
        vector<vector<int>> ans;
        vector<int> now_lr(2);
        nowlr = {now_l, now_r};
        for (auto it : intervals)
        {
            const int& l = it[0];
            const int& r = it[1];
            if (l > now_r)
            {
                ans.push_back(nowlr);
                nowlr[0] = l;
                nowlr[1] = r;
            }
            else
            {
                nowlr[1] = max(nowlr[1] , r);
            }
        }
        ans.push_back(nowlr);
        // get in the last nowlr
    }
};