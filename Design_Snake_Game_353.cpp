//
// Created by Anh Le on 9/21/26.
//

class SnakeGame {
public:
    deque<pair<int, int>> snake;
    vector<vector<int>> foods;
    vector<bool> occupied;
    int W, H;
    int foodIndex;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        snake.push_back({0, 0});
        W = width;
        H = height;
        foods = food;
        foodIndex = 0;
        occupied.resize(W * H, false);
        occupied[positionHash(0, 0)] = true;
    }

    int move(string direction) {
        auto [r, c] = snake.front();

        if (direction == "U") {
            r--;
        } else if (direction == "D") {
            r++;
        } else if (direction == "L") {
            c--;
        } else {
            c++;
        }
        if (r < 0 || r >= H || c < 0 || c >= W)
            return -1;
        bool getFood = false;
        if (foodIndex < foods.size() && r == foods[foodIndex][0] &&
            c == foods[foodIndex][1])
            getFood = true;
        if (!getFood) {
            occupied[positionHash(snake.back().first, snake.back().second)] =
                false;
            snake.pop_back();
        }
        if (occupied[positionHash(r, c)])
            return -1;

        snake.push_front({r, c});
        occupied[positionHash(r, c)] = true;
        if (getFood)
            foodIndex++;
        return foodIndex;
    }

private:
    int positionHash(int r, int c) const { return r * W + c; }
};
