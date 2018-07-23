#pragma once
#include <vector>

template <typename T>
class ObjectStorage
{
public:
	ObjectStorage();
	~ObjectStorage();

	T& operator[] (const size_t index);
	std::vector <T>& getRaw();

	const unsigned int addObject(T* object);
	void destroyObject(const size_t index);

	unsigned int size();
	typename std::vector<T>::iterator begin();
	typename std::vector<T>::iterator end();

private:
	// continuous list of type T
	std::vector <T> m_objects;
	// indicies keeps track of the swap and pop, other entities which need to know about an object have an index to indicies
	std::vector <unsigned int> m_indicies;
	// free keeps track of free spots in indicies
	std::vector <unsigned int> m_free;
};


template<typename T>
ObjectStorage<T>::ObjectStorage()
{}

template<typename T>
ObjectStorage<T>::~ObjectStorage()
{}

template<typename T>
T& ObjectStorage<T>::operator[] (const size_t index) {
	return m_objects[m_indicies[index]];
}
template<typename T>
std::vector <T>&  ObjectStorage<T>::getRaw() {
	return m_objects;
}

template<typename T>
const unsigned int ObjectStorage<T>::addObject(T* object) {

	// create using new: eg. objectStorage.createObject <objectType> (new objectType(constructor arguments))
	m_objects.push_back(*object);
	if (m_free.size() > 0) {
		unsigned int index = m_free.back();
		m_free.pop_back();
		m_indicies[index] = m_objects.size() - 1;
		return index;
	}
	else {
		m_indicies.push_back(m_objects.size() - 1);
		return m_indicies.size() - 1;
	}
}

template<typename T>
void ObjectStorage<T>::destroyObject(const size_t index) {

	// sets the index pointing to the last object to point to the deleted object, ready for swaping
	for (size_t i = 0; i < m_indicies.size(); i++) {
		if (m_indicies[i] == m_objects.size() - 1) {
			m_indicies[i] = m_indicies[index];
			break;
		}
	}
	// swap and pop
	std::swap(m_objects[m_indicies[index]], m_objects.back());
	m_objects.pop_back();
	// add the old index to free
	m_free.push_back(index);
	m_indicies[index] = -1;
}

template<typename T>
unsigned int ObjectStorage<T>::size() {
	return m_objects.size();
}

template<typename T>
typename std::vector<T>::iterator ObjectStorage<T>::begin() {
	return m_objects.begin();
}

template<typename T>
typename std::vector<T>::iterator ObjectStorage<T>::end() {
	return m_objects.end();
}
