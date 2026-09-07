class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        vector<int>countS1(26,0);
        vector<int>countS2(26,0);

        for(int i = 0; i<s1.length(); i++){
            countS1[s1[i] - 'a']++;
            countS2[s2[i] - 'a']++;
        }

        int matches = 0;

        for(int i = 0; i<26;i++){
            if(countS1[i] == countS2[i]){
                matches++;
            }
        }

        int l = 0;
        for(int r = s1.length(); r<s2.length(); r++){
            if(matches == 26){
                return true;
            }

            int ind = s2[r] - 'a';
            countS2[ind]++;

            if(countS1[ind] == countS2[ind]){
                matches++;
            } else if(countS1[ind]+1 == countS2[ind]){
                matches--;
            }

            ind = s2[l] - 'a';
            countS2[ind]--;

            if(countS1[ind] == countS2[ind]){
                matches++;
            } else if(countS1[ind] - 1 == countS2[ind]){
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};
