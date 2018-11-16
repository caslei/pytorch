#include "ATen/ATen.h"

#include <ATen/WrapDimUtils.h>
#include <c10/util/Exception.h>

#include <algorithm>
#include <vector>

namespace at {
namespace native {

static inline void flip_check_errors(int64_t total_dims, int64_t flip_dims_size, IntList dims) {
  // check if number of axis in dim is valid
  AT_CHECK(flip_dims_size > 0 && flip_dims_size <= total_dims,
    "flip dims size out of range, got flip dims size=", flip_dims_size);

  auto flip_dims_v = dims.vec();

  // check if dims axis within range
  auto min_max_d = std::minmax_element(flip_dims_v.begin(), flip_dims_v.end());

  AT_CHECK(*min_max_d.first < total_dims && *min_max_d.first >= -total_dims,
    "The min flip dims out of range, got min flip dims=", *min_max_d.first);

  AT_CHECK(*min_max_d.second < total_dims && *min_max_d.second >= -total_dims,
    "The max flip dims out of range, got max flip dims=", *min_max_d.second);

  // check duplicates in dims
  wrap_all_dims(flip_dims_v, total_dims);
  flip_dims_v.erase(std::unique(flip_dims_v.begin(), flip_dims_v.end()), flip_dims_v.end());
  AT_CHECK((int64_t)flip_dims_v.size() == flip_dims_size,
    "dims has duplicates, original flip dims size=", flip_dims_size,
    ", but unique flip dims size=", flip_dims_v.size());
}

}}  // namespace at::native
