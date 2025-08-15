#pragma once
#include <type_traits>

namespace SafeConvert {

template<typename T>
bool convert(T rawValue, char typeFlag, float &output);

} // namespace SafeConvert
