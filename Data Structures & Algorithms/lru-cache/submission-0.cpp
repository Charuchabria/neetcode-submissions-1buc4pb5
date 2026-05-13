class Node {
public:
    int key;
    int val;
    Node* prev; 
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    int cap;
    unordered_map<int,Node*>cache;
    Node* head; 
    Node* tail; 

    void deletenode(Node* node){
        Node* prevnode = node->prev;
        Node* afternode = node->next;
        prevnode->next = afternode; 
        afternode->prev = prevnode;
    }

    void insertafterhead(Node* node){
        Node* currentafterhead = head->next; 
        head->next = node; 
        node->next = currentafterhead;
        node->prev = head;
        currentafterhead->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        tail = new Node (0,0);
        head = new Node (0,0);
        head->next = tail; 
        tail-> prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            deletenode(node);
            insertafterhead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            deletenode(cache[key]);
        }
        Node* newNode = new Node(key,value);
        cache[key] = newNode;
        insertafterhead(newNode);

        if(cache.size()>cap){
            Node* lru = tail->prev; 
            deletenode(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
