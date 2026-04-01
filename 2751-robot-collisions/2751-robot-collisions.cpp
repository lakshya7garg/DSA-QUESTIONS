class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        // sort robots by position
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        stack<int> st; // stores indices of robots moving right
        
        for (int id : idx) {
            if (directions[id] == 'R') {
                st.push(id);
            } else {
                // current robot moving left
                while (!st.empty() && healths[id] > 0) {
                    int topId = st.top();
                    
                    if (healths[topId] < healths[id]) {
                        // right robot dies
                        st.pop();
                        healths[id]--;
                        healths[topId] = 0;
                    }
                    else if (healths[topId] > healths[id]) {
                        // left robot dies
                        healths[topId]--;
                        healths[id] = 0;
                    }
                    else {
                        // both die
                        st.pop();
                        healths[topId] = 0;
                        healths[id] = 0;
                    }
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) ans.push_back(healths[i]);
        }
        
        return ans;
    }
};