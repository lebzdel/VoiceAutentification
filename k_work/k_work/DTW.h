#pragma once

#ifndef DTW_H_
#define DTW_H_

#define DEBUG_ENABLED false
#define DEBUG(...)  \
		do { if (DEBUG_ENABLED) { fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n"); } } while (0)

#include <stdint.h>

using namespace std;

class DTW {
public:

	/**
	 * Calculate distance between two sequences of numbers
	 */
	static double calcDistance(double* seq1, uint32_t seq1size, double* seq2, uint32_t seq2size);

	/**
	 * Calculate distance between two sequences of vectors
	 */
	static double calcDistanceVector(double* seq1, uint32_t seq1size,
		double* seq2, uint32_t seq2size, uint8_t vectorSize);

private:

	static double findDistance(uint32_t seq1size, uint32_t seq2size, double** diffM);
};


#endif