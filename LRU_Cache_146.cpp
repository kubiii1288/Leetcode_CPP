class LRUCache {
    struct Node
    {
        int key, val;
        Node* next;
        Node* prev;
        Node(int key, int value)
        {
            this->key = key;
            this->val = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
public:
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int capacity;
    int size;
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        Node* node = it->second;
        remove(node);
        addHead(node);
        return node->val;
    }

    void put(int key, int value) {
       if (mp.find(key) == mp.end())
       {
           Node* newNode = new Node(key,value);
            if (size == capacity)
            {
                Node* lru = tail;
                mp.erase(lru->key);
                removeTail();
            }
           mp[key] = newNode;
           addHead(newNode);
       } else
       {
          Node* node = mp[key];
          node->val = value;
          remove(node);
          addHead(node);
       }
    }

    void remove(Node* node)
    {
        // no delete operator here
        if (node->prev !=nullptr)
        {
           node->prev->next = node->next;
        } else head = node->next;

        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        } else tail = node->prev;

        node->next = node->prev = nullptr;
        size--;
    }
    void removeTail()
    {
        if (tail == nullptr) return;
        Node* temp = tail;
        if (tail->prev != nullptr)
        {
            tail = tail->prev;
            tail->next= nullptr;
        } else head = tail = nullptr;

        delete temp;
        size--;
    }
    void addHead(Node* newNode)
    {
        if (newNode == nullptr) return;
        newNode->next = newNode->prev =nullptr;
        if (head == nullptr)
        {
            head = tail = newNode;
        } else
        {
            newNode->next =head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
};