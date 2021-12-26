#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class file_parser{
  string delimiter;
  public:
    file_parser(string d = ",") : delimiter(d) {};
    bool does_file_exist(string fileName)
    {
      ifstream infile(fileName.c_str());
      return infile.good();
    }
    sheet* open_file(string filename){
      if (does_file_exist(filename)){
        ifstream file;
        file.open(filename);
        sheet* sheet_var = new sheet(filename);
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
      else
        cout << "FIle doesnt exist \n";
        return NULL;
    }
};
