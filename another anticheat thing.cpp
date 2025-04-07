__declspec(noinline) void SafeRead(HANDLE hProcess, LPCVOID addr, LPVOID buf, SIZE_T size) {
    __try {
        ReadProcessMemory(hProcess, addr, buf, size, NULL);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        memset(buf, 0, size);
    }
}
