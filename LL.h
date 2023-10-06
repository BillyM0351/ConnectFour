#include <iostream>
    using namespace std;

template <typename T>
class LL 
{
    //contents of each node
    struct node 
    {
        T data;
        node* prev;
        node* next;
    };
    //iterator class to allow access of each node in main
   public:
    class Iterator 
    {
       public:
        friend class LL;
        Iterator();
        Iterator(node*);
        T operator*() const;
        Iterator operator++(int);
        Iterator operator++();
        Iterator operator--(int);
        Iterator operator--();
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

       private:
        node* current;
    };

    LL();
    LL(const LL<T>&);
    const LL<T>& operator=(const LL<T>&);
    ~LL();
    void headInsert(const T&);
    void tailInsert(const T&);
    void headRemove();
    bool isEmpty() const;
    //std::size_t size() const;
    Iterator begin() const;
    Iterator end() const;
    void printLL();
    int getSize();
    T getNode(int index);


   private:
    node* portal;
    node* endOfList; // Added this to help add to end of linked list
    node* frontOfList;
    int sizeOfList;

};

//iterator class implementation
template <typename T>
LL<T>::Iterator::Iterator() 
{
    current = nullptr;
}

template <typename T>
LL<T>::Iterator::Iterator(node* ptr) 
{
    current = ptr;
}

template <typename T>
T LL<T>::Iterator::operator*() const 
{
    return current->data;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator++(int) 
{

    this->current = this->current->next;
    return *this;

}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator++() 
{
    this->current = this->current->next;
    /*Iterator increment;
    increment.current = this->current->next;
    return increment;*/

    return *this;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator--(int) 
{
    this->current = this->current->prev;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator--() 
{
    this->current = this->current->prev;
}

template <typename T>
bool LL<T>::Iterator::operator==(const Iterator& rhs) const 
{
    bool equal = false;

   if (this->current == rhs.current) {
    equal = true;
   }

    return equal;
}

template <typename T>
bool LL<T>::Iterator::operator!=(const Iterator& rhs) const 
{
   bool equal = false;

   if (this->current != rhs.current) {
    equal = true;
   }

    return equal;
}

//Linked list class implementation
template <typename T>
LL<T>::LL() 
{
    //Default consturctor, allocates a node to portal and sets next/previous to itself
    //T garbageData = NULL;
    portal = new node();
    //portal->data = garbageData;
    portal->prev = portal->next = portal;
    sizeOfList = 0;
}

//copy constructor
template <typename T>
LL<T>::LL(const LL<T>& copy) 
{

    if (sizeOfList == 0) {
        portal = new node();
        portal->prev = portal->next = portal;
        sizeOfList = 0;
    }

    *this = copy;
/*
    //T garbageData = NULL;
    portal = new node();
    //portal->data = garbageData;
    portal->prev = portal->next = portal;
    node* tmp = copy.portal->next;
    for (int i = 0; i < copy.sizeOfList; i++) {
        tailInsert(tmp->data);
        tmp = tmp->next;
    }
    frontOfList = portal->next;*/

}

template <typename T>
const LL<T>& LL<T>::operator=(const LL<T>& rhs) 
{

    if (portal->next != portal) {
        node* currentNode = portal->next;
        node* nextNode = NULL;

    while (currentNode != portal) {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    delete portal;
    portal = new node();
    }








    //T garbageData = NULL;
    //portal = new node();
    //portal->data = garbageData;
    portal->prev = portal->next = portal;
    node* tmp = rhs.portal->next;

    for (int i = 0; i < rhs.sizeOfList; i++) {
        tailInsert(tmp->data);
        tmp = tmp->next;
    }

    frontOfList = portal->next;


    return *this;


/*
    if (&rhs != this) {
        node* tmp = new node();
        tmp = rhs.portal->next;
        sizeOfList = 0;
        for (int i = 0; i < rhs.sizeOfList; i++) {
            tailInsert(tmp->data);
            tmp = tmp->next;
        }
    }
   
    return *this; */
}

//destructor
template <typename T>
LL<T>::~LL() 
{

    node* currentNode = portal->next;
    node* nextNode = NULL;

    while (currentNode != portal) {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    delete portal;
    sizeOfList = 0;


}

//head insert
template <typename T>
void LL<T>::headInsert(const T& item) 
{

    node* newNode = new node();
    newNode->data = item;

    //Check if linked list is currently empty
    if (portal->next != portal) {
        frontOfList->prev = newNode;
        newNode->prev = portal;
        newNode->next = frontOfList;
        portal->next = newNode;
        frontOfList = newNode;
        sizeOfList++;
    }

    //If portal points to itself then list is empty
    if (portal->next == portal) {
        portal->next = newNode;
        portal->prev = newNode;
        newNode->next = portal;
        newNode->prev = portal;
        frontOfList = newNode;
        sizeOfList = 1;
    }


}

//tail insert
template <typename T>
void LL<T>::tailInsert(const T& item) 
{
    node* newNode = new node();
    newNode->data = item;

    //Check if linked list is currently empty
    if (portal->next != portal) {
        endOfList->next = newNode;
        newNode->next = portal;
        newNode->prev = endOfList;
        portal->prev = newNode;
        endOfList = newNode;
        frontOfList = portal->next;
        sizeOfList++;
    }

    //If portal points to itself then list is empty
    if (portal->next == portal) {
        portal->next = newNode;
        portal->prev = newNode;
        newNode->next = portal;
        newNode->prev = portal;
        endOfList = newNode;
        frontOfList = newNode;
        sizeOfList = 1;
    }
}

template <typename T>
void LL<T>::headRemove()
{
    
}

template <typename T>
bool LL<T>::isEmpty() const
{
    bool isEmpty = false;

    if (portal->next == portal) {
        isEmpty = true;
    }

    return isEmpty;
}

/*template <typename T>
std::size_t LL<T>::size() const
{
}*/

template <typename T>
typename LL<T>::Iterator LL<T>::begin() const 
{
    Iterator begin;
    begin.current = portal->next;
    return begin;
}

template <typename T>
typename LL<T>::Iterator LL<T>::end() const 
{
    Iterator end;
    end.current = portal;
    return end;
}

template <typename T>
void LL<T>::printLL()
{
    node* temp = portal->next;

    while (temp != portal)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

template <typename T>
int LL<T>::getSize()
{
    return sizeOfList;
}

template <typename T>
T LL<T>::getNode(int index) {

    node* current = portal->next;
    int count = 0;

    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }

    return (current->data);
}