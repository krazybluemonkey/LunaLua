#pragma once
#include "Defines.h"
#include "Globals.h"
#pragma comment(lib, "comsuppw.lib")

#define PATCH_FUNC(ptr, func) *(BYTE*)ptr = 0xE8;\
	*((DWORD*)(ptr+1)) = ((DWORD)(((DWORD)func) - ptr - 5))

#define PATCH_JMP(ptr, func) *(BYTE*)ptr = 0xE9;\
	*((DWORD*)(ptr+1)) = ((DWORD)(((DWORD)func) - ptr - 5))

#define PATCH_JMPOLD(ptr, func) *(BYTE*)source = 0xE9;\
	*((DWORD*)(source+1)) = ((DWORD)(((DWORD)dest) - source - 5))

#define COMBOOL(b) (b ? -1 : 0)

typedef int SMBXTrigger(BSTR*, int*);

void ParseArgs(const std::vector<std::string>& args);

void TrySkipPatch();

//Hooks
extern void InitHook();
extern void forceTermination();


//The World Load Code
extern int LoadWorld();
//The World Loop Code
extern DWORD WorldLoop();
//The World Render Code
extern void* renderTest();

extern void prTest(wchar_t** tarString, int* type, float* x, float* y);
extern DWORD bitBltHook(HDC hdcDest, int nXDest, int nYDest, int nWidth, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, unsigned int dwRop);
extern int __stdcall printLunaLuaVersion(HDC hdcDest, int nXDest, int nYDest, int nWidth, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, unsigned int dwRop);
extern MCIERROR __stdcall mciSendStringHookA(__in LPCSTR lpstrCommand, __out_ecount_opt(uReturnLength) LPSTR lpstrReturnString, __in UINT uReturnLength, __in_opt HWND hwndCallback);


//DBG
extern long long dbglongTest;

//Libs
extern HMODULE newLauncherLib = 0;


extern HMODULE newDebugger = 0;

//DBG Procs
void (*runAsyncDebuggerProc)(void);
int (*asyncBitBltProc)(HDC, int, int, int, int, HDC, int, int, unsigned int);
void (*runAsyncLoggerProc)(void);
void (*asyncLogProc)(const char*);

struct resultStruct{
	int result;
	bool disableFrameskip;
	bool NoSound;
};




//scraped for now..... D:
void RuntimePatch();

//Event Hooks
void record_SMBXTrigger(wchar_t* trigger, int unkVal, int type);

int getSMBXTriggerMain(BSTR* trigger, int* unkVal);
int getSMBXTriggerTalk(BSTR* trigger, int* unkVal);
int getSMBXTriggerUnknown(BSTR* trigger, int* unkVal);
int getSMBXTriggerPSwitch(BSTR* trigger, int* unkVal);
int getSMBXTriggerActivateEventLayer(BSTR* trigger, int* unkVal);
int getSMBXTriggerDeathEvent(BSTR* trigger, int* unkVal);
int getSMBXTriggerNoMoreObjEvent(BSTR* trigger, int* unkVal);
int getSMBXTriggerEventTrigger(BSTR* trigger, int* unkVal);