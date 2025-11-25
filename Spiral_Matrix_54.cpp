//
// Created by Anh Le on 10/4/25.
//
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();

    enum DIRECTION { RIGHT, LEFT, UP, DOWN };
    DIRECTION current = RIGHT;

    int left_w = 0;
    int right_w = n;
    int up_w = 0;
    int down_w = m;

    while (ans.size() < m * n) {
        if (current == RIGHT) {
            for (int i = up_w; i < right_w; i++) {
                int numb = matrix[up_w][i];
                ans.push_back(numb);
            }
            right_w--;
            current = DOWN;
        } else if (current == DOWN) {
            for (int i = up_w + 1; i < down_w; i++) {
                int numb = matrix[i][right_w];
                ans.push_back(numb);
            }
            down_w--;
            current = LEFT;
        } else if (current == LEFT) {
            for (int i = right_w - 1; i >= left_w; i--) {
                int numb = matrix[down_w][i];
                ans.push_back(numb);
            }
            left_w++;
            current = UP;
        } else if (current == UP) {

            for (int i = down_w - 1; i > up_w; i--) {
                int numb = matrix[i][left_w - 1];
                ans.push_back(numb);
            }
            up_w++;
            current = RIGHT;
        }
    }
    return ans;
}