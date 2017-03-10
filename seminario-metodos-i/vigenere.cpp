#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string texto, clave;
    int opc;
    int frased[99] = {};
    int frase[99]= {};

    do {
        cout << "\tMETODO DE CIFRADO Vigenere" << endl << endl;
        cout << "MENU DE OPCIONES:..." << endl;
        cout << "--> 1. Cifrar" << endl;
        cout << "--> 2. Descifrar" << endl;
        cout << "<--- 3. Salir" << endl << endl;
        cin >> opc;
        cin.ignore();
    switch(opc)
    {
        case 1:
                {
                    cout << "Ingrese el texto a cifrar: " << endl;
                    getline(cin, texto);

                    cout << "Ingrese palabra clave: " << endl;
                    getline(cin, clave);

                    for (int num = 0; num < texto.length(); num++)
                    {
                        frase[num] = ((int)texto[num] - 97) + ((int)clave[num] - 97);

                        frase[num] = frase[num] % 26;

                        if ((int)texto[num] == 32 )
                            frase[num] = 32;

                        cout<<(char)(frase[num] + 97);
                    }
                    cout << endl << endl;
                }
                break;
        case 2:
                {
                    texto = "";
                    clave = "";

                    cout << "Ingrese el texto a descifrar: " << endl;
                    getline(cin, texto);

                    cout << "Ingrese palabra clave: " << endl;
                    getline(cin, clave);

                    for (int unum = 0; unum < texto.length(); unum++)
                    {
                        if((int)(texto[unum] - 97) - (int)(clave[unum] - 97) >= 0) {
                            frased[unum] = (int)(texto[unum] - 97) - (int)(clave[unum] - 97);
                            frased[unum] =  frased[unum] % 26;
                        } else if((int)(texto[unum] - 97) - (int)(clave[unum] - 97) < 0) {
                            frased[unum] = (int)(texto[unum] - 97) - (int)(clave[unum] - 97) + 26;
                            frased[unum] =  frased[unum] % 26;
                        }

                        if (texto[unum] == ' ')
                            frased[unum] = 32;

                        cout<<(char)(frased[unum] + 97);
                    }
                    cout << endl << endl;
                }
                break;
        case 3:
                {
                    cout << "Adios...." << endl << endl;
                }
                break;
        default:
                {
                cout << "Opcion invalida... intentalo de nuevo" << endl << endl;
                }
                break;
    }

} while(opc != 3);

    return 0;
}
