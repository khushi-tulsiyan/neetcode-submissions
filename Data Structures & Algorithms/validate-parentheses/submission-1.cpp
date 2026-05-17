class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        std::unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char c: s){
            if(mp.count(c)){
                if(!st.empty() && st.top() == mp[c]){
                    st.pop();
                } else{
                    return false;
                }
            } else{
                    st.push(c);
                }
        }
        return st.empty();
    }
};
