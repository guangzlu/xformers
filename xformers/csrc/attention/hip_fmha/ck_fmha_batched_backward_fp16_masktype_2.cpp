#include <ck.hpp>
#include <stdexcept>

#include "ck_fmha_batched_backward.h"

template struct batched_backward_masktype_attnbias_dispatched<
    ck::half_t,
    2,
    true,
    true>;

template struct batched_backward_masktype_attnbias_dispatched<
    ck::half_t,
    2,
    true,
    false>;

template struct batched_backward_masktype_attnbias_dispatched<
    ck::half_t,
    2,
    false,
    true>;

template struct batched_backward_masktype_attnbias_dispatched<
    ck::half_t,
    2,
    false,
    false>;