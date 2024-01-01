#include <iostream>
#include <vector>

using namespace std;

// Funktsioon räsiväärtuste lisamiseks
void insert(vector<int>& indexMap, int key) {
    // Räsiväärtus
    int hashValue = key % indexMap.size();

    // Kui koht on juba hõivatud, leiab järgmise vaba koha
    while (indexMap[hashValue] != -1) {
        hashValue = (hashValue + 1) % indexMap.size();
    }
    // Salvestab räsiväärtuse
    indexMap[hashValue] = key;
}

// Funktsioon räsiväärtuse otsimiseks
bool search(const vector<int>& indexMap, int key) {
    // Räsiväärtus
    int hashValue = key % indexMap.size();

    // Otsib räsiväärtust
    while (indexMap[hashValue] != -1) {
        if (indexMap[hashValue] == key) {
            return true;
        }
        hashValue = (hashValue + 1) % indexMap.size();
    }
    return false;
}

int main() {
    const int size = 10;
    vector<int> indexMap(size, -1); // Vector, mis hoiab räsiväärtuste indekseid

    // Lisab ja otsib elemente
    insert(indexMap, 5);
    insert(indexMap, 15);
    insert(indexMap, 25);

    cout << "Kas 10  on olemas: " << (search(indexMap, 10) ? "<Olemas" : "Ei ole olemas") << endl;

    return 0;
}
