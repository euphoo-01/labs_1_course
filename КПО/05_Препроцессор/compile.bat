cl /c /EHsc /Yc"stdafx.h" stdafx.cpp
cl /c /EHsc /Yu"stdafx.h" Dictionary.cpp
cl /c /EHsc /Yu"stdafx.h" main.cpp
link stdafx.obj Dictionary.obj main.obj /out:dictionary.exe