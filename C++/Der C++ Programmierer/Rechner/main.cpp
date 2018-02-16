#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>

using namespace std;

long ausdruck(char &);
long summand(char &);
long faktor(char &);
long potenz(char &);
long zahl(char &);

bool valide = true;

int main()
{
    char ch;
    long ergebnis;
    do
    {
        cout << "\n>>";
        cin.get(ch);
        if (ch != 'e')
        {
            ergebnis = ausdruck(ch);
            if (valide)
                cout << ergebnis;
            else
            {
                cout << "Fehler, bitte nocheinmal!";
                valide = true;
            }
        }
    }
    while(ch != 'e');

    return EXIT_SUCCESS;
}


long ausdruck(char& c)   // Übergabe per Referenz!
{
    long a; // Hilfsvariable für Ausdruck

    if(c == '–')
    {
        cin.get(c); // - im Eingabestrom überspringen
        a = -summand(c); // Rest an summand() übergeben
    }
    else
    {
        if(c == '+')
            cin.get(c); // + überspringen
        a = summand(c);
    }

    while(c == '+' || c == '–')
        if(c == '+')
        {
            cin.get(c); // + überspringen
            a += summand(c);
        }
        else
        {
            cin.get(c); // - überspringen
            a -= summand(c);
        }

    return a;
}

long summand(char& c)
{
    long s = faktor(c);

    while(c == '*' || c == '/')
        if(c == '*')
        {
            cin.get(c); // * überspringen
            s *= faktor(c);
        }
        else
        {
            cin.get(c); // / überspringen
            s /= faktor(c);
        }

    return s;
}

long faktor(char& c)
{
    long f;

    if(c == '(')
    {
        cin.get(c); // ( überspringen
        f = ausdruck(c);
        if(c != ')' ) {
            cout << "Rechte Klammer fehlt!\n";
            valide = false;
        }
        else cin.get(c); // ) überspringen
    }
    else
        f = potenz(c);

    return f;
}

long potenz(char& ch)
{
    long p = zahl(ch);

    if (ch == '^') {
        cin.get(ch);
        p = pow(p, zahl(ch));
    }

    return p;
}

long zahl(char& c)
{
    long z = 0;

    while(isdigit(c))   // d.h. c >= ’0’ && c <= ’9’
    {
        z = 10 * z + long(c - '0'); // implizite Typumwandlung
        cin.get(c);
    }
    return z;
}
