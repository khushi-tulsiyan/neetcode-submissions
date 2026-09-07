class Solution {
public:
    //bool allzeroes()
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0;
        int n = s2.length(), k = s1.length();
        vector<int>temp1(26, 0);
        for(char ch : s1)
        {
            temp1[ch - 'a']++;
        }
        vector<int>temp2(26, 0);
        while(right < n)
        {
            temp2[s2[right]- 'a']++;

            if((right - left + 1) == k)
            {
                if(temp1 == temp2) return true;
                temp2[s2[left]-'a']--;
                left++;
            }
            right++;
            
        }
        return false;
    }
};
