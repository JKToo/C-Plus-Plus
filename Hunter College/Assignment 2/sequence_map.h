
#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include <iostream>
#include <vector>
using namespace std;
class SequenceMap{
public:
	//Default constructor
	SequenceMap() = default;
	//Copy Constructor
	SequenceMap(const SequenceMap &rhs) = default;
	//Copy assignment
	SequenceMap& operator= (const SequenceMap &rhs) = default;
	//Move constructor
	SequenceMap(SequenceMap &&rhs) = default;
	//Move assignment
	SequenceMap& operator=(SequenceMap &&rhs) = default;
	//Destructor
	~SequenceMap() = default;
	
	/*
	A constructor SequenceMap(const string &a_rec_seq, const
	string &an_enz_acro),that constructs a SequenceMap from	two	strings	
	(note that now the vector enzyme_acronyms_ will	contain	just one element,	
	the	an_enz_acro) 
	*/
    SequenceMap(const string &a_rec_seq, const string &an_enz_acro){
        recognition_sequence_ = a_rec_seq;
        enzyme_acronyms_.push_back(an_enz_acro);
    }
	
	/* 
	operates based on the regular string comparison between the recognition_sequence_ strings (this will be a one line function)
	*/
    bool operator<(const SequenceMap &rhs) const{
        return recognition_sequence_ < rhs.recognition_sequence_;
    }
  
    // Overload << Operator
    friend ostream &operator<<(ostream &out, const SequenceMap &map){
        for(unsigned int i = 0; i < map.enzyme_acronyms_.size(); ++i){
            cout << map.enzyme_acronyms_[i] << " ";
        }
        return out;
    }

	/* 
	This	function assumes that the object’s recognition_sequence_ and	
	other_sequence.recognition_sequence_ are equal to each other. The	
	function Merge() merges	the	other_sequence.enzyme_acronym_ with	
	the	object’s enzyme_acronym_. The other_sequence object	will not be	
	affected.  
	*/
    void Merge(const SequenceMap &other_sequence){
        for(unsigned int i = 0; i < other_sequence.enzyme_acronyms_.size(); ++i){
            enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
        }
    }

	
private:
    string recognition_sequence_;                  
    vector<string> enzyme_acronyms_;  

};

#endif
