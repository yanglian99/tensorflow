/* Copyright 2016 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef THIRD_PARTY_TENSORFLOW_CORE_KERNELS_XSMM_CONV2D_H_
#define THIRD_PARTY_TENSORFLOW_CORE_KERNELS_XSMM_CONV2D_H_

#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/util/tensor_format.h"

#include "libxsmm/include/libxsmm.h"
#include "libxsmm/include/libxsmm_dnn.h"

namespace tensorflow {

class OpKernelContext;

// XsmmConv2D is a wrapper for libxsmm direct convolutions.

// Returns true if convolution operation specified by function arguments
// can use XsmmConv2D implementation, and false otherwise.
bool CanUseXsmmConv2D(const libxsmm_dnn_conv_desc& desc,
                      TensorFormat data_format);

namespace functor {

template <typename Device, typename T>
struct XsmmConv2D {
  void operator()(OpKernelContext* ctx, const libxsmm_dnn_conv_desc& desc,
                  const T* input, const T* filter, T* output);
};

}  // namespace functor

}  // namespace tensorflow

#endif  // THIRD_PARTY_TENSORFLOW_CORE_KERNELS_XSMM_CONV2D_H_
