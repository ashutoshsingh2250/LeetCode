class Solution {
public:
    int leastBricks(vector<vector<int>>& a) {
        if(a.empty()) return 0;
        int single_brick_stacked=1;
        for(vector<int> v: a) {
            if(v.size()!=1) {
                single_brick_stacked=0;
            }
        }
        if(single_brick_stacked) return a.size();
        
        //vector<vector<int>> brick_matrix(a.size());
        vector<vector<int>> end_matrix(a.size());
        vector<string> vs(a.size(), "");
        
        //string way for constructing brick_matrix i.e vs .
        for(int i=0; i<a.size(); i++) {
            for(int j=0; j<a[i].size(); j++) {
                int n=a[i][j];                
                string ss=to_string(n);
                vs[i] += string(n-1, ss[0])+"*";
            }
        }
        //for(string s : vs) cout << s << endl;
        
        int i=0;
        for(string s: vs) { // constructing end_matrix
            for(char c: s) {
                if(c=='*')
                    end_matrix[i].push_back(0);    
                else 
                    end_matrix[i].push_back(1);    
            }
            i++;
        }
        
        /*for(vector v:end_matrix) { // for printing end_matrix
            for(int x:v) {
                cout << x << " ";
            }
            cout << endl;
        }*/
        
        int min_brick=INT_MAX, sum, col=end_matrix[0].size()-1, row=end_matrix.size();
        for(int i=0; i<col; i++) { // calculating min_brick from end_matrix
            sum=0;
            for(int j=0; j<row; j++) {
                sum+=end_matrix[j][i];
            }
            if(sum < min_brick)   min_brick=sum;
        }
        
        return min_brick;
    }
};
