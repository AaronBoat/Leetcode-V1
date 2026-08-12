class Solution
{
private:
    static constexpr int size_of_alphabet = 128;
    bool cmp(int *cnt_s, int *cnt_t)
    {
        for (int i = 0; i < size_of_alphabet; i++)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }
        return true;
    }
    // void en_empty(int *cnt)
    // {
    //     for(int i = 0 ; i < )
    // }

public:
    string minWindow(string s, string t)
    // TODO:DEBUG need_kinds 和 valid 来对比，显示是不是所有需要的字母都满足要求；一次只能改变一个字母的valid，而不是全局
    {
        constexpr bool test = true;

        int cnt_s[size_of_alphabet] = {0};
        int cnt_t[size_of_alphabet] = {0};

        int need_kinds = 0;
        for (auto c : t)
        {
            if (cnt_t[(int)c] == 0)
            {
                need_kinds++;
            }
            cnt_t[(int)c]++;

            //
            // cout << c<<": "<<cnt_t[c]<<"\n";
            //
        }

        int left = -1;
        int right = -1;
        int min_len_lr = 2e5;
        int ans_left = 0;
        int ans_right = 0;
        bool getans = false;
        int valid = 0;

        string ans = "";
        while (right < (int)s.length())
        {
            //
            if (test)
                cout << "\nRound in Left and Right: " << left << " r: " << right << "\n";
            //
            if (left > right)
            {
                right = left;
                memset(cnt_s, 0, sizeof(cnt_s));
                continue;
            }
            if (valid == need_kinds)
            {
                getans = true;
                int len_lr = right - left;
                if (len_lr < min_len_lr)
                {
                    min_len_lr = len_lr;
                    ans_left = left;
                    ans_right = right;
                }
                if (left >= 0)
                {
                    int &delete_left = cnt_s[(int)s[left]];
                    int &need_left = cnt_t[(int)s[left]];
                    if (need_left > 0 && delete_left == need_left)
                    {
                        valid--;
                    }
                    delete_left--;
                    // if (delete_left > 0)
                }
                left++;
                // //
                if (test)
                    cout << "valid, " << len_lr << "\n"
                         << "New L: " << left << "\n";
                // //
            }
            else
            {
                right++;
                int &add_right = cnt_s[(int)s[right]];
                add_right++;
                int &need_right = cnt_t[(int)s[right]];
                if (cnt_t[(int)s[right]] > 0 && add_right == need_right)
                {
                    valid++;
                }
                // //
                if (test)
                    cout << "Not valid, " << "New R: " << right << "\n";
                // //
            }
        }
        if (getans)
        {
            ans = s.substr(ans_left, ans_right - ans_left + 1);
        }
        return ans;
    }
};