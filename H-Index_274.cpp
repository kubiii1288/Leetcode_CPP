//
// Created by Anh Le on 9/17/25.
//
int hIndex(vector<int>& citations)
{
    sort(citations.begin(), citations.end(), greater<int>());
    cout << endl;
    int left = 0;
    int right = citations.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + (right - left) / 2);
        if (citations[mid] == mid + 1)
        {
            return min(mid + 1, citations[mid]);
        }
        else if (citations[mid] > mid + 1)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (right < 0)
        right = 0;
    return min(right + 1, citations[right]);
}
