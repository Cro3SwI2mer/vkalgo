#include "week2.hpp"

// #include <queue>

bool has_cycle(node* head){
    if((head == nullptr) || (head->next == nullptr)){
        return false;
    }

    node* slow = head; node* fast = head->next;
    while(slow != fast){
        if((fast == nullptr) || (fast->next == nullptr)){
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

void reverse_linked_list(node* head){
    node* prev = nullptr; node* curr = head;

    while(curr != nullptr){
        node* nn = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nn;
    }

    head = prev;
}

node* middle(node* head){
    node* slow = head; node* fast = head;
    while((fast != nullptr) && (fast->next != nullptr)){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* remove_elements(node* head, const int val){
    node* dummy = new node(); dummy->next = head;
    node* prev = dummy; node* curr = head;

    while(curr != nullptr){
        if(curr->val == val){
            prev->next = curr->next;
        }
        else{
            prev = curr;
        }
        curr = curr->next;
    }

    node* nhead = dummy->next;
    delete dummy;
    return nhead;
}


bool is_subseq(const std::string& s1, const std::string& s2){
    int i1 = 0, i2 = 0;
    int cnt = 0;
    while((i1 < s1.size()) && (i2 < s2.size())){
        char a1 = s1[i1];
        while((s2[i2] != a1) && (i2 < s2.size())){
            i2++;
        }
        cnt++;
        i1++; i2++;
    }

    return cnt == s1.size();
}

bool is_palindrome(const std::string& s){
    int n = s.size();
    for(int i = 0; i < (s.size() + 1) / 2; ++i){
        if(s[i] != s[s.size()-1 - i]) return false;
    }
    return true;
}
