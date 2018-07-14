/*
 * FSCController.h
 *
 *  Created on: Jul 10, 2016
 *      Author: demensdeum
 */

#ifndef FSCCONTROLLER_H_
#define FSCCONTROLLER_H_

#include "Object.h"

using namespace FlameSteelCore;

namespace FlameSteelCore  {

/*! FSCController - controller class from MVC pattern */

class Controller : public Object  {
public:
	Controller();
	virtual ~Controller();

	/*! step() - method to be called inside loop, represents one iteration of some process */
	virtual void step();
};

};

#endif /* FSCCONTROLLER_H_ */
