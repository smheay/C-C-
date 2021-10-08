//Shannon Meyer
//CS 162
//program 4



#include "class.h"

// after rereading instructions I changed name to Info_List

class Info_List
{
    public:
       Info_List(); //initialize data members
       ~Info_List(); //destructor (deallocate)
       void set_size();
       void set_size_file(int size_of_array);
       void input();
       void display_all(); 
       void search_list();
       void output_file();
       void input_file();
       void input_file2();
       
    private:
       card * array; //dynamically allocated array
       int size;
       int numberInput;
};