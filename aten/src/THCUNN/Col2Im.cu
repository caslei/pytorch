#include "THCUNN.h"
#include "common.h"
#include "im2col.h"
#include "THCTensor.hpp"
#include "THCStorage.hpp"

#include "TH/THHalf.h"
#include "THCHalfAutoNumerics.cuh"

#include "generic/Col2Im.cu"
#include "THCGenerateFloatTypes.h"
