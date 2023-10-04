#include <iostream>
#include <vector>

using namespace std;

// Binaarotsingu funktsioon
//Funktisoon tagastab täisarvu, sisendiks saab konstandi ja otsingut teeb sorteeritud listist
int binaarOtsing(const vector<int>& sortedList, int target) {
    int left = 0; // Vasak piir (alustab loendist esimesest elemendist)
    int right = sortedList.size() - 1; // Parem piir (alustab loendist viimasest elemendist)

    while (left <= right) { // Kuni vasak piir on väiksem või võrdne parema piiriga
        int mid = left + (right - left) / 2; // Arvutab keskme indeksi

        if (sortedList[mid] == target) {
            return mid; // Kui keskmine element on sihtmärk, tagastab selle indeksi
        } else if (sortedList[mid] < target) {
            left = mid + 1; // Kui keskmine element on väiksem kui sihtmärk, liigume parempoolsele poolele
        } else {
            right = mid - 1; // Kui keskmine element on suurem kui sihtmärk, liigume vasakpoolsele poolele
        }
    }
    return -1; // Kui sihtmärki ei leita, tagastab -1
}

int main() {
    //Siia eraldi sisendina arvu sisse andmist ei pannud, aga seda saab tulevikus siia juurde panna
    vector<int> sortedList = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Järjestatud täisarvude loend
    int target = 15; // Sihtmärk, mida otsime

    int result = binaarOtsing(sortedList, target); // Käivitab binaarotsingu

    if (result != -1) {
        cout << "Taisarv " << target << " leiti indeksilt " << result << endl; // Kui leiti, väljastatakse tulemus
    } else {
        cout << "Taisarvu " << target << " ei leitud loendist." << endl; // Kui ei leitud, väljastatakse sõnum
    }

    return 0;
}
