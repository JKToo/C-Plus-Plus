// Justin Too
// Main file for Part2(b) of Homework 2.
// Code will compile and run after you have completed sequence_map.h.

#include "avl_tree.h"
#include "bst_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

namespace {
template <typename TreeType>
float findSequence(const string file_name_, TreeType& a_tree){  //Find each string in the sequence file
  int successful_check_ = 0;
  float recursion_check_ = 0;
  ifstream current_(file_name_); 
  string input_;

  while( getline( current_, input_) ){
    SequenceMap check_( input_, "" );
    recursion_check_ += a_tree.find(check_); //increment recursion check
    if( a_tree.contains(check_)){
      successful_check_++;
    }
  }

  cout<< "4a: "<< successful_check_ << endl; // Outputs how many times successfully removed 
  recursion_check_ = recursion_check_/successful_check_;	//Average of recursion calls
  return recursion_check_;
}

template <typename TreeType>
float removeSequence(const string file_name_, TreeType& a_tree){ // Removes every other sequence 
  float recursion_check_ = 0;
  int removal_check_ = 0;
  ifstream current_(file_name_);
  string input_;
  int tracker_ = 0;
  while( getline( current_, input_) ){
    if( tracker_ % 2 == 0){	// Skips every other sequence
        SequenceMap check_( input_, "" );
        if(a_tree.contains(check_)) {	//Loop to find the sequence to remove, and to confirm that it was successfully removed
        	a_tree.remove(check_);  //If found then remove
       	if(!a_tree.contains(check_)) removal_check_++;  //Checks if removal was a success 
       	else continue;   
        }   
    }
    tracker_++; //Incremented tracker needed to remove every other line
  }
  recursion_check_ += a_tree.getRemove();
  cout<< "5a: "<< removal_check_ << endl; //total removals
  recursion_check_ = recursion_check_/removal_check_;
  return recursion_check_;
}


template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
    ifstream db_file_(db_filename);
    string db_line_;
 
    //Parse through each line
    while (getline(db_file_, db_line_)) {
	stringstream string_line_(db_line_);
	string recognition_sequence_;
	string enzyme_acronyms_;
	getline(string_line_, enzyme_acronyms_, '/');
	
		// End at '/' found and check if sequence is not empty
    	while (getline(string_line_, recognition_sequence_, '/') && (!recognition_sequence_.empty())) { 
	    SequenceMap new_recognition_sequence_ { recognition_sequence_, enzyme_acronyms_ };
	    a_tree.insert(new_recognition_sequence_);
	  }
     }
    
/*		Outputs		*/

     int node_count_ = a_tree.getNodeTracker();
     float node_depth_ = a_tree.getDepth();  //Retrieves the depth
     float depth_average_ = node_depth_ / node_count_;  //Calculates average depth of tree
     //2
     cout << "2: " << node_count_ << endl;
     
     //3
     cout << "3a: " << depth_average_ << endl;
     float node_ratio = (float)(depth_average_ / (float)log2(node_count_));  //Gets ratio of average depth to log2n
     cout << "3b: " << node_ratio << endl;

     //4
     float average_recursion_calls = findSequence(seq_filename, a_tree); //Displays 4a and returns average
     cout << "4b: " << average_recursion_calls << endl;

     //5
     float remove_calls = removeSequence(seq_filename, a_tree); //Displays 5a and returns average
     cout << "5b: " << remove_calls << endl;
     
     //6
     node_count_ = a_tree.getNodeTracker();
     node_depth_ = a_tree.getDepth();    //Retrieves the depth
     depth_average_ = node_depth_ / node_count_;  //Calculates average depth of tree
     cout << "6a: " << node_count_ << endl;
     cout << "6b: " << depth_average_ << endl;
     node_ratio = (float)(depth_average_ / (float)log2(node_count_));
     cout << "6c: " << node_ratio << endl;
  }
} // namespace
int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  const string param_tree(argv[3]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  cout << "Type of tree is " << param_tree << endl;
  if (param_tree == "BST") {
    BinarySearchTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);
  } else if (param_tree == "AVL") {
    AvlTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);
  } else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
