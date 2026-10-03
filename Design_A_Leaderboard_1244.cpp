//
// Created by Anh Le on 9/22/26.
//
class Leaderboard {
public:
    //to store player's score
    unordered_map<int,int> playerScore;
    // to store the freq of specific score
    map<int,int,greater<int>> freq;
    Leaderboard() {
    }

    void addScore(int playerId, int score) {
        if (playerScore[playerId])
        {
            freq[playerScore[playerId]]--;
            playerScore[playerId] += score;
            freq[playerScore[playerId]]++;
        } else
        {
            freq[score]++;
            playerScore[playerId] = score;
        }
    }

    int top(int K) {
        int sum = 0;
        for (map<int,int>::iterator it = freq.begin(); it != freq.end() && K > 0; ++it)
        {
            if (it->second >= K)
            {
                sum += (K * it->first);
                K = 0;
            } else
            {
                sum += (it->first * it->second);
                K -= it->second;
            }
        }
        return sum;
    }

    void reset(int playerId) {
        freq[playerScore[playerId]]--;
        playerScore[playerId] = 0;
    }
};

