class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> blocked;
        
        // Encode (x, y) into one number
        auto encode = [](int x, int y) -> long long {
            return (static_cast<long long>(x) << 32) ^ (unsigned int)y;
        };

        for (auto& obs : obstacles) {
            blocked.insert(encode(obs[0], obs[1]));
        }

        // north, east, south, west
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int dir = 0;
        int x = 0, y = 0;
        int ans = 0;

        for (int cmd : commands) {
            if (cmd == -2) {
                dir = (dir + 3) % 4; // turn left
            } else if (cmd == -1) {
                dir = (dir + 1) % 4; // turn right
            } else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (blocked.count(encode(nx, ny))) {
                        break;
                    }

                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};