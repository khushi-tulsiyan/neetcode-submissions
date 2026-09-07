class Solution {
public:
    vector<int> edit(int start, int len, const string& s2) {
        vector<int> cnt(26, 0);
        for (int j = start; j < start + len; j++)
            cnt[s2[j] - 'a']++;
        return cnt;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<int> s1Count(26, 0);
        for (int j = 0; j < n; j++) s1Count[s1[j] - 'a']++;

        int i = 0;
        bool ans = false;
        while (!ans && i <= m - n) {
            ans = (s1Count == edit(i, n, s2));
            i++;
        }
        return ans;
    }
};