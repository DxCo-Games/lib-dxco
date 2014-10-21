#include "VoiceManager.h"
#include "SimpleAudioEngine.h"
#include <cstdlib>

namespace dxco {

VoiceManager::VoiceManager(float voiceInterval) {
	this->voiceInterval = voiceInterval;
	this->dt = 0;
}

void VoiceManager::update(float dt) {
	this->dt += dt;
}

void VoiceManager::play(std::string sound, float probability) {
	if (random() % 1000 < probability * 1000) {
		this->doPlay(sound);
	}
}

//play either sound
void VoiceManager::play(std::string sound1, std::string sound2, float probability) {
	if (random() % 1000 < probability * 1000) {
		if (random() % 2) {
			this->doPlay(sound1);
		} else {
			this->doPlay(sound2);
		}
	}
}

void VoiceManager::doPlay(std::string sound) {
	//check another voice isn't
	if(this->dt > this->voiceInterval) {
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(sound.c_str());
		this->dt = 0;
	}
}

} /* namespace dxco */
