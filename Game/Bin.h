#pragma once
#include <vector>
#include <iterator>


// A Bin is a generic storage class that uses a vector of pointers.
// Stored objects will never be moved so pointers never become invalidated.
// can loop over objects
template <class T>
class Bin
{
public:

	// constructor
	Bin() {

	}

	// destructor
	~Bin() {

		// delete all stored objects
		for (auto& e : m_vector) {
			delete e;
		}
	}

	template <class U, class... Args>
	U* add(Args&&... args) {
		U* temp = new U(std::forward<Args>(args)...);
		m_vector.push_back(temp);
		return temp;
	}


	void add(T* pointer) {
		m_vector.push_back(pointer);
	}

	// swap and pop
	void remove(T* trash) {
		
		// deleted the object required
		delete trash;

		// fill the hole by copying the last element
		trash = m_vector.back();

		// then pop the old last element
		m_vector.pop_back();

	}

	/// iterators
	// used in for each loops

	typename std::vector<T*>::iterator begin() { return m_vector.begin(); }
	typename std::vector<T*>::iterator end() { return m_vector.end(); }

private:
	std::vector<T*> m_vector;
};