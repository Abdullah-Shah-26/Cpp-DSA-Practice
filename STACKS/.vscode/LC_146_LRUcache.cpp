#include <unordered_map>
using namespace std;

class LRUCache {
public: 
    // we are using DLL and unordered map
    class Node{   // regular node class for dll 
    public:
        Node* next;
        Node* prev;

        int key , val; // storing key val pair in each node 
            Node(int k , int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
    };
    public:
    Node* head = new Node(-1,-1); // initializing all nodes to -1 to avoid NULL node
    Node* tail = new Node(-1,-1);

    unordered_map<int , Node*> m;
    int limit;

    void addNode(Node* newNode) { // O(1)
        Node* oldNext = head->next;
        
        // Adjust pointers to insert newNode right after head
        newNode->next = oldNext;
        newNode->prev = head;
        head->next = newNode;
        oldNext->prev = newNode;
    }

    void delNode(Node* oldNode){ // O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) { // O(1)
        limit = capacity;    
        head-> next = tail;
        tail-> prev = head;
    }
    
    int get(int key) { // O(1)
        if(m.find(key) == m.end()){ // key doesnt exist
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;

        // first we delete the node then insert it at head 
        m.erase(key); 
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) { // O(1)
        // before putting any val we check in map whether it already exists
        if(m.find(key) != m.end()){ //It exist delete old node
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
            delete oldNode; // Free memory to prevent heap-use-after-free
        }
        if(m.size() == limit){ //capacity reached
            // delete LRU data 
            Node* lruNode = tail->prev;
            m.erase(lruNode->key);
            delNode(lruNode); // func to delete new node
            delete lruNode; // Free memory
        }

        Node* newNode = new Node(key , value); 
        addNode(newNode); // function to add new node
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */