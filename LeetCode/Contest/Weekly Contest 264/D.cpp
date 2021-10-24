#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n + 1);

        // The in-degree of each course
        vector<int> deg(n + 1);
        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0], v = relations[i][1];
            g[u].push_back(v);

            // Every relation increases the in-degree of course v by 1
            deg[v]++;
        }

        // records the start time and finish time of each course
        vector<int> start(n + 1), finish(n + 1);

        queue<vector<int>> q;
        for (int i = 1; i <= n; i++) {
            // {courseID, courseFinishTime}
            if (!deg[i]) q.push({i, time[i - 1]});
        }

        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            int u = v[0], ft = v[1];
            finish[u] = ft;
            for (int v : g[u]) {
                // One preCourse of course v is finished
                deg[v]--;
                // Update the valid start time of course v
                start[v] = max(start[v], ft);
                // If all the prevCourses are finished, we can take course v now
                if (!deg[v]) q.push({v, start[v] + time[v - 1]});
            }
        }

        return *max_element(finish.begin(), finish.end());
    }
};