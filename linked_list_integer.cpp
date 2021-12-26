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
                tail->next = NULL;
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
          void insert_using_str (string str , string delimiter = ","){
            int position = 0;
            int data = 0;
            try {
              while ((position = str.find(delimiter)) != string::npos) {
                data = stoi(str.substr(0, position));
                insert(data);
                str.erase(0, position + delimiter.length());
              }
              insert(stoi(str));
            }
            catch (...){
                cout << " \n ERROR: Enter Numerical values only. \n";
            }
          }
        
};