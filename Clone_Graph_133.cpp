 Node* cloneGraph(Node* node) {
     if (node == nullptr) return node;
     unordered_map<Node*, Node*> mp;
     queue<Node*> q;
     q.push(node);
     mp[node] = new Node(node->val);
     mp[node]->neighbors.reserve(node->neighbors.size());
     while(!q.empty())
     {
         Node* front = q.front();
         q.pop();
         for(Node* v : front->neighbors)
         {
             if (mp.find(v) == mp.end())
             {
                 mp[v] = new Node(v->val);
                 mp[v]->neighbors.reserve(v->neighbors.size());
                 q.push(v);
             }
             mp[front]->neighbors.push_back(mp[v]);
         }
     }
     return mp[node];
 }