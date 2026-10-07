#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

DWORD getParentProcessID(DWORD processID)
{
    HANDLE snapshot;
    PROCESSENTRY32 pe;

    pe.dwSize = sizeof(PROCESSENTRY32);

    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (snapshot == INVALID_HANDLE_VALUE)
        return 0;

    if (Process32First(snapshot, &pe))
    {
        do
        {
            if (pe.th32ProcessID == processID)
            {
                DWORD parentID = pe.th32ParentProcessID;
                CloseHandle(snapshot);
                return parentID;
            }
        } while (Process32Next(snapshot, &pe));
    }

    CloseHandle(snapshot);
    return 0;
}

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD ppid = getParentProcessID(pid);

    printf("Current Process ID : %lu\n", (unsigned long)pid);
    printf("Parent Process ID  : %lu\n", (unsigned long)ppid);

    return 0;
}
