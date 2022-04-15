//Justin Too

#include <fstream>
#include <iostream>
#include <string>

// Uncomment when you implemented linear probing & double hashing
#include "linear_probing.h"
#include "double_hashing.h"
#include "quadratic_probing.h"

using namespace std;


// You can add more functions here
 
// @hash_table: a hash table (can be linear, quadratic, or double)
// @words_filename: a filename of input words to construct the hash table
// @query_filename: a filename of input words to test the hash table
template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
    hash_table.MakeEmpty();
    //..Insert your own code

   /* cout <<"I will run the Hash code\nTestFunctionForHashTables..." << endl;
    cout << "Words filename: " << words_filename << endl;
    cout << "Query filename: " << query_filename << endl << endl;
    
    cout << "Inserting words into the Hash table...\n" << endl;
    
    cout << "Statistics for this Hash Table:" << endl;*/

	//Parse through files 
	string get_words_;
    ifstream input_file_(words_filename);
	while(!(input_file_.eof())){
		input_file_ >> get_words_;
		hash_table.Insert(get_words_);
	}


    cout << "number_of_elements: " << hash_table.getElements() << endl;
    cout << "size_of_table: " << hash_table.getTableSize() << endl;
    cout << "load_factor: " << (float) hash_table.getElements() / (float) hash_table.getTableSize() << endl;
	cout << "average_collisions: " << (float) hash_table.getCollisions() / (float) hash_table.getElements() << endl;
    cout << "total_collisions: " << hash_table.getCollisions() << endl;
    
    cout << endl;

    
	//Parse through to find if found in hash table, and find probes
	string current_word_;
	ifstream input_words_(query_filename);

	while(!input_words_.eof()){
		input_words_ >> current_word_;
		hash_table.resetCollision();
		if(hash_table.Contains(current_word_)){
			cout << current_word_ << " Found " << hash_table.getProbes()+1 << endl;
		}
		else if(!hash_table.Contains(current_word_)){
			cout << current_word_ << " Not_Found " << hash_table.getProbes()+1 << endl;
		}
	}
	
}

// @argument_count: argc as provided in main
// @argument_list: argv as provided in imain
// Calls the specific testing function for hash table (linear, quadratic, or double).
int testHashingWrapper(int argument_count, char **argument_list) {
    const string words_filename(argument_list[1]);
    const string query_filename(argument_list[2]);
    const string param_flag(argument_list[3]);
    int R = 89;
    if (argument_count == 5) {
	const string rvalue(argument_list[4]);
	R = stoi(rvalue);
    }

    if (param_flag == "linear") {
      // Uncomment below when you have implemented linear probing.
       HashTableLinear<string> linear_probing_table;
       TestFunctionForHashTable(linear_probing_table, words_filename,
       			 query_filename);
    } else if (param_flag == "quadratic") {
	HashTable<string> quadratic_probing_table;
	TestFunctionForHashTable(quadratic_probing_table, words_filename,
				 query_filename);
    } else if (param_flag == "double") {
	cout << "r_value: " << R << endl;
        // Uncomment below when you have implemented double hashing.
	 HashTableDouble<string> double_probing_table;
	 double_probing_table.setRValue(R); //Sets RValue in HashTableDouble class
	 TestFunctionForHashTable(double_probing_table, words_filename,
	 			 query_filename);
    } else {
	cout << "Unknown tree type " << param_flag
	     << " (User should provide linear, quadratic, or double)" << endl;
    }
    return 0;
}

// Sample main for program create_and_test_hash. DO NOT CHANGE IT.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testHashingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char **argv) {
    if (argc != 4 and argc != 5) {
	cout << "Usage: " << argv[0]
	     << " <wordsfilename> <queryfilename> <flag>" << endl;
	cout << "or Usage: " << argv[0]
	     << " <wordsfilename> <queryfilename> <flag> <rvalue>" << endl;
		 
	return 0;
    }

    testHashingWrapper(argc, argv);
    return 0;
}