#include <iostream>
#include <string>
using namespace std;


template<typename A>
class node{
    public:
    A data;
    node<A>* next = NULL;
    node<A>* previous = NULL;
};

template<typename A>
class linked_list{
  public:
    node<A>* head;
    node<A>* tail;
      int size = 0;
        linked_list(){
            head = NULL;
            tail = NULL;
        }
        void insert (A data){
            size++;
            node<A>* temp = new node<A>;
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
            node<A>* temp = head;
            while (temp!=NULL){
                cout << temp->data << endl;
                temp=temp->next;
            }
        }
        A delete_from_start(){
          if(head != NULL) {
            A data;
            node<A>* temp;
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