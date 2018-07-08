/*
 * FSCObject.cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: demensdeum
 */

#include "FSCObject.h"

#include <iostream>
#include "FSCObjects.h"
#include <FlameSteelFramework/FlameSteelCore/sole.hpp>

using namespace std;

FSCObject::FSCObject() {
        
	auto uuidContainer = sole::uuid0();
	uuid = uuidContainer.str();
    
	classIdentifier = shared_ptr<string>();
	instanceIdentifier = shared_ptr<string>();
    
	components = make_shared<FSCObjects>();
}

bool FSCObject::containsComponentWithIdentifier(shared_ptr<string> identifier) {

	return components->containsComponentWithIdentifier(identifier);

}

void FSCObject::setInstanceIdentifier(shared_ptr<string> instanceIdentifier) {
    
	this->instanceIdentifier = instanceIdentifier;
        
}

void FSCObject::setClassIdentifier(shared_ptr<string> classIdentifier) {
    
	this->classIdentifier = classIdentifier;
        
}

shared_ptr<string> FSCObject::getInstanceIdentifier() {
	return this->instanceIdentifier;
}

shared_ptr<string> FSCObject::getClassIdentifier() {
	return this->classIdentifier;
}

shared_ptr<FSCObject> FSCObject::getComponent(shared_ptr<string> identifier) {

	auto objects = components->objectsWithClassIdentifier(identifier);
	
	if (objects.size() < 1)
	{
		string errorString = "FSCObject::getComponent - there is no component with class identifier: ";
		errorString += *identifier.get();

		throw logic_error(errorString);
	}
	else if (objects.size() > 1)
	{
		string errorString = "FSCObject::getComponent - trying to get component from many components with same class identifier: ";
		errorString += *identifier.get();

		throw logic_error(errorString);
	}

	auto object = objects[0];

	return object;
}

/*! removeComponent - remove component by identifier*/
void FSCObject::removeComponent(shared_ptr<string> identifier) {
	components->removeObjectWithClassIdentifier(identifier);
}

/*! addComponent - add component*/
void FSCObject::addComponent(shared_ptr<FSCObject> component) {

	if (component.get() == nullptr) {

		cout << "Trying to add empty object... about" << endl;
		exit(1);
	}

	if (components.get() == nullptr) {

		cout << "Trying to insert component into empty object... about" << endl;
		exit(1);

	}

	components->addObject(component);
}

FSCObject::~FSCObject() {
	// TODO Auto-generated destructor stub
}
