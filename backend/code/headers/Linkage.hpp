
#pragma once

#ifdef GYMKHANA

#define GYMKHANA_API __declspec(dllexport)

#else

#define GYMKHANA_API __declspec(dllimport)

#endif
