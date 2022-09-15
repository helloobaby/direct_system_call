#include <Windows.h>
#include <cstdio>
#include <string>
#include "winternl.h"
#pragma comment(lib, "ntdll")

NTSTATUS SysNtCreateFile(
	PHANDLE FileHandle,
	ACCESS_MASK DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PIO_STATUS_BLOCK IoStatusBlock,
	PLARGE_INTEGER AllocationSize,
	ULONG FileAttributes,
	ULONG ShareAccess,
	ULONG CreateDisposition,
	ULONG CreateOptions,
	PVOID EaBuffer,
	ULONG EaLength);

using namespace std;

int main()
{
	FARPROC addr = GetProcAddress(LoadLibraryA("ntdll"), "NtCreateFile");
	WCHAR temp[MAX_PATH]{};
	GetTempPathW(MAX_PATH, temp);

	OBJECT_ATTRIBUTES oa;
	HANDLE fileHandle = NULL;
	NTSTATUS status = NULL;
	UNICODE_STRING fileName;
	IO_STATUS_BLOCK osb;

	wstring wstemp(temp);
	wstemp.append(L"testsbb.txt");
	wstemp.insert(0, L"\\??\\");

	RtlInitUnicodeString(&fileName, wstemp.c_str());
	
	ZeroMemory(&osb, sizeof(IO_STATUS_BLOCK));
	InitializeObjectAttributes(&oa, &fileName, OBJ_CASE_INSENSITIVE, NULL, NULL);

	NTSTATUS Status = SysNtCreateFile(
		&fileHandle,
		FILE_GENERIC_WRITE,
		&oa,
		&osb,
		0,
		FILE_ATTRIBUTE_NORMAL,
		FILE_SHARE_WRITE,
		FILE_OVERWRITE_IF,
		FILE_SYNCHRONOUS_IO_NONALERT,
		NULL,
		0);

	printf("%x\n", Status);

	return 0;
}