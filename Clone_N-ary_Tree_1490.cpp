//
// Created by Anh Le on 9/9/26.
//
Node* cloneTree(Node* root) {

    if (root == nullptr)
        return nullptr;
    unordered_map<Node*, Node*> mp;
    mp[root] = new Node(root->val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* u = q.front();
        q.pop();

        for (Node* v : u->children) {
            if (mp.find(v) == mp.end()) {
                mp[v] = new Node(v->val);
                q.push(v);
            }
            mp[u]->children.push_back(mp[v]);
        }
    }
    return mp[root];
}