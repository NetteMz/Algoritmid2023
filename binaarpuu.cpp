#include <iostream>

using namespace std;
// Binaarpuu sõlme klass
class BinaarpuuSolm {
public:
    int vaartus;
    BinaarpuuSolm* vasak;
    BinaarpuuSolm* parem;

    // Konstruktor
    BinaarpuuSolm(int v) : vaartus(v), vasak(nullptr), parem(nullptr) {}
};

// Binaarpuu klass
class Binaarpuu {
private:
    BinaarpuuSolm* juur;

    // Privaatne rekursiivne meetod sõlme lisamiseks puusse
    BinaarpuuSolm* lisaSolm(BinaarpuuSolm* juur, int vaartus) {
        // Kui puu on tühi, loo uus juursõlm
        if (juur == nullptr) {
            return new BinaarpuuSolm(vaartus);
        }

        // Kui lisatav väärtus on väiksem, mine vasakule alamhargnemisele
        if (vaartus < juur->vaartus) {
            juur->vasak = lisaSolm(juur->vasak, vaartus);
        }
        // Kui lisatav väärtus on suurem, mine paremale alamhargnemisele
        else if (vaartus > juur->vaartus) {
            juur->parem = lisaSolm(juur->parem, vaartus);
        }
        // Kui lisatav väärtus on juba olemas, ära tee midagi
        return juur;
    }

public:
    // Konstruktor
    Binaarpuu() : juur(nullptr) {}

    // Avalik meetod uue väärtuse lisamiseks binaarpuusse
    void lisa(int vaartus) {
        juur = lisaSolm(juur, vaartus);
    }

    // Avalik meetod puu läbimiseks inorder (vasak, juur, parem)
    void inorderLabimine(BinaarpuuSolm* juur) {
        if (juur != nullptr) {
            inorderLabimine(juur->vasak);
            std::cout << juur->vaartus << " ";
            inorderLabimine(juur->parem);
        }
    }

    // Avalik meetod puu läbimiseks inorder
    void inorder() {
        inorderLabimine(juur);
        cout << endl;
    }
};
int main() {
    Binaarpuu binaarpuu;

    // Lisa mõned väärtused binaarpuusse
    binaarpuu.lisa(50);
    binaarpuu.lisa(30);
    binaarpuu.lisa(70);
    binaarpuu.lisa(20);
    binaarpuu.lisa(40);
    binaarpuu.lisa(60);
    binaarpuu.lisa(80);

    // Tee inorder läbimine ja prindi välja
    cout << "Binaarpuu labimine: "<< endl;
    binaarpuu.inorder();

    return 0;
}
