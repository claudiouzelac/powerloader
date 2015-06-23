#ifndef _PELDR_H_
#define _PELDR_H_

namespace PeLdr
{
	DWORD64 PeGetImageBase(PVOID ImageBase);
	PIMAGE_NT_HEADERS PeImageNtHeader(PVOID ImageBase);
	PVOID PeImageDirectoryEntryToData(PVOID ImageBase, BOOLEAN ImageLoaded, ULONG Directory, PULONG Size, BOOLEAN RVA = FALSE);
	BOOLEAN PeProcessRelocs(PVOID ImageBase, ULONGLONG Diff);
	PVOID PeGetProcAddress(PVOID ModuleBase, PCHAR lpProcName, BOOLEAN RVA = FALSE);
	BOOLEAN PeProcessImport(PVOID pMZ, BOOLEAN Ntdll64 = FALSE);

#ifndef _WIN64
	PIMAGE_BASE_RELOCATION PeProcessRelocationBlock(ULONG_PTR uVA, ULONG uSizeOfBlock, PUSHORT puNextOffset, ULONGLONG lDelta);
#else
	PIMAGE_BASE_RELOCATION PeProcessRelocationBlock(ULONG_PTR VA, ULONG SizeOfBlock, PUSHORT NextOffset, LONGLONG Diff) ;
#endif

	PVOID PeGetNtdllImageBase();
	BOOLEAN InsertSection(PCHAR SectionName, PVOID Data, DWORD DataSize, PVOID Image, DWORD ImageSize, PVOID *ResultImage, DWORD *ResultImageSize, BOOLEAN VA);
	DWORD_PTR FreeSpaceInHeader(PVOID ImageBase, PIMAGE_NT_HEADERS NtHeaders);
	PIMAGE_SECTION_HEADER GetVirtualyLastSectionHeader(PIMAGE_NT_HEADERS NtHeaders);
	PIMAGE_SECTION_HEADER GetPhysicalyLastSectionHeader(PIMAGE_NT_HEADERS NtHeaders);
	PVOID LoadPEImage(PVOID ImageBaseRaw);
	PIMAGE_SECTION_HEADER PeSearchSection(PVOID ImageBase, PCHAR SectionName);
};

#endif
