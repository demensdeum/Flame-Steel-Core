/*
 * FSCUtils.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#include "FSCUtils.h"

#include <stdlib.h>
#include <time.h>

FSCUtils::FSCUtils() {
    // TODO Auto-generated constructor stub

}

int FSCUtils::FSCRandomInt(int maximalInt) {

    if (maximalInt == 0) {
        return 0;
    }

    int randomInt = rand() % maximalInt;

    return randomInt;
}

shared_ptr<string> FSCUtils::localizedString(shared_ptr<string> key) {

    return key;
}

FSCUtils::~FSCUtils() {
    // TODO Auto-generated destructor stub
}

string FlameSteelCore::Utils::LocalizedString(const char *key) {

	return string(key);

}