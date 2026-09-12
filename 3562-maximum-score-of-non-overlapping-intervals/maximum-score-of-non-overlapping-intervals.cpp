class Solution {
public:

    struct State {
        long long score = 0;
        int cnt = 0;
        array<int, 4> ids = {0, 0, 0, 0};
    };

    bool lexSmaller(State &a, State &b) {

        int len = min(a.cnt, b.cnt);

        for (int i = 0; i < len; i++) {
            if (a.ids[i] != b.ids[i])
                return a.ids[i] < b.ids[i];
        }

        return a.cnt < b.cnt;
    }

    State better(State &a, State &b) {

        if (a.score != b.score) {
            if (a.score > b.score)
                return a;
            return b;
        }

        if (lexSmaller(a, b))
            return a;

        return b;
    }

    State add(State s, int index, long long weight) {

        s.score += weight;

        int pos = s.cnt;

        while (pos > 0 && s.ids[pos - 1] > index) {
            s.ids[pos] = s.ids[pos - 1];
            pos--;
        }

        s.ids[pos] = index;
        s.cnt++;

        return s;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort according to left endpoint
        sort(a.begin(), a.end());

        vector<long long> start(n);

        for (int i = 0; i < n; i++) {
            start[i] = a[i][0];
        }

        // Find next non-overlapping interval
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {

            // Need next.left > current.right
            nxt[i] = upper_bound(
                start.begin(),
                start.end(),
                a[i][1]
            ) - start.begin();
        }

        /*
            dp[i][k] =
            best answer from i onwards
            when we can still choose k intervals
        */
        vector<array<State, 5>> dp(n + 1);

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Don't take interval i
                State skip = dp[i + 1][k];

                // Take interval i
                State take = dp[nxt[i]][k - 1];

                take = add(
                    take,
                    (int)a[i][3],
                    a[i][2]
                );

                dp[i][k] = better(skip, take);
            }
        }

        State ans = dp[0][4];

        vector<int> result;

        for (int i = 0; i < ans.cnt; i++) {
            result.push_back(ans.ids[i]);
        }

        return result;
    }
};