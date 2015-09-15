// Hash node class template

template <typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value) :
    m_key(key), m_value(value), m_next(NULL) {
    }
 
    K GetKey() const {
        return m_key;
    }
 
    V GetValue() const {
        return m_value;
    }
 
    void SetValue(V value) {
        m_value = value;
    }
 
    HashNode *GetNext() const {
        return m_next;
    }
 
    void SetNext(HashNode *next) {
        m_next = next;
    }
 
private:
    // key-value pair
    K m_key;
    V m_value;
    // next bucket with the same key
    HashNode *m_next;
};
