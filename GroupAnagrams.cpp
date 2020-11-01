// Approach 1: Generate Key using count sort.
//112 / 112 test cases passed.
//Status: Accepted
//Runtime: 64 ms
//Memory Usage: 24.3 MB

class Solution {
    string generateKey(string s) { //Count Sort
        vector<int> v(26, 0);
        for(char c: s) {
            v[c-'a']++;
        }
        
        string key;
        for(int i=0; i<v.size(); i++) {
            key += string(v[i], i+'a');
        }
        
        return key;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;
        
        for(int i=0; i<strs.size(); i++) {
            m[generateKey(strs[i])].push_back(strs[i]); 
            //cout << "Key:" << generateKey(strs[i]) << " Val:" << strs[i] << endl;
        }
        
        vector<vector<string>> ans;
        
        for(auto kvp: m) {
            ans.push_back(kvp.second);
        }
        
        return ans;
    }
};

==============================================================================================================

// Approach 2: Generate Key using #separated frequencies. 
//112 / 112 test cases passed.
//Status: Accepted
//Runtime: 88 ms
//Memory Usage: 29.3 MB

class Solution {
    string generateKey(string &s) { //#separated keys
        vector<int> v(26, 0);
        for(char &c: s) {
            v[c-'a']++;
        }
        
        string key;
        for(int x:v) {
            //cout << x;
            key+= to_string(x)+"#";
        }
        //cout << endl;
        
        return key;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> uom;
        
        for(int i=0; i<strs.size(); i++) {
            uom[ generateKey(strs[i]) ].push_back( strs[i] );
            //cout << "Key:" << generateKey(strs[i]) << " Val:" << strs[i] << endl;
        }
        
        vector<vector<string>> ans;
        for(auto kvp: uom) {
            ans.push_back(kvp.second);
        }
        
        return ans;
    }
};
