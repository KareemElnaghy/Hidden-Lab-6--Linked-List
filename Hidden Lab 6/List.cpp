//
//  List.cpp
//  Hidden Lab 6
//
//  Created by Kareem Elnaghy on 3/22/23.
//

#include <stdio.h>
#include <iostream>
using namespace std;
template < class T>
class Node {
private:
    T info;
    Node<T> *next, *back;
public:
    Node() {
        next = NULL;
        back = NULL;
    }
    //getters
    T get_info(){
        return info;
    }
    
    Node<T>* get_next() {
        return next;
    }
    
    Node<T>* get_back() {
        return back;
    }
    
    //setters
   
    void set_info(T temp) {
        info = temp;
    }
   
    void set_next(Node<T>* n) {
        next = n;
    }
    
    void set_back(Node<T>* b) {
        back = b;
    }

    ~Node() {

    }
};

//class for the linked list
template <class T>
class my_list {
private:
    Node<T> *first, *last;

public:
    my_list() {
        first = NULL;
        last = NULL;
    }
    //append method
    Node<T>* append(T t_info) {
        Node<T> *temp = new Node<T>();
        temp->set_info(t_info);
        if (first == NULL) {
            //first node in the list
            first = temp;
            last = first;
            return temp;
        }
        else {
            //not first
            /*
             1.the new temp will become last
             2. temp.next = NULL
             3. temp.back = old last
             4. old last.next = temp
             */
            temp->set_back(last);
            last->set_next(temp);
            last = temp;
            return temp;
        }
    }
    //write a method insert_after(curr pointer, info). inserts a new
    //node to the list after the curr node
    void insert_after(Node<T>* curr, T info) {
          Node<T>* new_node = new Node<T>();
          new_node->set_info(info);
          new_node->set_back(curr);
          new_node->set_next(curr->get_next());
          
          if (curr->get_next() != NULL)
          {
              curr->get_next()->set_back(new_node);
          }
          curr->set_next(new_node);
      }

    
    ~my_list() {}

};
int main()
    {
    my_list<int> x;
    Node <int>* node1 = x.append(1);
    Node <int>* node2 = x.append(2);
    Node <int>* node3 = x.append(3);
    Node <int>* node4 = x.append(10);
    Node <int>* node5 = x.append(20);
    x.insert_after(node4, 7);
    
    
    Node<int>* t = node1;
    while (t != NULL)
    {
        cout << t->get_info() << endl;
        t = t->get_next();
    }
    
}
