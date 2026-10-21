//
// Created by kubiii on 10/20/26.
//
#define ENTER 0
#define EXIT 1

vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
    const int n = arrival.size();
    vector<int> ans(n);
    queue<int> q[2];
    int i = 0; // next person to arrive
    int t = 0; // current  time
    int last = -1; // previous door used

    while (i < n || !q[ENTER].empty() || !q[EXIT].empty()) {
        // add arriving people
        while (i < n && arrival[i] <= t) {
            if (state[i] == ENTER) {
                q[ENTER].push(i);
            } else q[EXIT].push(i);
            // check next person
            i++;
        }
        if (q[ENTER].empty() && q[EXIT].empty()) {
            last = -1; // Door was idle
            if (i < n)
                t = arrival[i];
            continue;
        }

        // process queue because there're people waiting
        int chosen = -1;
        if (!q[ENTER].empty() && (q[EXIT].empty() || last == ENTER)) {
            chosen = ENTER;
        } else chosen = EXIT;

        // process person waiting on chosen queue
        int person = q[chosen].front();
        q[chosen].pop();

        ans[person] = t;
        last = chosen;

        t++;
    }
    return ans;
}