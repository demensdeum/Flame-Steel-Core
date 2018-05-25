/*
 * FSCObject.cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: demensdeum
 */

#include "FSCObject.h"

#include <iostream>
#include "FSCObjects.h"

using namespace std;

int FSCLastObjectID = 0;

FSCObject::FSCObject() {
        
    id = FSCLastObjectID;
    
    classIdentifier = shared_ptr<string>();
    instanceIdentifier = shared_ptr<string>();
    
    components = make_shared<FSCObjects>();
    
    FSCLastObjectID++;
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
	return components->objectWithIdentifier(identifier);
}

/*! removeComponent - remove component by identifier*/
void FSCObject::removeComponent(shared_ptr<string> identifier) {
	components->removeObjectWithIdentifier(identifier);
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
