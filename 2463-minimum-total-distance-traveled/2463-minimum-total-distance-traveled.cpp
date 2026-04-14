class Solution {
public:
    static constexpr long long INF = 4e18;
    vector<long long> robots;
    vector<vector<int>> factories;
    vector<vector<long long>> memo;
    int n, m;

    long long solve(int i, int j) {
        if (i == n) return 0;          // all robots repaired
        if (j == m) return INF;        // no factories left

        if (memo[i][j] != -1) return memo[i][j];

        long long ans = solve(i, j + 1);   // option 1: skip current factory

        long long dist = 0;
        int pos = factories[j][0];
        int limit = factories[j][1];

        // option 2: assign next k robots to current factory
        for (int k = 0; k < limit && i + k < n; k++) {
            dist += llabs(robots[i + k] - pos);
            long long next = solve(i + k + 1, j + 1);
            if (next != INF) {
                ans = min(ans, dist + next);
            }
        }

        return memo[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        n = robot.size();
        m = factory.size();

        robots.assign(robot.begin(), robot.end());
        factories = factory;

        memo.assign(n, vector<long long>(m, -1));

        return solve(0, 0);
    }
};