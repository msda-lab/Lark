#ifndef SYMB_TABLE_H
#define SYMB_TABLE_H

#include <iostream>
#include <string>
#include "Global.h"

using std::string;
using std::cout;
using std::endl;

class HashFunctions
{
public:
	static unsigned int StringHash(const string &str)
	{
		int seed = 131;
		unsigned int hash = 0;
		for(int i = 0; i < str.size(); ++ i)
		{
			hash = hash * seed + str[i];
		}
		return hash;
	}

};


template <class TypeK, class TypeV>
struct Element
{
	TypeK key;
	TypeV value;
	struct Element<TypeK, TypeV> *next;
    Element(const TypeK &k, TypeV v): key(k), value(v) {next=NULL;} 
    Element() {next=NULL;}
};


// SymbTable declare
template <class K, class V>
class SymbTable
{
	typedef struct Element<K, V> E;
public:
	SymbTable(unsigned int (*hash)(const K &key), bool (*equal)(const K &k, V v));
    SymbTable(const SymbTable<K, V> &other);
	~SymbTable();

	void Insert(const K &key, const V value);
	V Find(const K &key) const;
	void Delete(const K &key);
	void Update(const K &key, const V value);
    bool Contains(const K &key) const;
    bool Empty() const;

	unsigned int (*Hash)(const K &key);
	bool (*Equal)(const K &k, V v);

    int GetSize() const;
	void Print() const;

private:
	int len;
	int size;
	E **table;
};


// SymbTable define
template <class K, class V>
SymbTable<K, V>::SymbTable(unsigned int (*hash)(const K &key), bool (*equal)(const K &k, V v))
{
    len = HASH_LEN;
    table = new E* [len];
    for(int i = 0; i < len; ++ i)
        table[i] = NULL;
    size = 0;
    Hash = hash;
    Equal = equal;
}


template<class K, class V>
SymbTable<K, V>::SymbTable(const SymbTable<K, V> &other)
{
    size = other.size;
    len = other.len;
    table = new E *[len];
    for(int i = 0; i < len; ++ i)
    {
        if(other.table[i] == NULL)
            table[i] = NULL;
        else
        {
            E *head = other.table[i];
            E *front, *rear;
            rear = new E(head->key, head->value);
            table[i] = rear;
            front = rear;
            head = head->next;
            while(head)
            {
                rear = new E(head->key, head->value);
                front->next = rear;
                front = rear;
                head = head->next;
            }
        }
    }
}


template <class K, class V>
SymbTable<K, V>::~SymbTable()
{
    for(int i = 0; i < len; ++ i)
    {
        E *head = table[i];
        E *temp;
        while(head)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    delete[] table;
}


template <class K, class V>
void SymbTable<K, V>::Insert(const K &key, const V value)
{
    if(!Contains(key))
    {
        unsigned int hash = Hash(key)  (len - 1);
        E *ptr = new E(key, value);
        ptr->next = table[hash];
        table[hash] = ptr;
        size ++;
    }
    else
    {
        cout << "Element " << key << " is duplicated." << endl;
    }
    

}


template <class K, class V>
V SymbTable<K, V>::Find(const K &key) const
{
    unsigned int hash = Hash(key)  (len - 1);
    E *ptr = table[hash];

    while(ptr)
    {
        if(Equal(key, ptr->key))
            return ptr->value;
        ptr = ptr->next;
    }
    return V(); // need no args constructor.
}


template <class K, class V>
void SymbTable<K, V>::Delete(const K &key)
{
    unsigned int hash = Hash(key)  (len - 1);
    E *head = table[hash];
    if(head)
    {
        if(Equal(key, head->key))
        {
            table[hash] = head->next;
            delete head;
            size --;
            return;
        }

        E *temp = head;
        head = head->next;
        while(head)
        {
            if(Equal(key, head->key))
            {
                temp->next = head->next;
                delete head;
                size --;
                return;
            }
            temp = head;
            head = head->next;
        }
    }
}


template<class K, class V>
void SymbTable<K, V>::Update(const K &key, const V value)
{
    unsigned int hash = Hash(key)  (len - 1);
    E *head = table[hash];
    while(head)
    {
        if(Equal(key, head->key))
        {
            head->value = value;
            break;
        }
        head = head->next;
    }

}


template<class K, class V>
bool SymbTable<K, V>::Contains(const K &key) const
{
    unsigned int hash = Hash(key)  (len - 1);
    E *head = table[hash];
    while(head)
    {
        if(Equal(key, head->key))
            return true;
        head = head->next;
    }
    return false;
}


template<class K, class V>
bool SymbTable<K, V>::Empty() const
{
    if(size == 0)
        return true;
    else
        return false;
}


template<class K, class V>
int SymbTable<K, V>::GetSize() const
{
    return size;
}


template<class K, class V>
void SymbTable<K, V>::Print() const
{
    for(int i = 0; i < len; ++ i)
    {
        E *head = table[i];
        if(!head)
            continue;
        while(head)
        {
            cout << "(" << head->key << ", " << head->value << ")  ";
            head = head->next;
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
}

#endif
