#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class sheet{
public:
  row* head;
  row* tail;
  column* col_head;
  column* col_tail;
  bool skip_first_row_for_column_names = true;
  int total_rows = 0;
  int total_cols = 0;
  void set_skip_first_row_for_column_names (bool value){
    skip_first_row_for_column_names = value;
  }
  void insert_row(row* temp){
    total_rows++;
    if (head == NULL){
      head = tail = temp;
    }
    else{
      temp->prev = tail;
      tail->next = temp;
      tail = temp;
    }
  }
  void insert_column(column* temp){
    total_cols++;
    if (col_head == NULL){
      col_head = col_tail = temp;
    }
    else{
      temp->prev = col_tail;
      col_tail->next = temp;
      col_tail = temp;
    }
  }
  // TODO : Zaigham improve design.
  void display_sheet(){
      row* temp = head;
      while (temp != NULL){
        temp->display();
        temp = temp->next;
      }
      cout << "\n";
  }
  /* For testing purposes
  void display_sheet_2(){
    column* temp = col_head;
    while (temp != NULL){
      temp->display();
      temp = temp->next;
    }
    cout << "\n";
  }
  */
  void change_cell(int row_number, int column_number , string data){
    row* row_iterator = head;
    int row_counter = -1;
    while (row_iterator != NULL){
      row_counter++;
      if (row_counter == row_number){
        cell* column_iterator = row_iterator->head;
        int column_counter = -1;
        while (column_iterator != NULL){
          column_counter++;
          if (column_counter == column_number){
            column_iterator->data = data;
          }
          column_iterator = column_iterator->next;
        }
      }
      row_iterator = row_iterator->next;
    }
  }
 long double max(int verbose = 0){
    try{
      tree Tree;
      int err_flag = 0;
      row* row_iterator = head;
      int row_counter = -1;
      while (row_iterator != NULL){
        row_counter++;
        if ((skip_first_row_for_column_names == true && row_counter != 0)|| skip_first_row_for_column_names == false){
          cell* cell_iterator = row_iterator->head;
          while (cell_iterator != NULL){
            try{
              Tree.insert(stold(cell_iterator->data));
            }
            catch(...){
              if (err_flag == 0 && verbose == 1){
                cout << "\n Data is not completely numerical , Ignoring non numericals. \n";
                err_flag = 1;
              }
            }
            cell_iterator = cell_iterator->next;
          }
        }
        row_iterator = row_iterator->next;
      }
      return Tree.max();
    }
   
    catch(...){
      cout << "\nError\n";
      return 0;
    }
  
 }
 long double min(int verbose = 0){
    try{
      tree Tree;
      row* row_iterator = head;
      int err_flag = 0;
      int row_counter = -1;
      while (row_iterator != NULL){
        row_counter++;
        if ((skip_first_row_for_column_names == true && row_counter != 0)|| skip_first_row_for_column_names == false){
          cell* cell_iterator = row_iterator->head;
          while (cell_iterator != NULL){
            try{
              Tree.insert(stold(cell_iterator->data));
            }
            catch(...){
              if (err_flag == 0 && verbose == 1){
                cout << "\n Data is not completely numerical , Ignoring non numericals. \n";
                err_flag = 1;
              }
            }
            cell_iterator = cell_iterator->next;
          }
        }
        row_iterator = row_iterator->next;
      }
      return Tree.min();
    }
   
    catch(...){
      cout << "\nError\n";
      return 0;
    }
  
 }
  long double calculate_column_average(int column_number , int verbose = 0){
    long double sum = 0 , avg = 0;
    int err_flag = 0;
    column* column_iterator = col_head;
    int column_counter = -1;
    while (column_iterator != NULL){
      column_counter++;
      if (column_counter == column_number){
        cell* cell_iterator = column_iterator->head;
        int cell_counter = -1;
        while (cell_iterator != NULL){
          cell_counter++;
          if ((skip_first_row_for_column_names == true && cell_counter != 0)|| skip_first_row_for_column_names == false){
            //stod is used to convert string to double.
            try{
              sum = sum + stold(cell_iterator->data);
            }
            catch(...){
              if (err_flag == 0 && verbose == 1){
                cout << "\n Data is not completely numerical , Ignoring non numericals. \n";
                err_flag = 1;
              }
            }
          }
          cell_iterator = cell_iterator->next_col;

        }
        break;
      }
      column_iterator = column_iterator->next;
    }
    int count = column_iterator->size - 1;
    avg = sum / count;
    return avg;
  }
  long double calculate_column_sum(int column_number , int verbose = 0){
    long double sum = 0;
    int err_flag = 0;
    column* column_iterator = col_head;
    int column_counter = -1;
    while (column_iterator != NULL){
      column_counter++;
      if (column_counter == column_number){
        cell* cell_iterator = column_iterator->head;
        int cell_counter = -1;
        while (cell_iterator != NULL){
          cell_counter++;
          if ((skip_first_row_for_column_names == true && cell_counter != 0)|| skip_first_row_for_column_names == false){
            //stod is used to convert string to double.
            try{
              sum = sum + stold(cell_iterator->data);
            }
            catch (...){
              if (err_flag == 0 && verbose == 1){
                cout << "\n Data is not completely numerical , Ignoring non numericals. \n";
                err_flag = 1;
              }
            }
          }
          cell_iterator = cell_iterator->next_col;

        }
        break;
      }
      column_iterator = column_iterator->next;
    }
    return sum;
  }
  void display_row (int row_number){
    row* row_iterator = head;
    int row_counter = -1;
    while (row_iterator != NULL){
      row_counter++;
      if (row_counter == row_number){
          row_iterator->display();
          break;
      }
      row_iterator = row_iterator->next;
    }
  }
  void display_multiple_rows_helper(linked_list_int rows){
    linked_list_int* rows_ptr = &rows;
    node* temp = rows_ptr->head;
    int i = 0;
    while (i < rows_ptr->size) {
      i++;
      display_row(temp->data);
      temp = temp->next;
    }
    
  }
  void display_multiple_rows (string str){
    string delimiter = ",";
    int position = 0;
    linked_list_int list;
    int data = 0;
    while ((position = str.find(delimiter)) != string::npos) {
      data = stoi(str.substr(0, position));
      list.insert(data);
      str.erase(0, position + delimiter.length());
    }
    list.insert(stoi(str));
    display_multiple_rows_helper(list);
  }
};
