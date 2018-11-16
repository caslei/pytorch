#include "torch/csrc/python_headers.h"

#include "torch/csrc/utils/tensor_layouts.h"

#include "torch/csrc/Layout.h"
#include "torch/csrc/DynamicTypes.h"
#include "torch/csrc/Exceptions.h"

#include <ATen/ScalarType.h>
#include <ATen/Layout.h>

namespace torch { namespace utils {

void initializeLayouts() {
  auto torch_module = THPObjectPtr(PyImport_ImportModule("torch"));
  if (!torch_module) python_error();

  PyObject *strided_layout = THPLayout_New(at::Layout::Strided, "torch.strided");
  Py_INCREF(strided_layout);
  if (PyModule_AddObject(torch_module, "strided", strided_layout) != 0) {
    throw python_error();
  }
  // for now, let's look these up by Backend; we could create our own enum in the future.
  registerLayoutObject((THPLayout*)strided_layout, at::Backend::CPU);
  registerLayoutObject((THPLayout*)strided_layout, at::Backend::CUDA);

  PyObject *sparse_coo_layout = THPLayout_New(at::Layout::Sparse, "torch.sparse_coo");
  Py_INCREF(sparse_coo_layout);
  if (PyModule_AddObject(torch_module, "sparse_coo", sparse_coo_layout) != 0) {
    throw python_error();
  }
  registerLayoutObject((THPLayout*)sparse_coo_layout, at::Backend::SparseCPU);
  registerLayoutObject((THPLayout*)sparse_coo_layout, at::Backend::SparseCUDA);
}

}} // namespace torch::utils
