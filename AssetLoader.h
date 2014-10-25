/*
 * AssetLoader.h
 *
 *  Created on: Oct 25, 2014
 *      Author: gsosarolon
 */

#ifndef ASSETLOADER_H_
#define ASSETLOADER_H_

#include <vector>
#include <string>

namespace dxco {

class AssetLoader {
public:
	AssetLoader();
	void addAsset(std::string assetPath);
	void loadNext();
	bool hasNext();
private:
	std::vector<std::string> assetsToLoad;
	int currentAsset;
};

} /* namespace dxco */
#endif /* ASSETLOADER_H_ */
