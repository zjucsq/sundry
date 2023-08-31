#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node(int val, node* next): val(val), next(next) {}
};

node* reverse(node* head) {
    if (head->next == nullptr) {
        return head;
    }

    node* next_reverse = reverse(head->next);

    node* n = next_reverse;
    while (n->next != nullptr) {
        n = n->next;
    }
    n->next = head;
    return next_reverse;
}

node* reverse_k(node* head, int k) {
    
    node* subhead;
    node* subtail;
    node* nexthead = head;
    node* prevtail = nullptr;
    node* ret = nullptr;

    bool finish = false;
    while (true) {
        subhead = nexthead;
        subtail = nexthead;
        for (int i = 0; i < k - 1; ++i) {
            if (subtail->next == nullptr) {
                finish = true;
                break;
            }
            subtail = subtail->next;
            nexthead = nexthead->next;
        }
        if (finish) {
            break;
        }
        if (prevtail) {
            prevtail->next = subtail;
        }
        nexthead = nexthead->next;
        subtail->next = nullptr;

        node* subheadrev = reverse(subhead);

        prevtail = subhead;
        if (ret == nullptr) {
            ret = subtail;
        }
    }
    return ret;
}

void printList(node *head) {
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    } cout << endl;
}

int main()
{
    node* n5 = new node{5, nullptr};
    node* n4 = new node{4, n5};
    node* n3 = new node{3, n4};
    node* n2 = new node{2, n3};
    node* n1 = new node{1, n2};

    printList(n1);

    node* n_reverse = reverse_k(n1, 3);

    printList(n_reverse);
}