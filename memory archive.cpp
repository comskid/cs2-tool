// Memory manager class
class Memory {
private:
    HANDLE hProcess;
    uintptr_t clientBase;
    uintptr_t engineBase;
    
public:
    template<typename T>
    T Read(uintptr_t address) {
        T buffer;
        ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, sizeof(T), NULL);
        return buffer;
    }

    uintptr_t GetEntity(int index) {
        return Read<uintptr_t>(clientBase + dwEntityList + (index * 0x10));
    }
};
