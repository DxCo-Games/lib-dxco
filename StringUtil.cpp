#include "StringUtil.h"
#include <sstream>

namespace dxco {

std::string StringUtil::toString(int data) {
	std::ostringstream ss;
	ss << data;
	return ss.str();
}

std::string StringUtil::toString(float data) {
	std::ostringstream ss;
	ss << data;
	return ss.str();
}

std::string StringUtil::intToKString(int number) {

	if (number < 1000) { // full number
		return StringUtil::toString(number);
	}

	if (number < 10000) { // 1 decimal place
		return StringUtil::toString((float)((int)((number / 1000.0) * 10) / 10.0)) + "k";
	}

	return StringUtil::toString(number / 1000) + "k"; // no decimal place
}

int StringUtil::toInt(std::string data) {
	int value;
	std::istringstream ss(data);
	ss >> value;

	return value;
}

std::vector<std::string> StringUtil::split(const std::string &s, char delim) {

	std::vector<std::string> elems;

	std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
	}

    return elems;
}

std::string StringUtil::padLeft(std::string &str, const int stringSize, const char paddingChar)
{
	if(stringSize > str.size()) {
		str.insert(0, stringSize - str.size(), paddingChar);
	}

	return str;
}

std::string StringUtil::padLeft(int number, const int stringSize)
{
	std::string numberString = toString(number);

	return padLeft(numberString, stringSize, '0');
}

std::string sFormat(std::string s, std::string value) {
	char buff[200];
	sprintf(buff, s.c_str(), value.c_str());
	std::string buffAsStdStr = buff;
	return buff;
}
std::string iFormat(std::string s, int value) {
	char buff[200];
	sprintf(buff, s.c_str(), value);
	std::string buffAsStdStr = buff;
	return buff;
}

} /* namespace dxco */
