#include "week2.hpp"

#include <cassert>
#include <iostream>
#include <string>

void tt1(){

    {
        node* n1 = new node(1);
        assert(has_cycle(nullptr) == false);
        delete n1;
    }

    {
        node* n1 = new node(1); node* n2 = new node(2); node* n3 = new node(3);
        n1->next = n2; n2->next = n3; n3->next = n1;
        assert(has_cycle(n1) == true);
        assert(has_cycle(n2) == true);
        assert(has_cycle(n3) == true);
        delete n1; delete n2; delete n3;
    }

    {
        node* n1 = new node(1); node* n2 = new node(2); node* n3 = new node(3); node* n4 = new node(4);
        n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
        assert(has_cycle(n1) == true);
        delete n1; delete n2; delete n3; delete n4;
    }

    {
        node* n1 = new node(1); node* n2 = new node(2); node* n3 = new node(3); node* n4 = new node(4);
        n1->next = n2; n2->next = n3; n3->next = n4; n4->next = nullptr;
        assert(has_cycle(n1) == false);
        delete n1; delete n2; delete n3; delete n4;
    }

}

void tt2(){

    {
        node* n1 = new node(1); node* n2 = new node(2); node* n3 = new node(3); node* n4 = new node(4);
        n1->next = n2; n2->next = n3; n3->next = n4; n4->next = nullptr;
        reverse_linked_list(n1);
        assert(n4->next == n3);
        assert(n3->next == n2);
        assert(n2->next == n1);
        assert(n1->next == nullptr);
        delete n1; delete n2; delete n3; delete n4;
    }

}

void tt3(){

    {
        node* n1 = new node(1); node* n2 = new node(2); node* n3 = new node(3); node* n4 = new node(4);
        n1->next = n2; n2->next = n3; n3->next = n4;
        assert(middle(n1) == n3);
        node* n5 = new node(5); n4->next = n5;
        assert(middle(n1) == n3);
        delete n1; delete n2; delete n3; delete n4; delete n5;
    }

}

void tt4(){

    {
        node* n1 = new node(1); node* n2 = new node(2); node* n3 = new node(3); node* n4 = new node(4);
        n1->next = n2; n2->next = n3; n3->next = n4;
        node* n5 = new node(5); n4->next = n5;
        node* nh = remove_elements(n1, 3);
        assert(n1 == nh);
        assert(n2 == nh->next);
        assert(n4 == nh->next->next);
        assert(n5 == nh->next->next->next);
        delete n1; delete n2; delete n3; delete n4; delete n5;
    }

    {
        node* n1 = new node(1); node* n2 = new node(4); node* n3 = new node(3); node* n4 = new node(4);
        n1->next = n2; n2->next = n3; n3->next = n4;
        node* n5 = new node(5); n4->next = n5;
        node* nh = remove_elements(n1, 4);
        assert(n1 == nh);
        assert(n3 == nh->next);
        assert(n5 == nh->next->next);
        delete n1; delete n2; delete n3; delete n4; delete n5;
    }

}

void tt5(){

    {
        std::string s1 = "abc";
        std::string s2 = "abc";
        assert(is_subseq(s1, s2) == true);
        std::string s3 = "aabbccc";
        assert(is_subseq(s1, s3) == true);
        std::string s4 = "lsdnaksjnbalskdjabatusiofksjdkzvsdhbgxkdjhfougyhdljbasdkjbascbaskbcasbc";
        assert(is_subseq(s1, s4) == true);
        std::string s5 = "cba";
        assert(is_subseq(s1, s5) == false);
    }

}

void tt6(){

    {
        assert(is_palindrome("ababa") == true);
        assert(is_palindrome("abdba") == true);
        assert(is_palindrome("aaaaaa") == true);
        assert(is_palindrome("aabbaa") == true);
        assert(is_palindrome("cabbac") == true);

        assert(is_palindrome("a") == true);
        assert(is_palindrome("") == true);
    }

    {
        assert(is_palindrome("acaba") == false);
        assert(is_palindrome("aacaaa") == false);
        assert(is_palindrome("aabbad") == false);
        assert(is_palindrome("cabdac") == false);
    }

}

void tt7(){

    {
        node* n1 = new node(1); node* n2 = new node(2); node* n3 = new node(3); node* n4 = new node(4);
        n1->next = n3; n2->next = n4;
        node* r = merge_linked_lists(n1, n2);
        assert(n1 == r);
        assert(n2 == r->next);
        assert(n3 == r->next->next);
        assert(n4 == r->next->next->next);
    }

}

int main(){
    tt1();
    tt2();
    tt3();
    tt4();
    tt5();
    tt6();
    tt7();

    std::cout << "All tests passed!\n";

    return 0;
}