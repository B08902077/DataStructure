// #ifndef ICOLLECTION
// #define ICOLLECTION
// namespace DataStructure{
template <typename T>
class ICollection{
public:
    virtual int Count() = 0;
    virtual bool IsReadOnly() { return false; }
    virtual void Add(T item){}
    virtual void Clear(){}
    virtual bool Contains(T item) { return false; }
    virtual bool Remove(T item) { return false; }
};
// }

// #endif // ICOLLECTION
