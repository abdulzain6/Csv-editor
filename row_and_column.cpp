#include <iostream>
#include <string>
using namespace std;

class cell{
public:
  int row;
  int column;
  string data;
  cell* next = NULL;
  cell* prev = NULL;
  cell* next_col = NULL;
  cell* prev_col = NULL;

    cell (int row, int column , string data) : row(row), column(column), data(data) {};
};


class row{
public:
  int size = 0;
  cell* head = NULL;
  cell* tail = NULL;
  row* next = NULL;
  row* prev = NULL;
  void insert_cell(cell* temp){
    size++;
    if (head == NULL){
      head = tail = temp;
    }
    else{
      temp->prev = tail;
      tail->next = temp;
      tail = temp;
      tail->next = NULL;

    }
  }

  void display(){
      cell* temp = head;
      while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << "\n";
  }
};

class column{
public:
  int size = 0;
  cell* head = NULL;
  cell* tail = NULL;
  column* next = NULL;
  column* prev = NULL;
  
  void insert_cell(cell* temp){
    size++;
    if (head == NULL){
      head = tail = temp;
    }
    else{
      temp->prev_col = tail;
      tail->next_col = temp;
      tail = temp;
	  tail->next_col = NULL;
    }
  }

  void display(){
      cell* temp = head;
      while (temp != NULL){
        cout << temp->data << "\n";
        temp = temp->next_col;
      }
      cout << "\n";
  }
};
