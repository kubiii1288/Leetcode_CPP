//
// Created by Anh Le on 8/19/26.
//

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int threshHold = intervals[0][1];
    int erase = 0;
    for (int i = 1 ; i < intervals.size(); i++)
    {
        if (intervals[i][0] < threshHold)
        {
            erase++;
            threshHold = min(threshHold, intervals[i][1]);
        } else threshHold = intervals[i][1];
    }
    return erase;
}