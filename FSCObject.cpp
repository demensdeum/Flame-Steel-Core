/*
 * FSCObject.cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: demensdeum
 */

#include "FSCObject.h"
#include "FSCComponents.h"

#include <iostream>

#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>

using namespace std;

FSCObject::FSCObject() {
        
	boost::uuids::random_generator generator;
	uuid = boost::uuids::to_string(generator());

	classIdentifier = shared_ptr<string>();
	instanceIdentifier = shared_ptr<string>();
    
	components = shared_ptr<FSCComponents>();
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
    
	if (!this->components) {
            
		printf("warning cannot get component - components array is nullptr\n");

		return shared_ptr<FSCObject>();
                
	}
	else
	{
		return this->components->getComponent(identifier);
	}    
}

/*! removeComponent - remove component by identifier*/
void FSCObject::removeComponent(shared_ptr<string> identifier) {
	this->components->removeComponent(identifier);
}

shared_ptr<FSCObject> FSCObject::copy() {
	return shared_ptr<FSCObject>();
}

/*! addComponent - add component*/
void FSCObject::addComponent(shared_ptr<FSCObject> component) {
	if (!this->components)
	{
		shared_ptr<FSCComponents> components(new FSCComponents());
		this->components = components;
	}
	this->components->addComponent(component);
}

void FSCObject::debugPrintout() {

    if (classIdentifier == nullptr) {
        
        cout << "classIdentifier = nullptr. Quit" << endl;
        exit(1);
    }
    
    if (instanceIdentifier == nullptr) {
        
        cout << "instanceIdentifier = nullptr. Quit" << endl;
        exit(1);
    }
	cout << "My class: " << classIdentifier->c_str() << endl;
        cout << "My instance identifier: " << instanceIdentifier->c_str() << endl;

	cout << "My components: " << endl;

	if (this->components)
	{
		this->components->debugPrintout();
	}
}

FSCObject::~FSCObject() {
	// TODO Auto-generated destructor stub
}
