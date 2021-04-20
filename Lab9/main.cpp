#include <iostream>
#include <cstring>
#include <stdio.h>
#define MAX 1001
using namespace std;

template <class K, class V>
struct Item
{
    K key;
    V value;
    int index;
};

template <class K, class V>

class Map
{
    Item<K, V> items[MAX];
    /*K key[MAX];
    V value[MAX];
    int index[MAX];*/
    int count = 0;

public:
    
    V& operator[] (K k)
    {
        for (int i = 0; i < count; i++)
            if (items[i].key == k)
                return items[i].value;
        items[count].key = k;
        items[count].index = count;
        return items[count++].value;
    }
    void Set(K k, V v)
    {
        for (int i = 0; i < count; i++)
            if (items[i].key == k)
            {
                items[i].value = v;
                return;
            }
        items[count].key = k;
        items[count].index = count;
        items[count++].value = v;
    }
    bool Get(const K& k, V& val)
    {
        for (int i = 0; i < count; i++)
            if (items[i].key == k)
            {
                val = items[i].value;
                return 1;
            }
        return 0;
    }
    int Count()
    {
        return count;
    }
    void Clear()
    {
        count = 0;
    }
    bool Delete(const K& k)
    {
        for (int i = 0; i < count; i++)
            if (items[i].key == k)
            {
                for (int j = i; j < count; j++)
                {
                    items[j].key = items[j + 1].key;
                    items[j].value = items[j + 1].value;
                }

                count--;
                return 1;
            }
        return 1;
    }

    bool Includes(const Map<K, V>& map)
    {
        bool found;
        for (int i = 0; i < this->count; i++)
        {
            found = 0;
            for (int j = 0; j < map.Count(); j++)
                if (items[i].key[i] == map.items[i].key)
                {
                    found = 1;
                    break;
                }
            if (found == 0)
                return 0;
        }

        return 1;
    }
    Item<K, V>* begin()
    {
        //return &index[0];
        return &items[0];
    }
    Item<K, V>* end()
    {
        //return &index[count];
        return &items[count];
    }

};

int main()
{

    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;

}