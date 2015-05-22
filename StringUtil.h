#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

#include <string>
#include <vector>

namespace dxco {

class StringUtil {
public:
	static std::string toString(int data);
	static std::string toString(float data);
	static int toInt(std::string data);
	static std::vector<std::string> split(const std::string &s, char delim);
	static std::string padLeft(std::string &str, const int stringSize, const char paddingChar = ' ');
	static std::string padLeft(int number, const int stringSize);
	static std::string intToKString(int number);

	static std::string sFormat(std::string s, std::string value);
	static std::string iFormat(std::string s, int value);
};

} /* namespace dxco */
#endif /* STRINGUTIL_H_ */
