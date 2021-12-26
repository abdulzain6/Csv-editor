#include <iostream>
#include <string>
using namespace std;


class sheet_handler{
public:
  int size = 0;
  sheet* head = NULL; 
  sheet* tail = NULL;
  sheet_handler* next = NULL;
  sheet_handler* prev = NULL;
  void insert_sheet(sheet* temp){
    size++;
    if (head == NULL){
      head = tail = temp;
    }
    else{
      temp->previous = tail;
      tail->next = temp;
      tail = temp;
    tail->next = NULL;

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
    dictionary<int, string> get_available_sheets(void){
        dictionary<int , string> dict;
        if (size != 0){
            sheet* current = head;
            cout << "\nAvailable sheets: " << endl;
            int i = 1;
            while(current != NULL){
                cout << i <<". " <<current->filename <<endl;
                dict.insert(i , current->filename);
                current = current->next;
                i++;
            }
        }
        else 
            cout << "No available sheets" << endl;
            return dict;
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
