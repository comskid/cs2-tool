void RenderESP() {
    for (int i = 0; i < 64; i++) {
        Entity ent = GetEntity(i);
        if (ent.health <= 0) continue;

        Vector3 feetPos, headPos;
        if (WorldToScreen(ent.position, feetPos) && 
            WorldToScreen(ent.headPosition, headPos)) {
            
            // Box ESP
            float height = feetPos.y - headPos.y;
            float width = height / 2.4f;
            DrawBorderBox(headPos.x - width/2, headPos.y, width, height);
            
            // Skeleton
            for (auto& [bone1, bone2] : skeletonBones) {
                Vector3 b1 = GetBonePosition(ent.address, bone1);
                Vector3 b2 = GetBonePosition(ent.address, bone2);
                DrawBoneLine(b1, b2);
            }
        }
    }
}
