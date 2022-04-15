//Justin Too

#include <fstream>
#include <iostream>
#include <string>

// You can change to quadratic probing if you
// haven't implemented double hashing.
#include "double_hashing.h"
#include "quadratic_probing.h"
#include "linear_probing.h"
using namespace std;

// You can add more functions here.

/*
  Formats words to set words to lower case and remove special characters
  @returns word after format
 */
string FormatWord(string document_word_) {
	for(size_t i = 0; i < document_word_.size(); i++){
		document_word_[i] = tolower(document_word_[i]);		//Changes chars to lowercase
	}

	string word_holder_ = document_word_;	//Makes a copy of document_word_ to modify
	int size_of_word_ = word_holder_.size();
	if(size_of_word_ == 1 && (!isalnum(word_holder_[0]))){	//Checks the beginning
		word_holder_.erase(0,1);
		document_word_ = word_holder_;	//set document_word_ to the new world_holder_
	}
	else if(size_of_word_ > 1 && (!isalnum(word_holder_[size_of_word_-1]))){	//Checks the end
		word_holder_.erase(size_of_word_-1, 1);
		document_word_ = word_holder_;	//set document_word_ to the new world_holder_
	}
	document_word_ = word_holder_;	//set document_word_ to the new world_holder_
	return document_word_;
}

/*
  Checks Case A, B, C
  Case A to check while adding characters
  Case B to check when removing characters
  Case C to check when swapping characters
*/
void CaseCheck(const HashTableDouble<string>& dictionary, string document_word_ ) {
	string temp_word_ = document_word_;		//Creates copy of the word

	//Case A (Add characters)
	for(size_t i= 0; i < document_word_.size()+1; i++) {	//Loop to traverse through word + 1 to have space for insert
		for(char ch = 'a'; ch <= 'z'; ch++)	{  //Loop through ASCII from a to z
			temp_word_.insert(i, 1, ch);
			if(dictionary.Contains(temp_word_)) {
				cout << "*** " << document_word_ << " -> " << temp_word_ << " *** case A" << endl;
			}
			temp_word_ = document_word_;	//Resets temp_word_ back to default word
		}
	}	  

	//Case B (Remove characters)
	temp_word_ = document_word_;   //reverts back to copy of the word
	for(size_t i = 0; i < document_word_.size(); i++) { //Loop to traverse through word
            temp_word_.erase(i,1);	//Removes character in position i
            if(dictionary.Contains(temp_word_)) {
                    cout << "*** " << document_word_ << " -> " << temp_word_ << " *** case B"<< endl;
            }
			temp_word_ = document_word_; //Resets temp_word_ back to default word
	}
	
	//Case C (Swap characters)
	temp_word_ = document_word_;   //reverts back to copy of the word
	for(size_t i = 0; i < document_word_.size(); i++) {  //Loop to traverse through word
		string temp_word_ = document_word_;
		swap(temp_word_[i],temp_word_[i+1]);	//Swap characters in ith position
		if(dictionary.Contains(temp_word_)) {
			cout << "*** " << document_word_ << " -> " << temp_word_ << " *** case C" << endl;
		}
		temp_word_ = document_word_;	 //Resets temp_word_ back to default word
	}	
}

// Creates and fills double hashing hash table with all words from
// dictionary_file
HashTableDouble<string> MakeDictionary(const string &dictionary_file) {
  HashTableDouble<string> dictionary_hash;
  // Fill dictionary_hash.
  dictionary_hash.MakeEmpty();	//Empty incase it contains content

  string dictionary_words_;
  ifstream dictionary_input_(dictionary_file);

	while(!dictionary_input_.eof()){
		dictionary_input_ >> dictionary_words_;
	  dictionary_hash.Insert(dictionary_words_);
  }
  return dictionary_hash;
}

// For each word in the document_file, it checks the 3 cases for a word being
// misspelled and prints out possible corrections
void SpellChecker(const HashTableDouble<string>& dictionary, const string document_file) {
	string document_words_;
	ifstream new_document_file_(document_file); 
	while(!new_document_file_.eof()){
			new_document_file_ >> document_words_;
			string formatted_words_ = FormatWord(document_words_);

			if(dictionary.Contains(formatted_words_)){
				cout << formatted_words_ << " is CORRECT" << endl;
			}
			else{		
				cout << formatted_words_ << " is INCORRECT" << endl;			
				CaseCheck(dictionary, formatted_words_);
			}		
	}
}

// @argument_count: same as argc in main
// @argument_list: save as argv in main.
// Implements
int testSpellingWrapper(int argument_count, char** argument_list) {
    const string document_filename(argument_list[1]);
    const string dictionary_filename(argument_list[2]);

    // Call functions implementing the assignment requirements.
    HashTableDouble<string> dictionary = MakeDictionary(dictionary_filename);
    SpellChecker(dictionary, document_filename);

    return 0;
}

// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>"
         << endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);
  
  return 0;
}