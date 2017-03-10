#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string texto, newTexto;
    int x, j = 0, tamMatriz = 0;

    cout<<"Ingresa tu texto a encriptar: "<< endl;
    getline(cin, texto);

    cout << "Para cifrar su mensaje es necesario un llave tipo matriz cuadra, favor de ingresar ";
    cout << "la dimencion, debe de ser mayor a 2: " << endl;
    cin >> tamMatriz;

    int matriz[tamMatriz][tamMatriz];
    int auxMatriz[tamMatriz];

    for(int fila = 0; fila < tamMatriz; fila++)
    {
        for(int colun = 0; colun < tamMatriz; colun++)
        {
            cout << "Ingrese numero en la posicion -> " << fila << "-" << colun << endl;
            cin >> matriz[fila][colun];
        }
    }

    ///METODO PARA AGREGAR CARACTERES A UNA CADENA DE CARECTERES Y SE CONVIERTA
    ///EN DEVISIBLE DE 3 O DEL NUMERO DE DATOS QUE SE TOMARAN EN LA MATRIZ
    while(texto.length() % tamMatriz != 0)
    {
            texto+= '~';
    }

    int  k = tamMatriz;

    do {
        string aux;

        for (j; j < k; j++)
        {
            aux += texto[j];
        }

        for (int i = 0; i < tamMatriz; i++) ///fila
        {
            for (int y = 0; y <tamMatriz; y++) ///columna
            {
                x +=  ((int)aux[y] - 97) * matriz[i][y];
            }
            auxMatriz[i] = x;
            x = 0;
        }
        k += tamMatriz;

        ///MATRIZ QUE GUARDA LA CADENA YA ENCRIPTADA CADA tamMatriz CARACTERES EL CONTENIDO
        for (int h = 0; h < tamMatriz; h++)
        {
            newTexto += (char)((auxMatriz[h] % 26) + 97);
        }

    } while(k <= texto.length());

    cout << endl << endl <<newTexto;

    return 0;
}
