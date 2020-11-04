// stack question
class Solution {
public:
    string removeDuplicates(string S) {
        
        stack<char> s;
        string ans="";
        
        
        for(int i=0; i<S.length(); i++) {
            
            if(s.empty())   s.push(S[i]);
            else if(S[i]!=s.top())   s.push(S[i]);
            else if(S[i]==s.top())  s.pop();
            
        }
        
        while(!s.empty()) {
            ans+=s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
