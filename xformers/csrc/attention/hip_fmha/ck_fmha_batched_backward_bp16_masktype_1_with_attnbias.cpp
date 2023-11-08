#include <ck.hpp>
#include "ck_fmha_batched_backward.h"

template void run_batched_backward_masktype_attnbias_dispatched<
    ck::bhalf_t,
    1,
    true,
    true>(BatchedBackwardParams& param, hipStream_t stream);

template void run_batched_backward_masktype_attnbias_dispatched<
    ck::bhalf_t,
    1,
    true,
    false>(BatchedBackwardParams& param, hipStream_t stream);
