#include <iostream>
#include <fstream>
#include <string>
#include "csv_editor.h"
using namespace std;

int main(){
  file_parser parser;
  sheet* A= parser.open_file("/home/zain/Documents/Projects/Heart Failure/data.csv");

  A->change_cell(2,2,"fbfuj");
    A->display_multiple_rows("1,2,3,99");

  cout << A->max();
  return 0 ;
}
