
// Justin Too
// Main file for Part2(a) of Homework 2.
// Code will compile and run after you have completed sequence_map.h.
#include "avl_tree.h"
#include "bst_tree.h"
#include "sequence_map.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

namespace {

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be empty.

template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {

    // Code for running Part2(a)
    // Parse input file @db_filename and feel tree @a_tree
    // Then prompt the user for exactly three strings (do a loop) and
    // provide the results of find() as desrcribed in the assignment.
    ifstream db_file_(db_filename);
    string db_line;
 
    //Parse through each line
    while (getline(db_file_, db_line)) {
	stringstream string_line_(db_line);
	string recognition_sequence_;
	string enzyme_acronyms_;
	getline(string_line_, enzyme_acronyms_, '/');
	
		// End at '/' found
    	while (getline(string_line_, recognition_sequence_, '/')) { 
	    SequenceMap new_recognition_sequence_ { recognition_sequence_, enzyme_acronyms_ };
	    a_tree.insert(new_recognition_sequence_);
	  }
     }
		    
    string input_sequence_;
    for(int i = 0; i < 3; i++){  //Loop through 3 times for input
	   cin >> input_sequence_; //Checks for user input
	   SequenceMap check_{ input_sequence_, ""};
	   a_tree.displayValue(check_); //Will either display the element or Not found
    }	   
}

} // namespace


int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string param_tree(argv[2]);
  cout << "Input filename is " << db_filename << endl;
  cout << "Type of tree is " << param_tree << endl;
  if (param_tree == "BST") {
    BinarySearchTree<SequenceMap> a_tree;
    QueryTree(db_filename, a_tree);
  } else if (param_tree == "AVL") {
    AvlTree<SequenceMap> a_tree;
    QueryTree(db_filename, a_tree);
  } else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
