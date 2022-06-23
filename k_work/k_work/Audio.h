#pragma once
#include <cstdint>
#include <fstream>

// Объявление типов и констант
typedef int16_t raw_t;

const uint32_t FRAME_LENGTH = 10;

const double FRAME_OVERLAP = 0.5;

const unsigned short WORD_MIN_SIZE = (200 / FRAME_LENGTH) / (1 - FRAME_OVERLAP);

const unsigned short WORDS_MIN_DISTANCE = WORD_MIN_SIZE * 0.50;

const unsigned short MFCC_SIZE = 12;

const short MFCC_FREQ_MIN = 300;
const short MFCC_FREQ_MAX = 4000;

const short ENTROPY_BINS = 75;
const double ENTROPY_THRESHOLD = 0.1;

using namespace std;

// Голова WAV-файла
typedef struct  WAV_HEADER
{
	char               RIFF[4];        // RIFF Header
	unsigned long     ChunkSize;      // RIFF Chunk Size
	char               WAVE[4];        // WAVE Header

	char               fmt[4];         // FMT header
	unsigned long     Subchunk1Size;  // Size of the fmt chunk
	unsigned short    AudioFormat;    // Audio format 1=PCM (Other formats are unsupported)
	unsigned short    NumOfChan;      // Number of channels 1=Mono, 2=Stereo
	unsigned long     SamplesPerSec;  // Sampling Frequency in Hz
	unsigned long     bytesPerSec;    // bytes per second
	unsigned short    blockAlign;     // 2=16-bit mono, 4=16-bit stereo
	unsigned short    bitsPerSample;  // Number of bits per sample

	// The data below depends on audioFormat, but we work only with PCM cases
	char               data[4];        // DATA header
	unsigned long     Subchunk2Size;  // Sampled data length
};

// Даные WAV-файла
class WavData {
public:
	WavData(WAV_HEADER header) {
		this->header = header;
		this->rawData = NULL;
		this->normalizedData = NULL;

		this->maxVal = 0;
		this->minVal = 0;
		this->numberOfSamples = 0;
	}

	~WavData() {
		if (NULL != this->rawData) {
			delete[] this->rawData;
		}
		if (NULL != this->normalizedData) {
			delete[] this->normalizedData;
		}
	}

	static WavData* readFromFile(const string& file);

	uint32_t getNumberOfSamples() const { return numberOfSamples; }
	void setNumberOfSamples(uint32_t numberOfSamples) { this->numberOfSamples = numberOfSamples; }

	raw_t getMaxVal() const { return maxVal; }
	void setMaxVal(raw_t maxVal) { this->maxVal = maxVal; }

	raw_t getMinVal() const { return minVal; }
	void setMinVal(raw_t minVal) { this->minVal = minVal; }

	const WAV_HEADER& getHeader() const { return header; }
	const raw_t* getRawData() const { return rawData; }
	const double* getNormalizedData() const { return normalizedData; }

	static bool checkHeader(const WAV_HEADER& wavHeader);
	static void readData(fstream& fs, const WAV_HEADER& wavHeader, WavData& wavFile);

private:
	WAV_HEADER		header;
	raw_t* rawData;
	double* normalizedData;

	raw_t			maxVal;
	raw_t			minVal;
	uint32_t		numberOfSamples;

};