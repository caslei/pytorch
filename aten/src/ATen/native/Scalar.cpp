#include "ATen/ATen.h"
#include "ATen/NativeFunctions.h"

namespace at {
namespace native {

Scalar _local_scalar(const Tensor& self) {
  int64_t numel = self.numel();
  AT_CHECK(numel == 1, "a Tensor with ", numel, " elements cannot be converted to Scalar");
  if (self.is_sparse()) {
    if (self._nnz() == 0) return Scalar(0);
    if (self.is_coalesced()) return at::_local_scalar_dense(self._values());
    return at::_local_scalar_dense(self._values().sum());
  } else {
    return _local_scalar_dense(self);
  }
}

Scalar _local_scalar_dense_cpu(const Tensor& self) {
  Scalar r;
  AT_DISPATCH_ALL_TYPES_AND_HALF_AND_COMPLEX(
      self.type(), "_local_scalar_dense_cpu", [&] {
        scalar_t value = *self.data<scalar_t>();
        r = Scalar(value);
      });
  return r;
}

}} // at::native
