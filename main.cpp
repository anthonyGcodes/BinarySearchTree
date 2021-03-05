#include "main.h"
#include <chrono>

using namespace std::chrono;

int main(int argc, char *argv[])
{
if(argc != 2 ) 
  {
    std::cout << "use: "<< argv[0] <<"<filename>\n";
  }//if
  else {
    //assume argv[1] is the file to open
    ifstream inFile ( argv[1] );
    // check if file opened  
    if ( !inFile.is_open() )
    {
      std::cout << "Could not open file\n";
    }//if
    else {
      cout << "opened file" << endl; 
      
      char c;
      long int totalTime = 0;
      int additions = 0;
      int searches = 0;
      int removals = 0;
      string junk = "";
      BST<int> tree;
      
    auto start = high_resolution_clock::now();
    while (inFile >> additions)
    {
      tree.insert(additions); 
    }//while
    auto stop = high_resolution_clock::now();//clock ends
    auto insertTime = duration_cast<nanoseconds>(stop - start); 
    tree.display();
    
    inFile.clear();//handle new line

    inFile >> c;// the $ in text file

    //search
    while (inFile >> searches)
    {
      tree.search(searches);
    }//while
    
    inFile.clear();//end of line
    inFile >> c;//second $
 
    auto start2 = high_resolution_clock::now();
    while(inFile >> removals)
    {
      tree.remove(removals);
    }//
    auto stop2 = high_resolution_clock::now();//clock ends
    auto removalTime = duration_cast<nanoseconds>(stop2 - start2); 
    
    tree.display();//removals
    
    cout << endl;
    
    totalTime = insertTime.count() + removalTime.count();   
        
    cout << " Traversal Count: " << tree.traversalCount << endl;   
    cout << endl << " Runtime in nanoseconds : " << totalTime << " ns" << endl;
    }//else
}//else
} 
