#include <iostream>
#include <cstring>
#include <cmath>

#include "metodos-rsa.cpp"
#define N 26
#define ASC 97


using namespace std;

int main()
{
    int opc;
    int n = 0, p = 0, q = 0, funcionE = 0;
    int eCoprimo = 0;
    long d;
    string texto, textoCifrado;
    string aux, aux2;
    int tamTexto = 0;

    do {
        cout << "\t-----CIFRADO RSA------" << endl << endl;
        cout << "1 -> Generar llaves" << endl;
        cout << "2 -> Cifrar" << endl;
        cout << "3 -> Descifrar" << endl;
        cout << "4 <- SALIR" << endl << endl;
        cin >> opc;
        cin.ignore();

        switch(opc)
        {
            case 1:
                {
                    cout << endl << "\tINGRESE DOS NUMEROS PRIMOS QUE NO SEAN MAYORES A 1000" << endl << endl;

                    do {
                        cout << "Primer numero: " << endl;
                        cin >> p;
                        cin.ignore();

                        if(!esPrimo(p))
                        cout << "El numero que ingreso no es primo." << endl;

                    } while(!esPrimo(p));

                    cout << "El numero ingresado " << p << " es primo." << endl << endl;

                    do {
                        cout << "Segundo numero: " << endl;
                        cin >> q;
                        cin.ignore();

                        if(!esPrimo(q))
                        cout << "El numero que ingreso no es primo." << endl;

                    } while(!esPrimo(q));

                    cout << "El numero ingresado " << q << " es primo." << endl << endl;

                    n = p * q;

                    funcionE = (p - 1) * (q - 1);

                    cout << "Funcion euler: "<<funcionE << endl;

                    cout << "Elije un numero primo de esta lista..." << endl << endl;
                    for(int r = 1; r < funcionE; r++)
                        cout << "(" << r << " , " << funcionE << ")" << " = " << mcd(r, funcionE) << endl;

                    cout << "\tElije un numero, de la lista anterior que el resultado sea 1: " << endl;
                    cin >> eCoprimo;
                    cin.ignore();

                    d = inverso(eCoprimo, funcionE);

                    ///clavePublica = n * eCoprimo;
                    ///clavePrivada = n * d;
                    cout << "Tu llave publica es: (" << n << "," << eCoprimo << ")"<< endl;
                    cout << "Tu llave privada es: (" << n << "," << d << ")" << endl;
                    break;
                }
            case 2:
                {
                    eCoprimo = 0;

                    cout << "Ingrese el texto a cifrar: " << endl;
                    getline(cin, texto);
                    cout << "Ingrese su llave publica: " << endl;
                    cin >> eCoprimo;
                    cin.ignore();
                    textoCifrado = "";
                    tamTexto = texto.length();
                    long matriz[tamTexto];
                    for(int z = 0; z < tamTexto; z++)
                    {
                        matriz[z] = (int)texto[z] - ASC;
                        matriz[z] = pow(matriz[z],  eCoprimo);
                        matriz[z] = (matriz[z] % n);
                    }

                    //
                    for(int j = 0; j < tamTexto; j++)
                    {
                        for(int y = 0; y < N; y++)
                        {
                            for(int i = 0; i < N; i++)
                            {
                                if(y + (i * N) == matriz[j]) {
                                    aux = (char)(y + ASC);
                                    aux2 = (char)(i + ASC);
                                    textoCifrado = textoCifrado + aux +aux2;
                                }
                            }
                        }
                    }
                    cout << "El texto cifrado es: " << textoCifrado << endl;
                }
                break;
            case 3:
                {
                    long nn;
                    texto = "";
                    d = 0;
                    cout << "Ingrese el texto cifrado: " << endl;
                    getline(cin, texto);

                    cout << "Ingrese las dos llaves..." << endl;
                    cout << "Primera llave: " << endl;
                    cin >> nn;
                    cout << "Ingrese la llave privada: " << endl;
                    cin >> d;

                    tamTexto = texto.length();
                    long matrizDes[tamTexto];

                    for(int z = 0; z < tamTexto; z+=2)
                    {
                        matrizDes[z] = (int)texto[z] - ASC;
                        matrizDes[z+1] = ((int)texto[z+1] - ASC) * N;
                        matrizDes[z] = matrizDes[z] + matrizDes[z+1];
                    }

                    for(int z = 0; z < tamTexto; z+=2)
                    {
                        matrizDes[z] = pow(matrizDes[z], d);
                        matrizDes[z] = matrizDes[z] % nn;
                        matrizDes[z] = matrizDes[z] + ASC;
                        textoCifrado += (char)matrizDes[z];
                    }

                    cout << endl << "\t" << textoCifrado << endl;
                    break;
                }
            case 4:
                {
                    cout << "\tAdios" << endl;
                    break;
                }
            default:
                cout << "Opcion invalidad, intentelo de nuevo...." << endl;
        }

    } while(opc != 4);

    return 0;
}
