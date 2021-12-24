#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class node_string{
    public:
        string data;
        node_string * next;
};
class dynamic_stack_str{
    node_string* top;
    public: 
        int total = 0;
        dynamic_stack_str(){
            top = NULL;
        }

        void push (char data){
            node_string* temp = new node_string;
            temp->data = data;
            total++;
            if (top == NULL){
                top = temp;
            } 
            else{
                temp->next = top;
                top = temp;
            }
        }
        string pop (){
            if (top == NULL){
                cout<<"No top node\n";
                return 0;
            }
            else{
                node_string* temp = top;
                string data = temp->data;
                top = top->next;
                delete temp;
                total --;
                return data;
            }
        }
        string reverse_String (string input){
          int length = input.length();
          for (int i = 0 ; i < length ; i++){
            push(input[i]);
          }
          string reversed;
          for (int i = 0 ; i < length ; i++){
            reversed = reversed + pop();
          }
          return reversed;
        }
};