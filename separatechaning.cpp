#include <iostream>
#include <list>
#include <vector>

using namespace std;

class SeparateChainingHashTable {
private:
    vector<list<int>> table;  // Vector, mis hoiab linked-liste
    int tableSize;  // Tabeli suurus

public:
    // Konstruktor, mis määrab tabeli suuruse ja loob vektori
    SeparateChainingHashTable(int size) : tableSize(size) {
        table.resize(size);
    }

    // Hash funktsioon, mis arvutab indeksi võtme põhjal väljs
    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int index = hashFunction(key);  // Arvutab indeksi võtme abil
        table[index].push_back(key);    // Lisab võtme linked-listi
    }

    // Otsib elementi tabelist
    bool search(int key) {
        int index = hashFunction(key);
        // Kontrollib, kas võti on linked-listis
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    // Eemaldab elemendi tabelist
    void remove(int key) {
        int index = hashFunction(key);  // Arvutab indeksi võtme abil
        table[index].remove(key);        // Eemaldab võtme linked-listist
    }
};

int main() {
    SeparateChainingHashTable hashTable(10);

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);

    // Otsib võtit ja väljastab vastavalt tulemuse
    cout << "Otsi 15: " << (hashTable.search(15) ? "Leitud" : "Ei leitud") << endl;
    cout << "Otsi 20: " << (hashTable.search(20) ? "Leitud" : "Ei leitud") << endl;

    hashTable.remove(15);  // Eemaldab võtme

    // Otsib võtit pärast eemaldamist ja väljastab vastavalt tulemuse
    cout << "Otsi 15 parast eemaldamist: " << (hashTable.search(15) ? "Leitud" : "Ei leitud") << endl;

    return 0;
}
