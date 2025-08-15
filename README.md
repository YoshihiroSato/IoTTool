# SafeConvert

UART/UDP/ESP-NOWで受信したデータを型チェックして安全にfloatに変換するライブラリです。

## 使い方

```cpp
#include <SafeConvert.h>

float result;
if(SafeConvert::convert(12345, 'f', result)) {
    Serial.println(result);
}
typeFlag は 'f'（float用）、'i'（整数用）、's'（文字列用）
