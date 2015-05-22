#ifndef DXCO_LANGUAGE_H_
#define DXCO_LANGUAGE_H_

#include <string>
#include "rapidjson/document.h"

#include "cocos2d.h"

namespace dxco {

class Language {
public:
	Language();
	rapidjson::Document* texts;

	static std::string get(std::string code);

	static Language* instance;
};

} /* namespace dxco */

#endif /* DXCO_LANGUAGE_H_ */
