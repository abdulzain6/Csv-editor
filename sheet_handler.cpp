#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class sheet_handler{
public:
  int size = 0;
  sheet* head = NULL; 
  sheet* tail = NULL;
  sheet_handler* next;
  sheet_handler* prev;
  void insert_sheet(sheet* temp){
    size++;
    if (head == NULL){
      head = tail = temp;
    }
    else{
      temp->previous = tail;
      tail->next = temp;
      tail = temp;
    }
  }
    void delete_sheet(string filename){
    sheet *current = head;
    while (current != NULL){
        if (current->filename == filename)
        {
            break;
        }
        current = current->next;
    }
    if (current==head){
        head=head->next;
        delete current;
    }
    else if(current==tail){
        tail=tail->previous;
        tail->next = NULL;
        delete current;

    }
    else{
        current->next->previous = current->previous;
        current->previous->next = current->next;
        delete current;
    }
    }
    int display_available_sheets(void){
        if (size != 0){
            sheet* current = head;
            cout << "\nAvailable sheets: " << endl;
            while(current != NULL){
                cout << "* " <<current->filename <<endl;
                current = current->next;
            }
            return 1;
        }
        else 
            cout << "No available sheets" << endl;
            return 0;
    }
    sheet* get_sheet_by_name (string name){
        if (size != 0){
            sheet* current = head;
            while(current != NULL){
                if (current->filename == name)
                    return current;
                current = current->next;
            }
        }
        else 
            cout << "No available sheets" << endl;
        return NULL;
    }
};