#include "random_utils.h"
#include <random>

namespace 
{
  thread_local static std::default_random_engine Engine {};
}

namespace ts 
{
  void randomize() 
  {
    thread_local static std::random_device device {};
    Engine.seed(device());
  }

  int random() 
  {
    return static_cast<int>(Engine());
  }

  int pick(const int from, const int thru)
  {
    thread_local static std::uniform_int_distribution <> dist{};
    using param_type_t = decltype(dist)::param_type;
    return dist(Engine, param_type_t{from, thru});
  }

  double pick(const double from, const double thru)
  {
    thread_local static std::uniform_real_distribution <> dist{};
    using param_type_t = decltype(dist)::param_type;
    return dist(Engine, param_type_t{from, thru});
  }
}
