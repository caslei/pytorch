#include "THCUNN.h"
#include "TH/THHalf.h"
#include "THCHalfAutoNumerics.cuh"
#include "THCTensor.hpp"

#include <cusparse.h>

static cusparseHandle_t cusparse_handle = 0;

static void init_cusparse() {
  if (cusparse_handle == 0) {
    cusparseStatus_t status = cusparseCreate(&cusparse_handle);
    if (status != CUSPARSE_STATUS_SUCCESS) {
      THError("CUSPARSE Library initialization failed");
    }
  }
}

void THNN_CudaHalfSparseLinear_updateOutput(
          THCState *state,
          THCudaHalfTensor *input,
          THCudaHalfTensor *output,
          THCudaHalfTensor *weight,
          THCudaHalfTensor *bias) {
  THError("THCudaHalfTensor not supported with SparseLinear");
}

void THNN_CudaHalfSparseLinear_accGradParameters(
          THCState *state,
          THCudaHalfTensor *input,
          THCudaHalfTensor *gradOutput,
          THCudaHalfTensor *gradWeight,
          THCudaHalfTensor *gradBias,
          THCudaHalfTensor *weight,
          THCudaHalfTensor *bias,
          float weightDecay,
          float scale) {
  THError("THCudaHalfTensor not supported with SparseLinear");
}

void THNN_CudaHalfSparseLinear_legacyUpdateOutput(
          THCState *state,
          THCudaHalfTensor *input,
          THCudaHalfTensor *output,
          THCudaHalfTensor *weight,
          THCudaHalfTensor *bias) {
  THError("THCudaHalfTensor not supported with SparseLinear");
}

void THNN_CudaHalfSparseLinear_legacyAccGradParameters(
          THCState *state,
          THCudaHalfTensor *input,
          THCudaHalfTensor *gradOutput,
          THCudaHalfTensor *gradWeight,
          THCudaHalfTensor *gradBias,
          THCudaHalfTensor *weight,
          THCudaHalfTensor *bias,
          float weightDecay,
          float scale) {
  THError("THCudaHalfTensor not supported with SparseLinear");
}

void THNN_CudaHalfSparseLinear_zeroGradParameters(
          THCState *state,
          THCudaHalfTensor *gradWeight,
          THCudaHalfTensor *gradBias,
          THCudaHalfTensor *lastInput) {
  THError("THCudaHalfTensor not supported with SparseLinear");
}

void THNN_CudaHalfSparseLinear_updateParameters(
          THCState *state,
          THCudaHalfTensor *weight,
          THCudaHalfTensor *bias,
          THCudaHalfTensor *gradWeight,
          THCudaHalfTensor *gradBias,
          THCudaHalfTensor *lastInput,
          float learningRate) {
  THError("THCudaHalfTensor not supported with SparseLinear");
}

#include "generic/SparseLinear.cu"
#include "THCGenerateFloatType.h"
#include "generic/SparseLinear.cu"
#include "THCGenerateDoubleType.h"
