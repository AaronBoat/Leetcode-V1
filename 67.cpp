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
        }

        int left = 0;
        int right = 0;
        int min_len_lr = 2e5;
        int ans_left = 0;
        int ans_right = 0;

        string ans = "";
        while (right < t.length())
        {
            if (left > right)
            {
                right = left ;
                memset(cnt_s, 0, sizeof(cnt_s));
                continue;
            }
            if (cmp(cnt_s, cnt_t))
            {
                int len_lr = right - left;
                if (len_lr < min_len_lr)
                {
                    min_len_lr = len_lr;
                    ans_left = left;
                    ans_right = right;
                }
                cnt_s[s[left]]--;
                left++;
            }
            else
            {
                right++;
                cnt_s[s[right]]++;

            }

        }
        ans = s.substr(ans_left,ans_right - ans_left);
        return ans;
    }
};