/*
 * Message.h
 *
 *  Created on: Jul 30, 2016
 *      Author: demensdeum
 */

#ifndef FSCMESSAGE_H_
#define FSCMESSAGE_H_

/*! Message - class used to send messages between objects */

#include "Object.h"

#include <memory>

using namespace std;
using namespace FlameSteelCore;

namespace FlameSteelCore {

class Message: public Object {
public:
	Message(shared_ptr<string> title, shared_ptr<string> text);

	/*! Message - get message title @return title*/
        
	shared_ptr<string> getTitle();

	/*! Message - get message text @return text*/
        
	shared_ptr<string> getText();

	virtual ~Message();

private:
	shared_ptr<string> title;
	shared_ptr<string> text;
};

};

#endif /* FSCMESSAGE_H_ */
