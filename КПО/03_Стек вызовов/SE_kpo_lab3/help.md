cl /c /EHsc /Yc"stdafx.h" kpo_lab3.cpp
cl /c /EHsc /Yu"stdafx.h" detSerialNumber.cpp
cl /c /EHsc detViscosity.cpp
cl /c /EHsc /Yu"stdafx.h" splitData.cpp
cl /c /EHsc /Yu"stdafx.h" showMonth.cpp
cl /c /EHsc /Yu"stdafx.h" showDate.cpp

link kpo_lab3.obj detSerialNumber.obj detViscosity.obj splitData.obj showMonth.obj showDate.obj