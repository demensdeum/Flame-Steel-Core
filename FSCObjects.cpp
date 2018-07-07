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
    
	if (object->getClassIdentifier().get() == nullptr) {

		throw logic_error("Trying to add object with classIdentifier = nullptr");

	}

	if (object->getInstanceIdentifier().get() == nullptr) {

		string errorString = "Trying to add object with instanceIdentifier = nullptr; With class identifier: ";
		errorString += *object->getClassIdentifier().get();

		throw logic_error(errorString);

	}

	auto objectInstanceIdentifierString = *object->getInstanceIdentifier().get();

	objects.push_back(object);
	uuidToObject[object->uuid] = object;
	instanceIdentifierToObjectMap[objectInstanceIdentifierString] = object;

	shared_ptr<string> classIdentifier = object->getClassIdentifier();
        
        if (classIdentifier.get() == nullptr) {
            
            cout << "FSCComponents: cannot add component - component class identifier is nullptr. Quit.";
            
            exit(1);
        }

	auto classIdentifierString = *classIdentifier.get();

	if (classIdentifierToComponentMap.find(classIdentifierString) != classIdentifierToComponentMap.end()) {

		auto objects = classIdentifierToComponentMap[classIdentifierString];
		objects.push_back(object);

	}
	else
	{
		vector<shared_ptr<FSCObject> > objects;
		objects.push_back(object);

		classIdentifierToComponentMap[classIdentifierString] = objects;
	}
}

void FSCObjects::removeObject(shared_ptr<FSCObject> object) {

	if (object.get() == nullptr)
	{
		throw logic_error("Trying to remove nullptr object");
	}

	auto index = 0;

	for (auto item : objects) {

		if (item->uuid.compare(object->uuid) == 0) {

			objects.erase(objects.begin() + index);
			return;
		}
		
		index += 1;
	}

}

shared_ptr<FSCObject> FSCObjects::objectWithUUID(string uuid) {
    
    return uuidToObject[uuid];
    
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

	objects.clear();
	uuidToObject.clear();
	classIdentifierToComponentMap.clear();
	instanceIdentifierToObjectMap.clear();

}

void FSCObjects::removeObjectWithClassIdentifier(shared_ptr<string> classIdentifier) {

	throw logic_error("FSCObjects::removeObjectWithClassIdentifier unimplemented");

}

vector<shared_ptr<FSCObject> > FSCObjects::objectsWithClassIdentifier(shared_ptr<string> identifier) {

	auto classIdentifierString = *identifier.get();

	if (classIdentifierToComponentMap.find(classIdentifierString) != classIdentifierToComponentMap.end()) {

		auto component = classIdentifierToComponentMap[classIdentifierString];
    
		return component;		

	}
	else {

		vector<shared_ptr<FSCObject> > emptyVector;

		return emptyVector;

	}
}

shared_ptr<FSCObject> FSCObjects::objectWithInstanceIdentifier(shared_ptr<string> instanceIdentifier) {

	auto instanceIdentifierString = *instanceIdentifier.get();

	if (instanceIdentifierToObjectMap.find(instanceIdentifierString) != instanceIdentifierToObjectMap.end()) {

		auto object = instanceIdentifierToObjectMap[instanceIdentifierString];

		return object;

	}
	else {

		return shared_ptr<FSCObject>();

	}
}

FSCObjects::~FSCObjects() {
	// TODO Auto-generated destructor stub
}
