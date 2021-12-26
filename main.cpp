#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "csv_editor.hpp"
using namespace std;
int start_menu (){
  int choice = 0; 
  cout << "Welcome to the command line CSV editor." << endl;
  cout << "Here are the options you can choose from." << endl;
  cout << "1. Open a new CSV file." << endl;
  cout << "2. View already opened CSVs. " <<endl;
  cout << "3. Exit." << endl;
  cin >> choice;
  return choice;
}

void clear_screen() // Used to clear screen on windows and linux
{
  #ifdef WINDOWS
      system("cls");
  #else
      system ("clear");
  #endif
}
int main(){
  sheet_handler* handler = new sheet_handler();
  while (true) {
    clear_screen();
    int choice = start_menu();
    if (choice == 1){
      try{
        file_parser parser;
        string filename;
        cout << "\nEnter the file location for the csv :" << endl;
        cin.ignore(); 
        getline(cin, filename);
        cout << "here";
        sheet* A = parser.open_file(filename);
        handler->insert_sheet(A);
        A->display_sheet();
      }
      catch (...){
        cout << "Error: FIle doesnt exist\n";
      }
      //Todo zain : add functions menu
      int a;
      cin >> a; // To stop the execution
    }
    else if (choice == 2){
      int success = handler->display_available_sheets();
      if (success == 1) {
        string choice;
        cout << "Please type the name for the sheet to choose." << endl;
        cin.ignore(); 
        getline(cin, choice);
        sheet* A = handler->get_sheet_by_name(choice);
        if (A != NULL){
          A->display_sheet();
        }
      }
      cout << "Enter any number to continue..." << endl;
      int a;
      cin >> a; // To stop the execution
    }
    else if (choice == 3){
      return 0;
    }
    else{
      start_menu();
    }
  }


  return 0 ;
}
