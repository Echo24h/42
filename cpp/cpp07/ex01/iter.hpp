template<typename T>
void iter(T * ptr, int size, void (*f)(T)) {
    if (!ptr || !f) {
        return ;
    }
    
    for (int i = 0; i < size; i++) {
        f(ptr[i]);
    }
}
