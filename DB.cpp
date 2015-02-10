#include "DB.h"

namespace dxco {

std::map<std::string, int> DB::icache;
std::map<std::string, std::string> DB::scache;

void DB::putString(const std::string& key, const std::string& value) {
	cocos2d::CCUserDefault::sharedUserDefault()->setStringForKey(key.c_str(), value);
	cocos2d::CCUserDefault::sharedUserDefault()->flush();
	DB::scache[key] = value;
}

void DB::putInteger(const std::string& key, const int& value) {
	cocos2d::CCUserDefault::sharedUserDefault()->setIntegerForKey(key.c_str(), value);
	cocos2d::CCUserDefault::sharedUserDefault()->flush();
	DB::icache[key] = value;
}

std::string DB::getString(const std::string& key) {
	if (DB::scache.count(key)) {
		return DB::scache[key];
	}
	return cocos2d::CCUserDefault::sharedUserDefault()->getStringForKey(key.c_str());
}

int DB::getInteger(const std::string& key, int def) {
	if (DB::icache.count(key)) {
		return DB::icache[key];
	}
	return cocos2d::CCUserDefault::sharedUserDefault()->getIntegerForKey(key.c_str(), def);
}

} /* namespace dxco */
