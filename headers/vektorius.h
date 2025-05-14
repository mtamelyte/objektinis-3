
template <typename T>
class Vector{
    private: 
    T* duomenys = nullptr;
    size_t dydis = 0;
    size_t talpa =0;

    void resize();

    public:
    Vector() = default;
    ~Vector() { 
        delete[] duomenys; 
        dydis=0;
        talpa=0;
    }

    Vector(const Vector & v);
    Vector&operator=(const Vector & v);

    Vector(const Vector && v);
    Vector&operator=(const Vector && v);

    void push_back(const T& elementas);
    void pop_back();
    T& operator[](size_t index);
}