#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct node_tree{
	int data;
	node_tree *left;
	node_tree *right;
};

class tree{
	public:
		node_tree *root;
		tree() : root(NULL) {}
		
		node_tree* insert_helper(node_tree *temp , int d)
		{
			if (temp == NULL)
			{
				temp = new node_tree;
				temp->data = d;
				temp->left = NULL;
				temp->right = NULL;
				if(root == NULL)
				{
					root = temp;
				}
			}
			else if(temp->data > d)
			{
				temp->left = insert_helper(temp->left , d);
			}
			else
			{
				temp->right = insert_helper(temp->right , d);
			}
			
			return temp;
		}
    void insert (int data){
      insert_helper(root, data);
    }
    int find_largest_helper (node_tree* temp){
      if (temp->right == NULL){
        return temp->data;
      }
      else{
        find_largest_helper(temp->right);
      }

    }
    int max(){
      return find_largest_helper(root);
    }
    int find_smallest_helper (node_tree* temp){
      if (temp->left == NULL){
        return temp->data;
      }
      else{
        find_smallest_helper(temp->left);
      }

    }
    int min(){
      return find_smallest_helper(root);
    }

};
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
          else
          {
              return 0;
          }

        }
};


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
  row* next;
  row* prev;
  void insert_cell(cell* temp){
    size++;
    if (head == NULL){
      head = tail = temp;
    }
    else{
      temp->prev = tail;
      tail->next = temp;
      tail = temp;
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
  column* next;
  column* prev;
  void insert_cell(cell* temp){
    size++;
    if (head == NULL){
      head = tail = temp;
    }
    else{
      temp->prev_col = tail;
      tail->next_col = temp;
      tail = temp;
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
  long double calculate_column_average(int column_number){
    long double sum = 0 , avg = 0;
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
            sum = sum + stold(cell_iterator->data);
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
  long double calculate_column_sum(int column_number){
    long double sum = 0;
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
            sum = sum + stold(cell_iterator->data);
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

class file_parser{
  string delimiter;
  public:
    file_parser(string d = ",") : delimiter(d) {};
    sheet* open_file(string filename){
      ifstream file;
      file.open(filename);
      sheet* sheet_var = new sheet();
      if (file.is_open()) {
        string line;
        int line_number = 0;
        while (getline(file, line)) {
          line_number++;
          int position = 0;
          string data;
          int column_number = 0;

          row* row_var = new row();
          while ((position = line.find(delimiter)) != string::npos) {
              column_number++;
              data = line.substr(0, position);
              cell* cell_var = new cell(line_number , column_number , data);
              row_var->insert_cell(cell_var);
              line.erase(0, position + delimiter.length());
          }

          cell* cell_var = new cell(line_number , column_number , line);
          row_var->insert_cell(cell_var);
          sheet_var->insert_row(row_var);
        }
      }
      file.close();

      //Making COlumns objects from rows.
      for (int i = 0 ; i < sheet_var->head->size; i++){
        column* col_var = new column();
        row* row_var = sheet_var->head;
        while (row_var != NULL){
          cell* cell_var = row_var->head;
          int counter = 0;

          while (cell_var != NULL){
            if (counter == i){
              col_var->insert_cell(cell_var);

              break;
            }
            counter ++ ;
            cell_var = cell_var->next;
          }

          row_var = row_var->next;
        }
        sheet_var->insert_column(col_var);

      }

      return sheet_var;
    }
};

int main(){
  file_parser parser;
  sheet* A = parser.open_file("/home/zain/Documents/Projects/Heart Failure/data.csv");

  A->display_multiple_rows("1,2,3,99");

  return 0 ;
}
