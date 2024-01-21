#pragma once

#ifndef WINDOWS
    #error amx only support Windows at the moment
#endif

#ifdef AMX_BUILD_DLL
    #define AMX_API __declspec(dllexport)
#else
    #define AMX_API __declspec(dllimport)
#endif