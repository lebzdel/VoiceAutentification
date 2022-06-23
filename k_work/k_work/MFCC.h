#pragma once
#include <fstream>
#include <stdio.h>
#include "Audio.h"
#include <Windows.h>


class MFCC {
public:
    static double* transform(const double* source, uint32_t start, uint32_t finish,
        uint8_t mfccSize, uint32_t frequency, uint32_t freqMin, uint32_t freqMax);

    static double* filter(const double* source, uint32_t start, uint32_t finish);

    static double* fourierTransform(const double* source, uint32_t start, uint32_t length, bool useWindow);

    static double** getMelFilters(uint8_t mfccSize, uint32_t filterLength, uint32_t frequency,
        uint32_t freqMin, uint32_t freqMax);


    static double* calcPower(const double* fourierRaw, uint32_t fourierLength,
        double** melFilters, uint8_t mfccSize);


    static double* dctTransform(const double* data, uint32_t length);


    static double convertToMel(double f) { return 1125. * log(1. + f / 700.); }
    static double convertFromMel(double m) { return 700. * (exp(m / 1125.) - 1); }
};
