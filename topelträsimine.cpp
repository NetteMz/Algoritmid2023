#include <iostream>
#include <vector>

class DoubleHashingHashTable {
private:
    std::vector<int> table;
    int tableSize;
    int prime; // Suurim esmane arv, mis on väiksem kui tabeli suurus

public:
    DoubleHashingHashTable(int size) : tableSize(size) {
        table.resize(size, -1);
        prime = getLargestPrime(size);
    }
    // Räsifunktsioon 1
    int hashFunction1(int key) {
        return key % tableSize;
    }
    // Räsifunktsioon 2
    int hashFunction2(int key) {
        return prime - (key % prime);
    }
    // Lisab elemendi tabelisse kasutades topelträsimist
    void insert(int key) {
        int index = hashFunction1(key);

        if (table[index] == -1) {
            // Kui koht on vaba, lisab võtme sinna
            table[index] = key;
        } else {
            // Kui koht on hõivatud, kasutab topelträsimist uue indeksi leidmiseks
            int step = hashFunction2(key);
            int i = 1;
            while (table[(index + i * step) % tableSize] != -1) {
                i++;
            }
            table[(index + i * step) % tableSize] = key;
        }
    }
    // Otsib elementi tabelist
    bool search(int key) {
        int index = hashFunction1(key);
        int step = hashFunction2(key);
        int i = 0;
        while (table[(index + i * step) % tableSize] != -1) {
            if (table[(index + i * step) % tableSize] == key) {
                return true;
            }
            i++;
        }
        return false;
    }
    // Leiab suurima esimese arvu, mis on väiksem kui antud arv
    int getLargestPrime(int n) {
        for (int i = n - 1; i >= 2; i--) {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                return i;
            }
        }
        return 2; // Kui ei leita suuremat esimest, tagastatakse 2
    }
};

int main() {
    DoubleHashingHashTable hashTable(10);

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);

    std::cout << "Otsi 15: " << (hashTable.search(15) ? "Leitud" : "Ei leitud") << std::endl;
    std::cout << "Otsi 20: " << (hashTable.search(20) ? "Leitud" : "Ei leitud") << std::endl;

    return 0;
}
