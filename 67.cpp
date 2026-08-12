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
    {

        int cnt_s[size_of_alphabet] = {0};
        int cnt_t[size_of_alphabet] = {0};

        for (auto c : t)
        {
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

        string ans = "";
        while (right < (int)s.length())
        {
            //
            cout << "\nRound in Left and Right: " << left << " r: " << right << "\n";
            //
            if (left > right)
            {
                right = left;
                memset(cnt_s, 0, sizeof(cnt_s));
                continue;
            }
            if (cmp(cnt_s, cnt_t))
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
                    cnt_s[(int)s[left]]--;
                }
                left++;
                //
                cout << "valid, " << len_lr << "\n"
                     << "New L: " << left << "\n";
                //
            }
            else
            {
                right++;
                cnt_s[(int)s[right]]++;

                //
                cout << "Not valid, " << "New R: " << right << "\n";
                //
            }
        }
        if (getans)
        {
            ans = s.substr(ans_left, ans_right - ans_left + 1);
        }
        return ans;
    }
};