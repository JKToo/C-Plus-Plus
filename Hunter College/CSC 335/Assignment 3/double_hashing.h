
#ifndef DOUBLE_PROBING_H
#define DOUBLE_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>


namespace {

// Internal method to test if a positive number is prime.
bool IsPrimeDouble(size_t n) {
  if( n == 2 || n == 3 )
    return true;
  
  if( n == 1 || n % 2 == 0 )
    return false;
  
  for( int i = 3; i * i <= n; i += 2 )
    if( n % i == 0 )
      return false;
  
  return true;
}


// Internal method to return a prime number at least as large as n.
int NextPrimeDouble(size_t n) {
  if (n % 2 == 0)
    ++n;  
  while (!IsPrimeDouble(n)) n += 2;  
  return n;
}

}  // namespace


// Quadratic probing implementation.
template <typename HashedObj>
class HashTableDouble {
 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};

  explicit HashTableDouble(size_t size = 101) : array_(NextPrimeDouble(size))
    { 
		MakeEmpty(); 
		RValue = 89; //If RValue is not provided
	}
  
  bool Contains(const HashedObj & x) const {
    return IsActive(FindPos(x));
  }
  
  void MakeEmpty() {
    current_size_ = 0;
    for (auto &entry : array_)
      entry.info_ = EMPTY;
  }

  bool Insert(const HashedObj & x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos].element_ = x;
    array_[current_pos].info_ = ACTIVE;
    
    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();    
    return true;
  }
    
  bool Insert(HashedObj && x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos] = std::move(x);
    array_[current_pos].info_ = ACTIVE;

    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();
      
    return true;
  }

  bool Remove(const HashedObj & x) {
    size_t current_pos = FindPos(x);
    if (!IsActive(current_pos))
      return false;

    array_[current_pos].info_ = DELETED;
    return true;
  }

/*   ------------------------------------ */

// Accessor to get size
int getElements() {
	return current_size_;
}

//Accessor to get Array size
int getTableSize(){
	return array_.size();
}

//Accessor to get number of collisions
int getCollisions(){
	return collisions_;
}

//Reset collisions
void resetCollision(){
	probes_ = 0;
	collisions_ = 0;
}

//Accessor to get probes
int getProbes(){
	return probes_;
}

//Modifier to set RValue
void setRValue(int n){
	RValue = n;
}


 private:        
  struct HashEntry {
    HashedObj element_;
    EntryType info_;
    
    HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY)
    :element_{e}, info_{i} { }
    
    HashEntry(HashedObj && e, EntryType i = EMPTY)
    :element_{std::move(e)}, info_{ i } {}
  };
    

  std::vector<HashEntry> array_;
  size_t current_size_;
  mutable size_t collisions_ = 0;  //Keep track of collisions;
  int RValue;
  mutable size_t probes_ = 0;
  
  
  bool IsActive(size_t current_pos) const
  { return array_[current_pos].info_ == ACTIVE; }  


  size_t FindPos(const HashedObj & x) const {
    size_t current_pos = InternalHash(x);

    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) 
    { 
      current_pos += HashDouble(x);  // Compute ith probe.

      if (current_pos >= array_.size())
      {
      	current_pos -= array_.size();	
      }    
            collisions_++;  //Increment collisions
			probes_++; //Increment probes
    }   
    
    return current_pos;
  }
     
  
  

  void Rehash() {
    std::vector<HashEntry> old_array = array_;

    // Create new double-sized, empty table.
    array_.resize(NextPrimeDouble(2 * old_array.size()));
    for (auto & entry : array_)
      entry.info_ = EMPTY;
    
    // Copy table over.
    current_size_ = 0;
    for (auto & entry :old_array)
      if (entry.info_ == ACTIVE)
	Insert(std::move(entry.element_));
  }  

  
  size_t InternalHash(const HashedObj & x) const {
    static std::hash<HashedObj> hf;
    return hf(x) % array_.size( );
  }
  
  /*
  	Second Hash function to calculate R - (x % R)
    @returns value of (R - (x % R))
  */
  size_t HashDouble(const HashedObj & x) const {
    static std::hash<HashedObj> hf;
    return RValue - (hf(x) % RValue);
  }
  
  
};

#endif  // DOUBLE_PROBING_H