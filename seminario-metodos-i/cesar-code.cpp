#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main ()
{
    string abc, abcd, opc;
    int opcCas = 0;
    int frased[99] = {};
    int frase[99]= {};
    int unKey, key;

    do {

        cout << "\tMETODO DE CIFRADO C3SAR" << endl << endl;
        cout << "MENU DE OPCIONES:..." << endl;
        cout << "--> 1. Cifrar" << endl;
        cout << "--> 2. Descifrar" << endl;
        cout << "<--- 3. Salir" << endl << endl;
        getline(cin, opc);

        if(opc.length() > 1) {
            opc = "x";
        }

        opcCas = (int)opc[0];

        switch(opcCas)
        {
            case 49:
                    {
                        ofstream Escribir;
                        Escribir.open("texto.txt");
                        cout << "INGRESA FRASE A CIFRAR:" <<endl;
                        getline(cin, abc);

                        Escribir << abc;
                        Escribir.close();

                        cout<<"Ingresa la llave, recuerda no ingresar 0 o 26, no seria productivo"<<endl;
                        cin>>key;
                        cin.ignore();

                        Escribir.open("texto-cifrado.txt");

                        if (key > 26)
                            key %= 26;

                        for ( int num = 0; num < abc.length(); num++ )
                        {
                            frase[num] = (int)abc[num] + key;

                            if (frase[num] > 122)
                                frase[num] = frase[num] - 26;

                            if ((int)abc[num] == 32 )
                                frase[num] = 32;

                            cout<<(char)frase[num];
                            Escribir <<(char)frase[num] ;
                        }
                        cout << endl << endl;
                        Escribir.close();
                    }
                    break;
            case 50:
                    {
                        cout<<endl<<"\nDesencriptar:"<<endl;
                        getline(cin, abcd);

                        cout<<"Ingresa la llave para que sea posible decifrar de manera correcta el texto:"<<endl;
                        cin>>unKey;
                        cin.ignore();

                        if (unKey > 26)
                            unKey %= 26;
                            
                        for (int unum = 0; unum < abcd.length(); unum++ )
                        {
                            frased[unum] = (int)abcd[unum] - unKey;

                            if (frased[unum] < 97)
                                frased[unum] = frased[unum] + 26;

                            if (abcd[unum] == 32)
                                frased[unum] = 32;

                            cout<<(char)frased[unum];
                        }
                        cout << endl << endl;
                    }
                    break;
            case 51:
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

    } while(opcCas != 51);

    return 0;
}
