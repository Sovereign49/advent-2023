constexpr int foo(int factor) {
    return 123 * factor;
}

int main () {
    const int const_factor = 10;
    int non_const_factor = 20;

    const int first = foo(const_factor);
    const int second = foo(non_const_factor);
    return 0;
}
