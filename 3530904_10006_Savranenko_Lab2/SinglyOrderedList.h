#ifndef SINGLYORDEREDLIST_H
#define SINGLYORDEREDLIST_H

#include <iostream>

class SinglyOrderedList
{
private:

    struct Node
    {
        int item_;
        Node* next_;

        Node(int item, Node *next = nullptr) : item_(item), next_(next) {  }
    };

    Node* head_;
    Node* head() const { return head_; }

    void swap(SinglyOrderedList &other) noexcept;  // Нельзя копировать списки при выполнении одного из заданий

    bool endInsert(Node* x);

    bool insertNode(Node* x);
    void deleteNode(Node* x);
    Node* searchNode(int item);
    Node* replaceNode(Node* x, int item);

public:

    SinglyOrderedList() : head_(nullptr) {  }
    SinglyOrderedList(SinglyOrderedList &&other) noexcept;

    SinglyOrderedList& operator=(SinglyOrderedList &&right) noexcept;

    int headItem() const;
    int& headItem();

    void insertItem(int item);
    bool deleteItem(const int item);
    bool searchItem(int item);
    bool replaceItem(int itemOld, int itemNew);

    void addList(SinglyOrderedList &&other) noexcept;
    void removeFromList(SinglyOrderedList&& other) noexcept;

    void outAll();
    bool operator == (const SinglyOrderedList &other);
    friend std::ostream &operator <<(std::ostream &out, const SinglyOrderedList &list);
    friend SinglyOrderedList crossLists(SinglyOrderedList&& first, SinglyOrderedList&& second);

    virtual ~SinglyOrderedList();
};

#endif SINGLYORDEREDLIST_H