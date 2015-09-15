// Hash node class template

template<typename K, typename V>
class HashNode
{
public:
    HashNode(const K &key, const V &value) :
        first(key),
        second(value),
        m_next(NULL)
    {
    }

    HashNode()
    {
    }

    K GetKey() const
    {
        return first;
    }

    V& GetValue()
    {
        return second;
    }

    void SetValue(V value)
    {
        second = value;
    }

    void SetKey(K key)
    {
        first = key;
    }

    HashNode *GetNext() const
    {
        return m_next;
    }

    void SetNext(HashNode *next)
    {
        m_next = next;
    }

private:
    // key-value pair
    K first;
    V second;
    // next bucket with the same key
    HashNode *m_next;
};
