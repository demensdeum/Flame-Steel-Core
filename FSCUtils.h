/*
 * FSCUtils.h
 *
 *  Created on: Jul 31, 2016
 *      Author: demensdeum
 */

#ifndef FSCUTILS_H_
#define FSCUTILS_H_

#include <string>
#include <memory>

using namespace std;

/*! FSCUtils - contains common utils functions for Flame Steel Engine */

class FSCUtils {
public:
	FSCUtils();

	/*! FSCRandomUInt - return random unsigned integer from zero to maximalUInt*/
	static int FSCRandomInt(int maximalInt);
        
	static bool FSCRandomBool();

        static shared_ptr<string> localizedString(shared_ptr<string> key);

	virtual ~FSCUtils();
};

namespace FlameSteelCore {
namespace Utils {

	string LocalizedString(const char *key);

}
}

#endif /* FSCUTILS_H_ */
