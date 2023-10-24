#pragma once

#include <ck/ck.hpp>
#include "ck_fmha_op_helper.h"

// list the template parameters that is commonly used
struct GemmOpConstantsCommon {
  static constexpr ck::index_t NumDimG = 2;
  static constexpr ck::index_t NumDimM = 1;
  static constexpr ck::index_t NumDimN = 1;
  static constexpr ck::index_t NumDimK = 1;
  static constexpr ck::index_t NumDimO = 1;

  static constexpr auto TensorSpecA =
      ck::tensor_operation::device::TensorSpecialization::Default;
  static constexpr auto TensorSpecB0 =
      ck::tensor_operation::device::TensorSpecialization::Default;
  static constexpr auto TensorSpecB1 =
      ck::tensor_operation::device::TensorSpecialization::Default;
  static constexpr auto TensorSpecC =
      ck::tensor_operation::device::TensorSpecialization::Default;
};

// list the template parameters that will not be tuned,
// the commented lines gives the tunable template parameters
struct GemmOpConstantsBatchedInfer {
  static constexpr ck::index_t BlockSize = 256;
  static constexpr ck::index_t MPerBlock = 128;
  static constexpr ck::index_t NPerBlock = 128;
  static constexpr ck::index_t KPerBlock = 32;
  // static constexpr ck::index_t Gemm1NPerBlock;
  static constexpr ck::index_t Gemm1KPerBlock = 32;
  static constexpr ck::index_t AK1 = 8;
  static constexpr ck::index_t BK1 = 8;
  static constexpr ck::index_t B1K1 = 2;
  static constexpr ck::index_t MPerXDL = 32;
  static constexpr ck::index_t NPerXDL = 32;
  static constexpr ck::index_t MXdlPerWave = 1;
  static constexpr ck::index_t NXdlPerWave = 4;
  // static constexpr ck::index_t Gemm1NXdlPerWave;
  using ABlockTransferThreadClusterLengths_AK0_M_AK1 = S<4, 64, 1>;
  using ABlockTransferThreadClusterArrangeOrder = S<1, 0, 2>;
  using ABlockTransferSrcAccessOrder = S<1, 0, 2>;
  static constexpr ck::index_t ABlockTransferSrcVectorDim = 2;
  // static constexpr ck::index_t ABlockTransferSrcScalarPerVector;
  static constexpr ck::index_t ABlockTransferDstScalarPerVector_AK1 = 8;
  static constexpr bool ABlockLdsExtraM = true;
  using BBlockTransferThreadClusterLengths_BK0_N_BK1 = S<4, 64, 1>;
  using BBlockTransferThreadClusterArrangeOrder = S<1, 0, 2>;
  using BBlockTransferSrcAccessOrder = S<1, 0, 2>;
  static constexpr ck::index_t BBlockTransferSrcVectorDim = 2;
  // static constexpr ck::index_t BBlockTransferSrcScalarPerVector;
  static constexpr ck::index_t BBlockTransferDstScalarPerVector_BK1 = 8;
  static constexpr bool BBlockLdsExtraN = true;
  // static constexpr ck::index_t Acc0BiasTransferSrcScalarPerVector;
  using B1BlockTransferThreadClusterLengths_BK0_N_BK1 = S<16, 16, 1>;
  using B1BlockTransferThreadClusterArrangeOrder = S<0, 2, 1>;
  using B1BlockTransferSrcAccessOrder = S<0, 2, 1>;
  static constexpr ck::index_t B1BlockTransferSrcVectorDim = 1;
  // static constexpr ck::index_t B1BlockTransferSrcScalarPerVector;
  static constexpr ck::index_t B1BlockTransferDstScalarPerVector_BK1 = 4;
  static constexpr bool B1BlockLdsExtraN = false;
  static constexpr ck::index_t CShuffleMXdlPerWavePerShuffle = 1;
  // static constexpr ck::index_t CShuffleNXdlPerWavePerShuffle;
  using CShuffleBlockTransferClusterLengths_MBlock_MPerBlock_NBlock_NPerBlock =
      S<1, 32, 1, 8>;
  // static constexpr ck::index_t
  // CShuffleBlockTransferScalarPerVector_NPerBlock;
};

// list the template parameters that will not be tuned,
// the commented lines gives the tunable template parameters
struct GemmOpConstantsGroupedInfer {
  static constexpr ck::index_t BlockSize = 256;
  static constexpr ck::index_t MPerBlock = 128;
  static constexpr ck::index_t NPerBlock = 128;
  static constexpr ck::index_t KPerBlock = 32;
  // static constexpr ck::index_t Gemm1NPerBlock;
  static constexpr ck::index_t Gemm1KPerBlock = 32;
  static constexpr ck::index_t AK1 = 8;
  static constexpr ck::index_t BK1 = 8;
  static constexpr ck::index_t B1K1 = 2;
  static constexpr ck::index_t MPerXDL = 32;
  static constexpr ck::index_t NPerXDL = 32;
  static constexpr ck::index_t MXdlPerWave = 1;
  static constexpr ck::index_t NXdlPerWave = 4;
  // static constexpr ck::index_t Gemm1NXdlPerWave;
  using ABlockTransferThreadClusterLengths_AK0_M_AK1 = S<4, 64, 1>;
  using ABlockTransferThreadClusterArrangeOrder = S<1, 0, 2>;
  using ABlockTransferSrcAccessOrder = S<1, 0, 2>;
  static constexpr ck::index_t ABlockTransferSrcVectorDim = 2;
  // static constexpr ck::index_t ABlockTransferSrcScalarPerVector,
  static constexpr ck::index_t ABlockTransferDstScalarPerVector_AK1 = 8;
  static constexpr bool ABlockLdsExtraM = true;
  using BBlockTransferThreadClusterLengths_BK0_N_BK1 = S<4, 64, 1>;
  using BBlockTransferThreadClusterArrangeOrder = S<1, 0, 2>;
  using BBlockTransferSrcAccessOrder = S<1, 0, 2>;
  static constexpr ck::index_t BBlockTransferSrcVectorDim = 2;
  // static constexpr ck::index_t BBlockTransferSrcScalarPerVector;
  static constexpr ck::index_t BBlockTransferDstScalarPerVector_BK1 = 8;
  static constexpr bool BBlockLdsExtraN = true;
  // static constexpr ck::index_t Acc0BiasTransferSrcScalarPerVector;
  using B1BlockTransferThreadClusterLengths_BK0_N_BK1 = S<16, 16, 1>;
  using B1BlockTransferThreadClusterArrangeOrder = S<0, 2, 1>;
  using B1BlockTransferSrcAccessOrder = S<0, 2, 1>;
  static constexpr ck::index_t B1BlockTransferSrcVectorDim = 1;
  // static constexpr ck::index_t B1BlockTransferSrcScalarPerVector;
  static constexpr ck::index_t B1BlockTransferDstScalarPerVector_BK1 = 4;
  static constexpr bool B1BlockLdsExtraN = false;
  static constexpr ck::index_t CShuffleMXdlPerWavePerShuffle = 1;
  // static constexpr ck::index_t CShuffleNXdlPerWavePerShuffle;
  using CShuffleBlockTransferClusterLengths_MBlock_MPerBlock_NBlock_NPerBlock =
      S<1, 32, 1, 8>;
  // static constexpr ck::index_t
  // CShuffleBlockTransferScalarPerVector_NPerBlock;
};

struct GemmOpConstantsForward {};

struct GemmOpConstantsBackward {};