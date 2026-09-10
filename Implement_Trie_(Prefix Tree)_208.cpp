struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode()
    {
        this->isEnd = false;
    }
};

class Trie
{
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }

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

    bool search(string word)
    {
        TrieNode* node = trace(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return trace(prefix) != nullptr;
    }

    TrieNode* trace(string word)
    {
        TrieNode* current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
                return nullptr;
            current = current->children[c];
        }
        return current;
    }
};
