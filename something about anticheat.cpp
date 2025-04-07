// Encrypted string storage
constexpr auto DecryptOffset = [](int encrypted) { 
    return encrypted ^ 0xDEADBEEF; 
};

const DWORD dwEntityList = DecryptOffset(0xABCD1234);
