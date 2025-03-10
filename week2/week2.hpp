#ifndef WEEK_2_HEADER
#define WEEK_2_HEADER

#include <string>

struct node{
    int val;
    node* next;

    node(): val(0), next(nullptr) {}
    node(int VAL): val(VAL), next(nullptr) {}
};

bool has_cycle(node* head);
void reverse_linked_list(node* head);
node* middle(node* head);
node* remove_elements(node* head, const int val);

bool is_subseq(const std::string& s1, const std::string& s2);
bool is_palindrome(const std::string& s);

#endif