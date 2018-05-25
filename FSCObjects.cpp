/*
 * FSCObjects.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#include "FSCObjects.h"

#include <cstddef>
#include <iostream>

FSCObjects::FSCObjects() {
    
}

void FSCObjects::addObject(shared_ptr<FSCObject> object) {
    
    objects.push_back(object);
    
    idToObject[object->id] = object;

	shared_ptr<string> classIdentifier = object->getClassIdentifier();
        
        if (classIdentifier.get() == nullptr) {
            
            cout << "FSCComponents: cannot add component - component class identifier is nullptr. Quit.";
            
            exit(1);
        }

	identifierToComponentMap[*classIdentifier.get()] = object;

}

shared_ptr<FSCObject> FSCObjects::objectWithId(int id) {
    
    return idToObject[id];
    
}

shared_ptr<FSCObject> FSCObjects::objectAtIndex(unsigned int index) {
	if (index >= objects.size()) {
		return shared_ptr<FSCObject>();
	}

	return objects[index];
}

int FSCObjects::size() {
	return objects.size();
}

void FSCObjects::removeObjectAtIndex(unsigned int index) {
	if (index < objects.size()) {
		objects.erase(objects.begin() + index);
	}
}

void FSCObjects::removeAllObjects() {

    for (unsigned int i = 0; i < objects.size(); i++) {
        
        i--;
        objects.pop_back();
        
    }
    
}

shared_ptr<FSCObject> FSCObjects::objectWithIdentifier(shared_ptr<string> identifier) {

    auto component = identifierToComponentMap[*identifier.get()];
    
    return component;
}

void FSCObjects::removeObjectWithIdentifier(shared_ptr<string> identifier) {

	identifierToComponentMap.erase(*identifier.get());
}

FSCObjects::~FSCObjects() {
	// TODO Auto-generated destructor stub
}
