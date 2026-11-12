//
// Created by kubiii on 10/22/26.
//

int minimumTime(vector<int>& jobs, vector<int>& workers) {
    const int n = jobs.size();
    sort(jobs.begin(), jobs.end(), greater<int>());
    sort(workers.begin(), workers.end(), greater<int>());
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, jobs[i]-1 + workers[i]/workers[i]);
    }
    return ans;
}