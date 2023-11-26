#include <iostream>

// Funktsioon lineaarotsinguks
int linearSearch(const int arr[], int size, int target) {
    // Läbime massiivi elementide järjestikku
    for (int i = 0; i < size; ++i) {
        // Kui leitakse otsitav element, tagastatakse selle indeks
        if (arr[i] == target) {
            return i;
        }
    }
    // Kui elementi ei leita, tagastatakse -1
    return -1;
}

int main() {
    const int size = 5; // Massiivi suurus
    int arr[size] = {10, 5, 7, 3, 1}; // Massiiv, milles otsime
    int target = 7; // Otsitav element

    // Rakendame lineaarset otsingut
    int result = linearSearch(arr, size, target);

    // Kontrollime, kas element leiti ja väljastame vastava teate
    if (result != -1) {
        std::cout << "Element " << target << " leitud indeksil " << result << std::endl;
    } else {
        std::cout << "Element " << target << " ei leitud." << std::endl;
    }

    return 0; // Tagastame nullväärtuse, näidates programmi edukat lõpetamist
}
