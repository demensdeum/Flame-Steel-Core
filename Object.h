/*
 * Object.h
 *
 *  Created on: Jul 10, 2016
 *      Author: demensdeum
 */

#ifndef FSCOBJECT_H_
#define FSCOBJECT_H_

#include <string>
#include <memory>
#include "Serializable.h"

class Objects;

using namespace std;

namespace FlameSteelCore {

/*! Object - base class of Flame Steel Core */

class Object : public Serializable {
public:
	Object();
	virtual ~Object();

        string uuid;
        
	/*! instanceIdentifier setter - string identifier of object */
	void setInstanceIdentifier(shared_ptr<string> gameSceneIdentifier);
        
	/*! classIdentifier setter - string identifier of object class */
	void setClassIdentifier(shared_ptr<string> gameSceneClass);

	/*! instanceIdentifier - getter string identifier of object @return instanceIdentifier*/
	shared_ptr<string> getInstanceIdentifier();

	/*! instanceIdentifier - getter string identifier of object @return classIdentifier*/
	shared_ptr<string> getClassIdentifier();

	/*! addComponent - add component*/
	void addComponent(shared_ptr<Object> component);

	/*! getComponent - get component by identifier*/
	shared_ptr<Object> getComponent(shared_ptr<string> identifier);

	/*! removeComponent - remove component by identifier*/
	void removeComponent(shared_ptr<string> identifier);
        
	bool containsComponentWithIdentifier(shared_ptr<string> identifier);

private:
	/*! instanceIdentifier - string identifier of object */
	shared_ptr<string> instanceIdentifier;
        
	/*! classIdentifier - string identifier of object class */
	shared_ptr<string> classIdentifier;
        
	/*! components - getter list of components from CES pattern @return components*/
	shared_ptr<Objects> components;

};

};

#endif /* FSCOBJECT_H_ */
