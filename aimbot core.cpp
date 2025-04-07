void AimbotThread(Memory* mem) {
    while (true) {
        if (config.aimbotEnabled) {
            Vector3 localEyePos = GetLocalEyePosition();
            Vector3 bestAngle = {0,0,0};
            
            for (int i = 0; i < 64; i++) {
                uintptr_t entity = mem->GetEntity(i);
                if (IsValidEnemy(entity)) {
                    Vector3 targetBone = GetBonePosition(entity, 8); // Head bone
                    Vector3 angle = CalculateAngle(localEyePos, targetBone);
                    
                    if (GetFOV(angle) < config.aimbotFOV) {
                        bestAngle = angle;
                        break;
                    }
                }
            }
            
            if (!bestAngle.IsZero()) {
                SmoothAim(bestAngle, config.smoothFactor);
            }
        }
        Sleep(1);
    }
}
