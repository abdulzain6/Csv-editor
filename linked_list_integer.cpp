#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* previous;
};
class linked_list_int{
  public:
    node* head;
    node* tail;
      int size = 0;
        linked_list_int(){
            head = NULL;
            tail = NULL;
        }
        void insert (int data){
            size++;
            node* temp = new node;
            temp->data = data;

            if (head==NULL){
                head = temp;
                tail = temp;
            }
            else{
                temp->previous = tail;
                tail->next = temp;
                tail = temp;
            }
        }
        void display(){
            node* temp = head;
            while (temp!=NULL){
                cout << temp->data << endl;
                temp=temp->next;
            }
        }
        int delete_from_start(){
          if(head != NULL) {
            int data;
            node* temp;
            data = head -> data;
            temp = head;
            head = head->next;
            if(head != NULL)
              head->previous = NULL;
            delete temp;
            return data;
          }
          else{
            return 0;
          }

        }
};