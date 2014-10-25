/*
 * AssetLoader.cpp
 *
 *  Created on: Oct 25, 2014
 *      Author: gsosarolon
 */

#include "AssetLoader.h"
#include "SpriteUtil.h"

namespace dxco {

AssetLoader::AssetLoader() {
	this->currentAsset = 0;
}

void AssetLoader::addAsset(std::string assetPath) {
	this->assetsToLoad.push_back(assetPath);
}

void AssetLoader::loadNext() {

	if (this->hasNext()) {
		std::string nextAsset = this->assetsToLoad[this->currentAsset];
		dxco::SpriteUtil::preloadTextureWithFile(nextAsset.c_str());
		this->currentAsset++;
	}
}

bool AssetLoader::hasNext() {
	return this->currentAsset < this->assetsToLoad.size();
}

} /* namespace dxco */
