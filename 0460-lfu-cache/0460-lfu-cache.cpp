class Node{
    public:
        int key,val,freq;
        Node *prev,*next;

        Node(int k,int v){
            key=k;
            val=v;
            freq=1;
            prev=next=NULL;
        }
};
class DLL{
    public:
        Node *head,*tail;
        int size;

        DLL(){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            size =0;
        }

        void addFront(Node* node){
            Node* temp = head->next;
            head->next = node;
            node->prev= head;
            temp->prev = node;
            node->next=temp;
            size++;
        }

        void remove(Node* node){
            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            size--;
        }

        Node* removeLast(){
            if(size==0)return NULL;
            Node* node = tail->prev;
            remove(node);
            return node;
        }
};
class LFUCache {
public:
    int cap,minFreq;
    unordered_map<int,Node*>keyNode;
    unordered_map<int,DLL*>freqList;

    LFUCache(int capacity) {
        cap= capacity;
        minFreq =0;
    }
    void update(Node* node){
        int f = node->freq;
        freqList[f]->remove(node);
        if(f==minFreq && freqList[f]->size==0)minFreq++;
        node->freq++;

        if(!freqList.count(node->freq))freqList[node->freq]=new DLL();
        freqList[node->freq]->addFront(node);
    }

    int get(int key) {
        if(!keyNode.count(key))return -1;

        Node* node = keyNode[key];
        update(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap==0)return;
        if(keyNode.count(key)){
            Node* node = keyNode[key];
            node->val = value;
            update(node);
            return;
        }
        if(keyNode.size()==cap){
            Node *node = freqList[minFreq]->removeLast();
            keyNode.erase(node->key);
        }
        Node* node = new Node(key,value);
        minFreq=1;
        if(!freqList.count(1))freqList[1] = new DLL();
        freqList[1]->addFront(node);
        keyNode[key]=node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */