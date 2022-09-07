template<typename T>
void iter(T const * ptr, int size, void (*f)(T const)) {
    if (!ptr || !(*f)) {
        return ;
    }
    
    for (int i = 0; i < size; i++) {
        (*f)(ptr[i]);
    }
}
