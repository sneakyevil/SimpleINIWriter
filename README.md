# SimpleINIWriter
SimpleINIWriter is one C++ File header which uses operators to build ini.

## Usage
```cpp
CINIWriter m_INI;

m_INI["Section0"]["Integer"] = 1234;
m_INI["Section0"]["Float"] = 1.234f;
m_INI["Section0"]["String"] = "String of Section0";

m_INI["Section1"]["Integer"] = 5678;
m_INI["Section1"]["Float"] = 5.678f;
m_INI["Section1"]["String"] = "String of Section1";
```

## Output from usage
```ini
[Section0]
Float=1.234000
Integer=1234
String="String of Section0"

[Section1]
Float=5.678000
Integer=5678
String="String of Section1"
```
