struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode()
    {
        this->isEnd = false;
    }
};

TrieNode* root;

void insert(string word)
{
    TrieNode* current = root;
    for (char c : word)
    {
        if (current->children.find(c) == current->children.end())
        {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEnd = true;
}

int N, M;

void dfs(int r, int c, TrieNode* node, vector<string>& ans, vector<vector<char>>& board, vector<vector<bool>>& visited,
         string& currentWord)
{
    if (r < 0 || r >= N || c < 0 || c >= M) return;
    if (visited[r][c]) return;
    char currentChar = board[r][c];
    if (node->children.find(currentChar) == node->children.end()) return;
    node = node->children[currentChar];
    currentWord.push_back(currentChar);
    if (node->isEnd)
    {
        ans.push_back(currentWord);
        node->isEnd = false;
    }
    visited[r][c] = true;
    dfs(r+1, c, node, ans, board, visited, currentWord);
    dfs(r, c-1, node, ans, board, visited, currentWord);
    dfs(r-1, c, node, ans, board, visited, currentWord);
    dfs(r, c+1, node, ans, board, visited, currentWord);
    currentWord.pop_back();
    visited[r][c] = false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
    root = new TrieNode();
    for (string& s : words)
        insert(s);
    N = board.size();
    M = board.back().size();
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<string> ans;
    string currentWord;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dfs(i, j, root, ans, board, visited, currentWord);
        }
    }
    return std::move(ans);
}
