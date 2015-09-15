#include "HashNode.h"
#include "KeyHash.h"

// Hash map class template
template<typename K, typename V, typename F = KeyHash<K> >
class HashMap
{
public:

    typedef HashNode<K, V> iterator;
    HashMap()
    {
        // construct zero initialized hash table of size
        m_table = new HashNode<K, V> *[TABLE_SIZE]();
    }

    ~HashMap()
    {
        // destroy all buckets one by one
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode<K, V> *entry = m_table[i];
            while (entry != NULL)
            {
                HashNode<K, V> *prev = entry;
                entry = entry->GetNext();
                delete prev;
            }
            m_table[i] = NULL;
        }
        // destroy the hash table
        delete[] m_table;
    }

    bool Get(const K &key, V &value)
    {
        unsigned long hashValue = m_hashFunc(key);
        HashNode<K, V> *entry = m_table[hashValue];

        while (entry != NULL)
        {
            if (entry->GetKey() == key)
            {
                value = entry->GetValue();
                return true;
            }
            entry = entry->GetNext();
        }
        return false;
    }

    V& operator[](const K &key)
    {
        unsigned long hashValue = m_hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = m_table[hashValue];

        while (entry != NULL && entry->GetKey() != key)
        {
            prev = entry;
            entry = entry->GetNext();
        }

        if (entry == NULL)
        {
            entry = new HashNode<K, V>();
            entry->SetKey(key);

            if (prev == NULL)
            {
                // insert as first bucket
                m_table[hashValue] = entry;
            }
            else
            {
                prev->SetNext(entry);
            }
        }

        return entry->GetValue();
    }

    void Put(const K &key, const V &value)
    {
        unsigned long hashValue = m_hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = m_table[hashValue];

        while (entry != NULL && entry->GetKey() != key)
        {
            prev = entry;
            entry = entry->GetNext();
        }

        if (entry == NULL)
        {
            entry = new HashNode<K, V>(key, value);
            if (prev == NULL)
            {
                // insert as first bucket
                m_table[hashValue] = entry;
            }
            else
            {
                prev->SetNext(entry);
            }
        }
        else
        {
            // just update the value
            entry->SetValue(value);
        }
    }

    void Remove(const K &key)
    {
        unsigned long hashValue = m_hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = m_table[hashValue];

        while (entry != NULL && entry->GetKey() != key)
        {
            prev = entry;
            entry = entry->GetNext();
        }

        if (entry == NULL)
        {
            // key not found
            return;
        }
        else
        {
            if (prev == NULL)
            {
                // remove first bucket of the list
                m_table[hashValue] = entry->GetNext();
            }
            else
            {
                prev->SetNext(entry->GetNext());
            }
            delete entry;
        }
    }

private:
    // hash table
    HashNode<K, V> **m_table;
    F m_hashFunc;
};
