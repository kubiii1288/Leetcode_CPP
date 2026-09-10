class WordDictionary
{
    struct DictNode
    {
        DictNode* children[26] = {nullptr};
        bool isEnd = false;
    };

public:
    DictNode* root;

    WordDictionary()
    {
        root = new DictNode();
    }

    void addWord(string word)
    {
        DictNode* current = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (current->children[index] == nullptr)
                current->children[index] = new DictNode();
            current = current->children[index];
        }
        current->isEnd = true;
    }

    bool search(string word)
    {
        return bfs(word);
    }

private:
    bool dfs(string& word, int index, DictNode* currentNode)
    {
        if (currentNode == nullptr) return false;
        if (index == word.size())
            return currentNode->isEnd;
        char c = word[index];

        if (c == '.')
        {
            for (DictNode* child : currentNode->children)
            {
                if (dfs(word, index + 1, child))
                    return true;
            }
            return false;
        }
        else
        {
            int i = c - 'a';
            if (currentNode->children[i] != nullptr)
                return dfs(word, index + 1, currentNode->children[i]);
            return false;
        }
    }

    bool bfs(string& word)
    {
        if (root == nullptr) return false;
        queue<pair<DictNode*, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            DictNode* currentNode = q.front().first;
            int index = q.front().second;
            q.pop();
            if (currentNode == nullptr) continue;
            if (index == word.size())
            {
                if (currentNode->isEnd) return true;
                continue;
            }

            if (word[index] == '.')
            {
                for (DictNode* child : currentNode->children)
                {
                    if (child != nullptr)
                        q.push({child, index + 1});
                }
            }
            else
            {
                int i = word[index] - 'a';
                if (currentNode->children[i] != nullptr)
                    q.push({currentNode->children[i], index + 1});
            }
        }
        return false;
    }
};
