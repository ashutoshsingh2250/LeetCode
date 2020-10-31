class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> v;
        
        if(p.size()>s.size()) return v;
        
        for(int i=0; i<s.size()-p.size()+1; i++) {
            //map<char, int> umap;
            vector<int> umap(26, 0);
            for(int m=0;m<p.size();m++) {
                //umap.insert({s[m], ++umap[s[m]]});
                ++umap[p[m]-'a'];
            }
            
            /*for(int m=0;m<p.size();m++) {
                cout << s[m] <<" "<< umap[s[m]] << endl;
            }*/
                        
            bool flag=true;
            int last=i+p.size();
            for(int j=i; j<last; j++) {
                //cout << s[j] << " " << umap[s[j]-'a'] << "\t";
                if(umap[s[j]-'a']==0) {
                    flag=false;
                    break;
                } else {
                    umap[s[j]-'a']--;
                    flag=true;
                }
                
            }
            cout << endl;
            if(flag==true)
                v.push_back(i);   
        }        
        return v;
    }
};
