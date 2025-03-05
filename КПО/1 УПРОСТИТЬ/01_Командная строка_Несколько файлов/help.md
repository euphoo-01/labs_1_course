```bash
cl /c /EHsc /Yc"stdafx.h" kpo_lab1.cpp
cl /c /EHsc /Yu"stdafx.h" detSerialNumber.cpp
cl /c /EHsc detViscosity.cpp
cl /c /EHsc /Yu"stdafx.h" splitData.cpp

link kpo_lab1.obj detSerialNumber.obj detViscosity.obj splitData.obj
```
```bash
cl /EHsc /Fa /FAcs kpo_lab1.cpp
```