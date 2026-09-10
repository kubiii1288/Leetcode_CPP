//
// Created by Anh Le on 8/16/26.
//

class Trie {
    struct TrieNode
    {
        TrieNode* child[26];
        bool isEnd;

        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
            isEnd = false;
        }
    };
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* temp = root;
        for (char c : word)
        {
            if (temp->child[c-'a'] == nullptr)
            {
                temp->child[c-'a'] = new TrieNode();
            }
            temp = temp->child[c-'a'];
        }
        temp->isEnd = true;
    }

    TrieNode* prefix(string prefix)
    {
        TrieNode *temp = root;
        for (char c : prefix)
        {
            if (temp->child[c-'a'] == nullptr)
                return nullptr;
            temp = temp->child[c-'a'];
        }
        return temp;
    }

    void dfs(vector<string> &res, TrieNode* node, string prefix)
    {
        if (res.size() == 3 || node == nullptr) return;
        if (node->isEnd)
            res.push_back(prefix);
        for (int i = 0; i < 26; i++)
        {
            if (node->child[i])
            {
                prefix.push_back('a'+i);
                dfs(res,node->child[i], prefix );
                prefix.pop_back();
            }
        }
    }
};


vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    Trie trie;
    for (string &s : products)
        trie.insert(s);
    string prefix;
    vector<vector<string>> ans;
    ans.reserve(searchWord.size());
    for (char c : searchWord)
    {
        prefix.push_back(c);
        vector<string> suggest;
        trie.dfs(suggest,trie.prefix(prefix), prefix);
        ans.push_back(suggest);
    }
    return std::move(ans);

}