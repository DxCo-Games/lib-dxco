#ifndef DB_H_
#define DB_H_

#include "cocos2d.h"

namespace dxco {

class DB {
public:
	static void putString(const std::string& key, const std::string& value);
	static void putInteger(const std::string& key, const int& value);

	static std::string getString(const std::string& key);
	static int getInteger(const std::string& key, int def=0);

	static std::map<std::string, int> icache;
	static std::map<std::string, std::string> scache;
};

} /* namespace dxco */
#endif /* DB_H_ */
