#ifndef VOICEMANAGER_H_
#define VOICEMANAGER_H_

#include <string>
#include <vector>

namespace dxco {

class VoiceManager {
public:
	VoiceManager(float voiceInterval = 3);

	void update(float dt);
	void play(std::string sound, float probability = 1);

	//play either sound
	void play(std::string sound1, std::string sound2, float probability = 1);

	//will play after voiceInterval with no sound and with probability .5
	void loadRandom(std::string sound);

private:
	void doPlay(std::string sound);
	float dt;
	float voiceInterval;
	float randomDt;
	std::vector<std::string> randomVoices;

};

} /* namespace dxco */

#endif /* VOICEMANAGER_H_ */
