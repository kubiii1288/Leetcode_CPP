//
// Created by Anh Le on 8/9/26.
//
string predictPartyVictory(string senate) {
    const int N = senate.size();
    queue<int> rQueue, dQueue;
    for (int i = 0; i < senate.size(); i++)
    {
        if (senate[i] == 'R')
            rQueue.push(i);
        else dQueue.push(i);
    }
    while (!rQueue.empty() && !dQueue.empty())
    {
        if (rQueue.front() < dQueue.front())
        {
            dQueue.pop();
            rQueue.push(rQueue.front()+ N);
            rQueue.pop();
        } else
        {
            rQueue.pop();
            dQueue.push(dQueue.front() + N);
            dQueue.pop();
        }
    }
    if (rQueue.size()) return "Radiant";
    return "Dire";
}