//Ajamõõtmised varieeruvad sõltuvalt masiivi suurusest ja arvuti suutlikusest
//Selle massiivi puhul on ajaline keerukus minimaalne, kuna tegemist on väikese massiiviga

#include <iostream>
#include <ctime>
using namespace std;

//https://www.programiz.com/cpp-programming/stack
//https://www.programiz.com/cpp-programming/library-function/ctime/clock

const int MAX_SUURUS = 1000;  // Määrame maksimaalse stacki suuruse

int stack[MAX_SUURUS]; // Dünaamiline massiiv, mis on meie määratud suurusega
int top = -1; // Näitab stacki tippu

//Ajamõõtmise funktsioon
double aeg(void (*operation)()){
    clock_t algus, lopp;
    algus = clock();
    operation();
    lopp = clock();
    //Tagastame kulunud aja sekundites
    return double( lopp - algus) / CLOCKS_PER_SEC;
}
// Lisa element stacki
void push(int element) { // Võtab argumendina 'element' ja lisab selle stacki
//Kontrollib kas stack on täis enne uue elemendi lisamist
    if (top < MAX_SUURUS - 1) {
        stack[++top] = element; //
    } else {
        cout << "Stack on tais. Elementi ei saa lisada." <<endl;
    }
}
// Võta ja eemalda ülemine element stackist
int pop() {
    //Kontrollib kas stack ei ole tühi enne elemendi eemaldamist
    if (top >= 0) {
        return stack[top--];
    } else {
        cout << "Stack on tyhi. Elementi ei saa votta." << endl;
        return -1; // Tagastab vaikimisi väärtuse vea korral
    }
}
// Kontrollime, kas stack on tühi ja tagastab kas 'true' või 'false'
bool isEmpty() {
    return top == -1;
}

// Vaata stacki pealmist elementi ja tagastab selle konsooli
int peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        cout << "Stack on tyhi. Ei saa vaadata pealmist elementi." << endl;
        return -1; // Tagastab vaikimisi väärtuse vea korral
    }
}

int main() {
    
    push(32);
    push(12);
    push(45);
    push(58);
    pop();
    pop();

    cout << "Pealmine element: " << peek() << endl;
    //Kasutab isEmpty et kuvada kas stack on tühi

    if (isEmpty()){
        cout << "Stack on tyhi." << endl;
    }
    else {
        cout << "Stack ei ole tyhi." << endl;
    }
//Mõõdame push operatsioni aega
    double pushAeg = aeg([]() {push(42);}); //[]() { push(42); } on anonüümne lambda-funktsioon,
    //mis ei võta argumente ([]()) ja teeb ühe operatsiooni, kutsub välja push(42);.
    //See tähendab, et see lambda-funktsioon lisab 42 stacki, mille kirust me mõõdame

    cout << "Push operatiooni aeg: " << pushAeg << "sekundit." << endl;

//Tühjendame stacki
    top = -1;
//Mõõdame pop operatsiooni aega
    double popAeg = aeg([](){pop();});
    cout << "Pop operatsiooni aeg: " << popAeg << "sekundit." << endl;

    return 0;
}
