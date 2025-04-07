// Randomized delay between operations
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(15, 150);
