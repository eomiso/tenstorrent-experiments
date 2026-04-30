template <typename F>
int checked(const char* label, F&& f) {
    try {
        f();
        fmt::print("PASS: {}\n", label);
        return 0;
    } catch (const std::exception& e) {
        fmt::print(stderr, "FAIL: {}: {}\n", label, e.what());
        return 1;
    }
}
