/*
 * Object.cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: demensdeum
 */

#include "Object.h"

#include <iostream>
#include "Objects.h"

using namespace std;

Object::Object() {
        
	FSGL_OBJECT_ID += 1;
	uuid = std::to_string(FSGL_OBJECT_ID);
    
	classIdentifier = shared_ptr<string>();
	instanceIdentifier = shared_ptr<string>();
    
	components = make_shared<Objects>();
}

bool Object::containsComponentWithIdentifier(shared_ptr<string> identifier) {

	return components->containsComponentWithIdentifier(identifier);

}

void Object::setInstanceIdentifier(shared_ptr<string> instanceIdentifier) {
    
	this->instanceIdentifier = instanceIdentifier;
        
}

void Object::setClassIdentifier(shared_ptr<string> classIdentifier) {
    
	this->classIdentifier = classIdentifier;
        
}

shared_ptr<string> Object::getInstanceIdentifier() {
	return this->instanceIdentifier;
}

shared_ptr<string> Object::getClassIdentifier() {
	return this->classIdentifier;
}

shared_ptr<Object> Object::getComponent(shared_ptr<string> identifier) {

	auto objects = components->objectsWithClassIdentifier(identifier);
	
	if (objects.size() < 1)
	{
		string errorString = "Object::getComponent - there is no component with class identifier: ";
		errorString += *identifier.get();

		throw logic_error(errorString);
	}
	else if (objects.size() > 1)
	{
		string errorString = "Object::getComponent - trying to get component from many components with same class identifier: ";
		errorString += *identifier.get();

		throw logic_error(errorString);
	}

	auto object = objects[0];

	return object;
}

/*! removeComponent - remove component by identifier*/
void Object::removeComponent(shared_ptr<string> identifier) {
	components->removeObjectWithClassIdentifier(identifier);
}

/*! addComponent - add component*/
void Object::addComponent(shared_ptr<Object> component) {

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

Object::~Object() {
	// TODO Auto-generated destructor stub
}
