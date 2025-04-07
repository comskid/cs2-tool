void Bunnyhop(Memory* mem) {
    DWORD localPlayer = mem->Read<uintptr_t>(clientBase + dwLocalPlayer);
    int flags = mem->Read<int>(localPlayer + m_fFlags);
    
    if (GetAsyncKeyState(VK_SPACE) && (flags & FL_ON_GROUND)) {
        mem->Write<int>(clientBase + dwForceJump, 6);
        std::this_thread::sleep_for(
            std::chrono::milliseconds(10 + rand() % 5)
        );
    }
}
