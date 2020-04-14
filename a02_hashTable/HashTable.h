// HashTable.h -- class template for a hash table using chaining

#include "List.h"

// client must provide a hash function with the following characteristics:
//		1 input parameter of DT (see below), passed by const reference
//	    returns an integer between 0 and size - 1, inclusive, where size is the
//		number of elements in the hash table
//		the name of the function is passed as the first parameter to the HashTable 
//		constructor
//		client may make as many hash functions for as many HashTables as desired
// if a struct is used for DT, a typical use of retrieve, remove, and update would
// be to set the key of an object and then pass the object into the function
// retrieve, remove, and update will return false if:
//		(1) the hash function supplied above does not return a valid index
//	    (2) the supplied key or element cannot be found in the hash table
// otherwise, these functions will return true if successful
// For retrieve, remove and update functions, if you are using an object as an element, a 
// typical use would be to set the key of the desired object to retrieve, remove, or
// update; then pass the object into the function.
// If an object of a struct is used for DT, the == operator must be 
// overloaded for it; the left and right operands are both DT objects
// the == comparison is used for finding elements, usually by key value
//		Exceptions can be thrown in the constructor, the (default) copy constructor,
// the (default) assignment operator, or the insert function if out of heap memory.

template <class DT>
class HashTable 
{
public:
	HashTable( int (*hf)(const DT &), int);  //The constructor prototype
	~HashTable();  //The destructor
	HashTable(const HashTable<DT>&);  //The copy constructor prototype
	HashTable<DT>& operator=(const HashTable<DT>&);  //The overload assignment operator
	bool insert( const DT &); // returns true if successful; returns
					                     // false if invalid index was returned 
										 // from the hash function
	bool retrieve( DT &);  // see description above class template
	bool deleteItem( DT & );
	void makeEmpty( );  //The function to remove all entries
	int getCollisions();
private:
	List<DT>* table;  //The underlying array of linked lists
	int (*hashfunc)(const DT &); // pointer to the hash function from client
	inline void deepCopy(const HashTable<DT>&);  //The deep copy prototype
	int size;  //The size of the underlying array
};

// The function definitions for a hash table using chaining follows

//The constructor
template <class DT>
HashTable<DT>::HashTable( int (*hf)(const DT &), int s )
{
	size=s;
	table= new List<DT>[size];
	hashfunc = hf;
}

//The destructor
template <class DT>
HashTable<DT>::~HashTable()
{
	makeEmpty();
	delete [] table;
}

//The copy constructor
template <class DT>
HashTable<DT>::HashTable(const HashTable<DT>& original)
{
	deepCopy(original);
}

//The overloaded assignment operator
template <class DT>
HashTable<DT>& HashTable<DT>::operator=(const HashTable<DT>& original)
{
	if (this==&original)
		return *this;
	delete [] table;
	deppCopy(original);
	return *this;
}

//The deep copy function
template <class DT>
inline void HashTable<DT>::deepCopy(const HashTable<DT>& original)
{
	size=original.size;
	hashfunc = original.hashfunc;
	table= new List<DT>[size];
	for(int i=0; i< size;i++)
	{
		table[i]=original.table[i];
	}
}

//The function to insert an item into the hash table
template <class DT>
bool HashTable<DT>::insert( const DT & newObject )
{
	int location = hashfunc( newObject );
	cout << "The calculated location in the insert function is " 
		<< location << endl;
	if ( location < 0 || location >= size )
		return false;
	table[ location ].insert( newObject ) ;
	return true;
}

//The function to locate and retireve a selected item in the hash table
template <class DT>
bool HashTable<DT>::retrieve( DT & retrieved )
{
	int location = hashfunc( retrieved );
	cout << "The calculated location in the retrieve function is "
		<< location << endl;
	if ( location < 0 || location >= size )
		return false;
	if ( !table[ location ].retrieve( retrieved ) )
		return false;
	return true;
}

template <class DT>
bool HashTable<DT>:: deleteItem( DT & deleted )
{
	int location = hashfunc( deleted );
	cout << "The calculated location in the deleteItem function is "
		 << location << endl;
	if ( location < 0 || location >= size )
		return false;
	return table[ location ].remove(deleted );
}

//The function to remove all entries in the hash table
template <class DT>
void HashTable<DT>::makeEmpty( )
{
	for ( int i = 0; i < size; i++ )
		table[ i ].makeEmpty( );
}

template <class DT>
int HashTable<DT>::getCollisions() {

       return  table[0].getCollisionCounter();

}
