/*
 * AssetLoader.cpp
 *
 *  Created on: Oct 25, 2014
 *      Author: gsosarolon
 */

#include "AssetLoader.h"
#include "SpriteUtil.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

namespace dxco {

AssetLoader::AssetLoader() {
	this->currentAsset = 0;
}

void AssetLoader::addAsset(std::string assetPath, bool isSound) {

	if (isSound) {
		this->soundAssetsToLoad.push_back(assetPath);
	} else {
		this->assetsToLoad.push_back(assetPath);
	}
}

void AssetLoader::loadNext() {

	if (this->hasNext()) {

		if (this->currentAsset < this->assetsToLoad.size()) {
			std::string nextAsset = this->assetsToLoad[this->currentAsset];
			CCLOG("Loading resource %s", nextAsset.c_str());
			dxco::SpriteUtil::preloadTextureWithFile(nextAsset.c_str());
			this->currentAsset++;
		} else {
			std::string nextAsset = this->soundAssetsToLoad[this->currentAsset - this->assetsToLoad.size()];
			CCLOG("Loading resource %s", nextAsset.c_str());
			CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(nextAsset.c_str());
			this->currentAsset++;
		}
	}
}

bool AssetLoader::hasNext() {
	return this->currentAsset < this->assetsToLoad.size() + this->soundAssetsToLoad.size();
}

} /* namespace dxco */
