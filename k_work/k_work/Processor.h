#ifndef Processor_H_
#define Processor_H_

#include <vector>
#include <map>
#include <utility>
#include "Audio.h"
#include "Frame.h"
#include <memory>
#include "Word.h"

	class Processor {
	public:

		Processor(WavData* wavData);
		~Processor();

		void init();
		void initMfcc(Word& word);

		const WavData* getWavData() const { return this->wavData; }
		const std::vector<Frame*>* getFrames() const { return this->frames; }
		const std::vector<Word*>* getWords() const { return this->words; }

		double getWordsThreshold() const { return this->wordsThreshold; }
		double getRmsMax() const { return this->rmsMax; }

		Word* getAsWholeWord();
		void divideIntoWords();

		bool isPartOfAWord(const Frame& frame) const;
		uint32_t getFramesCount(const Word& word) const;

		void saveWordAsAudio(const std::string& file, const Word& word) const;

	private:
		WavData* wavData;

		std::vector<Frame*>* frames;
		std::map<uint32_t, std::pair<uint32_t, uint32_t> >* frameToRaw;
		uint32_t samplesPerFrame;

		std::vector<Word*>* words;
		std::map<uint32_t, std::pair<uint32_t, uint32_t> >* wordToFrames;

		double rmsMax;
		double wordsThreshold;

		void divideIntoFrames();

		uint32_t processSilence(vector<Frame*>::const_iterator frame,
			Word*& lastWord, long& firstFrameInCurrentWordNumber,
			uint32_t& wordId);
		void cleanUpWords();
		void useAllSamplesAsOneWord();
		bool findSilenceThreshold();
	};

	//typedef std::unique_ptr<Processor> ProcessorPtr;
	typedef Processor* ProcessorPtr;


#endif /* Processor_H_ */