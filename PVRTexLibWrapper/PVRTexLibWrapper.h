// PVRTexLibC.h

#pragma once

#include <PVRTGlobal.h>
#include <PVRTextureDefines.h>
#include <PVRTextureFormat.h>

using namespace pvrtexture;

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_DLL
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllexport))
    #else
      #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllimport))
    #else
      #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define DLL_LOCAL
#else
  #define __cdecl
  #if __GNUC__ >= 4
    #define DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define DLL_PUBLIC
    #define DLL_LOCAL
  #endif
#endif

extern "C" {
	DLL_PUBLIC void* __cdecl CreateTexture(void* data, uint32 u32Width, uint32 u32Height, uint32 u32Depth, PixelType ptFormat, bool preMultiplied, EPVRTVariableType eChannelType, EPVRTColourSpace eColourspace);

	DLL_PUBLIC void* __cdecl CreateTextureFromFile(const char* filePath);

	DLL_PUBLIC bool __cdecl SaveTexture(void* pPvrTexture, const char* filePath);

	DLL_PUBLIC void __cdecl DestroyTexture(void* pPvrTexture);

	DLL_PUBLIC bool __cdecl Resize(void* pPvrTexture, uint32 u32NewWidth, uint32 u32NewHeight, uint32 u32NewDepth, EResizeMode eResizeMode);

	DLL_PUBLIC bool __cdecl PremultiplyAlpha(void* pPvrTexture);

	DLL_PUBLIC bool __cdecl GenerateMIPMaps(void* pPvrTexture, EResizeMode eFilterMode, uint32 uiMIPMapsToDo = PVRTEX_ALLMIPLEVELS);

	DLL_PUBLIC bool __cdecl Transcode(void* pPvrTexture, PixelType ptFormat, EPVRTVariableType eChannelType, EPVRTColourSpace eColourspace, ECompressorQuality eQuality = ePVRTCNormal, bool bDoDither = false);

	DLL_PUBLIC uint32 __cdecl GetTextureDataSize(void* pPvrTexture, int32 iMIPLevel = PVRTEX_ALLMIPLEVELS);

	DLL_PUBLIC void __cdecl GetTextureData(void* pPvrTexture, void* data, uint32 dataSize, uint32 uiMIPLevel = 0);
}
