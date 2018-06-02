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

class FSCObjects {
public:
	FSCObjects();

	void addObject(shared_ptr<FSCObject> object);
	void removeObjectAtIndex(unsigned int index);
	void removeAllObjects();

      shared_ptr<FSCObject> objectWithUUID(string uuid);
      shared_ptr<FSCObject> objectAtIndex(unsigned int index);
	vector<shared_ptr<FSCObject> > objectsWithClassIdentifier(shared_ptr<string> identifier);
	shared_ptr<FSCObject> objectWithInstanceIdentifier(shared_ptr<string> instanceIdentifier);
	void removeObject(shared_ptr<FSCObject> object);
	void removeObjectWithClassIdentifier(shared_ptr<string> classIdentifier);


	int size();

	virtual ~FSCObjects();

private:
	vector <shared_ptr<FSCObject> > objects;

      map <string, shared_ptr<FSCObject> > uuidToObject;
	map<string, vector<shared_ptr<FSCObject>> > classIdentifierToComponentMap;
	map<string, shared_ptr<FSCObject> > instanceIdentifierToObjectMap;
        
};

#endif /* FSCOBJECTS_H_ */
