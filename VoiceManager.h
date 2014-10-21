#ifndef VOICEMANAGER_H_
#define VOICEMANAGER_H_

#include <string>

namespace dxco {

class VoiceManager {
public:
	VoiceManager(float voiceInterval = 3);

	void update(float dt);
	void play(std::string sound, float probability = 1);

	//play either sound
	void play(std::string sound1, std::string sound2, float probability = 1);

private:
	void doPlay(std::string sound);
	float dt;
	float voiceInterval;


};

} /* namespace dxco */

#endif /* VOICEMANAGER_H_ */
