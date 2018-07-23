#pragma once
#include <unordered_map>
#include <string>
#include <iostream>


// A ResourceMap uses a std::unordered_map to link a name and a resource
// Resources are loaded from a folder using their name, folder.name.extension
// A Resource called "Error" must exist
template<typename Resource>
class ResourceMap {

public:

	// constructor
	ResourceMap(const std::string& folder, const std::string& extention) :
		m_folder("Resources/" + folder + "/"),
		m_extention("." + extention)
	{}

	Resource& get(const std::string& name) {

		if (!exists(name))	// if the resource doesn't exist yet, add it
			add(name);

		return m_resources.at(name);
	}

	// checks if a resource exists within m_resources
	bool exists(const std::string& name) const {
		return m_resources.find(name) != m_resources.end();
	}

	// adds a resource and name pair to m_resources
	void add(const std::string& name) {

		Resource r;

		//if the resource fails to load, then it adds a default "fail" resource
		if (!r.loadFromFile(getFileName(name))) {

			std::cout << "Error: Failed to load " << name << " from file - ResourceManager.h\n";
			Resource fail;
			fail.loadFromFile(m_folder + "Error" + m_extention);
			m_resources.insert(std::make_pair(name, fail));			// make pair makes a key from name and pairs it with the resource
		}
		else {
			m_resources.insert(std::make_pair(name, r));
		}
	}

private:

	std::string getFileName(const std::string& name) {
		return m_folder + name + m_extention;
	}

	// folder to load the resources from
	const std::string m_folder;
	const std::string m_extention;

	// an unordered map uses hashes and "buckets"
	// they are faster for accessing individual elements but slower for range based loops
	std::unordered_map<std::string, Resource> m_resources;
};
