#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    
    setlocale (LC_ALL, "Portuguese");

    float n1 = 0, n2 = 0, n3 = 0, ma = 0, me = 0;

    cout << "Nota 1: ";
    cin >> n1;

    cout << "Nota 2: ";
    cin >> n2;

    cout << "Nota 3: ";
    cin >> n3;

    me = (n1 + n2 + n3) / 3;
    ma = (n1 + n2 * 2 + n3 * 3 + me) / 7;

    if (ma >= 9) cout << "\nMedia A";
    else if (ma >= 7.5 && ma < 9) cout << "\nMedia B";
    else if (ma >= 6 && ma < 7.5) cout << "\nMedia C";
    else if (ma >= 4 && ma < 6) cout << "\nMedia D";
    else if (ma < 4) cout << "\nMedia E";

    return 0;
}