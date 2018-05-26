/*
 * FSCObjects.h
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#ifndef FSCOBJECTS_H_
#define FSCOBJECTS_H_

#include "FSCObject.h"

#include <vector>
#include <memory>
#include <string>
#include <map>

using namespace std;

class FSCObjects: public FSCObject {
public:
	FSCObjects();

	void addObject(shared_ptr<FSCObject> object);

        shared_ptr<FSCObject> objectWithUUID(string uuid);
        
        shared_ptr<FSCObject> objectAtIndex(unsigned int index);
        
	int size();

        vector <shared_ptr<FSCObject> > *getObjectsVector();
        
	void removeObjectAtIndex(unsigned int index);
	void removeAllObjects();

	virtual ~FSCObjects();

private:
	vector <shared_ptr<FSCObject> > objects;
        map <string, shared_ptr<FSCObject> > uuidToObject;
        
};

#endif /* FSCOBJECTS_H_ */