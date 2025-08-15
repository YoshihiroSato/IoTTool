#include "SafeConvert.h"

namespace SafeConvert {

template<typename T>
bool convert(T rawValue, char typeFlag, float &output) {
    // 範囲チェック
    if (rawValue < 0 || rawValue > 100000) return false;

    if (typeFlag == 'f') {
        if constexpr (std::is_floating_point<T>::value) {
            output = rawValue / 1000.0f;
        } else {
            output = static_cast<float>(rawValue) / 1000.0f;
        }
        return true;
    }
    else if (typeFlag == 'i') {
        if constexpr (std::is_integral<T>::value) {
            output = static_cast<float>(rawValue);
        } else {
            output = rawValue;
        }
        return true;
    }
    else if (typeFlag == 's') {
        // 文字列なら0にしておく（floatには変換できないので）
        output = 0;
        return false;
    }

    return false; // 不正フラグ
}

// インスタンス化しておく（Arduino IDE向け）
template bool convert<int>(int, char, float&);
template bool convert<float>(float, char, float&);

} // namespace SafeConvert
