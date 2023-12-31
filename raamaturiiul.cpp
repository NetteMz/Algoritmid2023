#include <iostream>
using namespace std;


struct Raamat { //Defineerime struktuuri Raamat, kus on raamatu nimi ja kõrgus sees
    string nimi; // Raamatu nimi
    int korgus; // Raamatu kõrgus sentimeetrites
};

void Sorteerime(Raamat raamatud[], int n) { //n on massiivi pikkus
    //
    for (int i = 0; i < n - 1; ++i) { //loop käib läbi kõik massiivi elemendid peale viimase
        for (int j = 0; j < n - i - 1; ++j) {
           // loop käib läbi kõik massiivi elemendid, mille indeksid on väiksemad
           //kui n-i-1, ehk siis välistame järjestikused sorteeritud elemendid
            if (raamatud[j].korgus > raamatud[j + 1].korgus) { //kontrollime kas hetkel vaatuse all olev raamat
                //on kõrgem kui tema kõrval olev raamat, kui see on tõene siis tõstame raamatud ümber
                // ehk vahetame kahe raamatu asukohad
                Raamat temp = raamatud[j];
                raamatud[j] = raamatud[j + 1];
                raamatud[j + 1] = temp;
            }
        }
    }
}
int main() { //Loome massiivi, kus on 10 raamatut
    Raamat raamatud[10];

    // Küsime kasutajalt raamatute nimed ja kõrgused
    for (int i = 0; i < 10; ++i) {
        cout << "Sisesta " << i+1 << ". raamatu nimi: "<< endl;
        cin >> raamatud[i].nimi;
        cout << "Sisesta " << i+1 << ". raamatu korgus (cm): "<< endl;
        cin >> raamatud[i].korgus;
    }

    // Sorteerime raamatud kõrguse järgi kasvavas järjekorras
    Sorteerime(raamatud, 10);

    // Kuvame sorteeritud raamatute järjekorra
   cout << "Sorteeritud raamatute jarjekord (kasvavalt korguse jargi):\n";
   for (int i = 0; i < 10; ++i) {
       cout << i+1 << ". raamat: " << raamatud[i].nimi << " (korgus: " << raamatud[i].korgus << " cm)\n";
   }


    return 0;
}
