
template <typename T>
class Vector{
    private: 
    T* duomenys = nullptr;
    size_t dydis = 0;
    size_t talpa =0;

    public:
    Vector() = default;
    ~Vector() { 
        delete duomenys; 
        dydis=0;
        talpa=0;
    }

    Vector(const Vector & v);
    Vector&operator=(const Vector & v);

    Vector(const Vector && v);
    Vector&operator=(const Vector && v);
}