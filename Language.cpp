#include "Language.h"
#include "JsonParser.h"


namespace dxco {

Language* Language::instance = NULL;

Language::Language() {
	std::string filename;
	switch(cocos2d::CCApplication::sharedApplication()->getCurrentLanguage()) {
	case cocos2d::kLanguageSpanish:
		filename = "lang/es.json";
		break;
	default: filename = "lang/en.json";
	}

	this->texts = JsonParser::parseJsonFile(filename);
}

std::string Language::get(std::string code) {

	if (instance == NULL) {
		instance = new Language();
	}

	if (!instance->texts->HasMember(code.c_str())) {
		CCLOG("WARNING! unknown language code: %s", code.c_str());
	}

	return (*(instance->texts))[code.c_str()].GetString();
}

} /* namespace dxco */
