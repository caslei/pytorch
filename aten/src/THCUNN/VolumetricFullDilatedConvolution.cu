#include "THCUNN.h"
#include "THCTensor.hpp"
#include "common.h"
#include "vol2col.h"
#include "TH/THHalf.h"
#include "THCHalfAutoNumerics.cuh"

#include "generic/VolumetricFullDilatedConvolution.cu"
#include "THCGenerateFloatTypes.h"
