
v1.0:很考察链表基本操作的一题，尤其要注意下标index和size的区分
class MyLinkedList {
public:
    struct LinkNode{
        int val;
        LinkNode *next;
        LinkNode(int x):val(x), next(nullptr){};
    };

    MyLinkedList() {
        dummyHead = new LinkNode(0);
        size = 0;
    };
    
    int get(int index) {
        if(index+1>size||index<0)return -1;
        LinkNode *cur = dummyHead->next;        
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkNode *newnode = new LinkNode(val);
        newnode->next = dummyHead->next;
        dummyHead->next = newnode;
        size++;
    }
    
    void addAtTail(int val) {
        LinkNode *cur = dummyHead;
        int index = size;
        while(index--){
            cur = cur->next;
        }
        LinkNode *newnode = new LinkNode(val);
        cur->next = newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)return;
        if(index<0)index = 0;
        LinkNode *cur = dummyHead;        
        while(index--){
            cur = cur->next;
        }
        LinkNode *newnode = new LinkNode(val);
        newnode->next = cur->next;
        cur->next = newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index+1>size||index<0)return;
        LinkNode *cur = dummyHead;        
        while(index--){
            cur = cur->next;
        }
        LinkNode *tmp= cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }
private:
    int size;
    LinkNode *dummyHead;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */