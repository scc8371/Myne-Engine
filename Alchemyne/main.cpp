#include <iostream>
using namespace std;

//memory management
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

void wrapper();

int main()
{
   cout << "test works!" << endl; 
   wrapper();

   _CrtDumpMemoryLeaks();
}

//holds main execution for the program
void wrapper(){
    cout << "test" << endl;
}