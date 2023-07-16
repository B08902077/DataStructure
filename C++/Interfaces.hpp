#ifndef ICOLLECTION
#define ICOLLECTION
namespace DataStructure{
    template <typename T>
    class IComparer{
    public:
        virtual int Compare(T x, T y) = 0;
    };

    template <typename T>
    class ICollection{
    public:
        virtual int Count() = 0;
        virtual bool IsReadOnly() { return false; }
        virtual void Add(T item){}
        virtual void Clear(){}
        virtual bool Contains(T item) { return false; }
        virtual bool Remove(T item) { return false; }
        virtual bool RemoveAll(T item) { return false; }
    };

    template <typename TKey, typename TValue>
    class IDictionary{
    public:
        virtual ICollection<TKey> Keys() {}
        virtual ICollection<TValue> Values() {}
        virtual bool ContainsKey(TKey key) { return false; }
        virtual void Add(TKey key, TValue value){}
        virtual bool Remove(TKey key) { return false; }
        virtual bool TryGetValue(TKey key, TValue& value) { return false; }
    };
}

#endif // ICOLLECTION
