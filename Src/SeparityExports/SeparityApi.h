#pragma once
#ifndef _SEPARITY_API_
#ifdef _SEPARITY_EXPORT_
#define _SEPARITY_API_ __declspec(dllexport)
#else
#define _SEPARITY_API_ __declspec(dllimport)
#endif
#endif