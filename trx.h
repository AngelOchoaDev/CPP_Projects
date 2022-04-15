#ifndef _trx_h
#define _trx_h

#include<windows.h>
#include<time.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<math.h>
#include<list>
#include<vector>

using namespace std;

/**
 * @brief Posiciona el cursor en un punto específico de la consola, partiendo de la esquina superior izquierda.
 * 
 * @param x : Determina la posición en el eje x (horizontal).
 * @param y : Determina la posición en el eje y (vertical).
 */
void lugar(int x, int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/**
 * @brief Dibuja rectangulos con el simbolo '*' dependiendo de su tamaño.
 * 
 * @param x  Determina el largo de los rectangulos en el eje x.
 * @param y  Determina el alto de los rectangulos en el eje y.
 * 
 * @param nx  Determina el numero de rectangulos en el eje x.
 * @param ny  Determina el numero de rectangulos en el eje y.
 * 
 * @param paddingX Determina la distancia entre rectangulos en el eje x.
 * @param paddingY Determina la distancia entre rectangulos en el eje y.
 * 
 * @version 1.0
 */
void DibujarRectangulos(int x, int y, int nx, int ny, int paddingX, int paddingY)
{
    if (nx*(paddingX+x)>110){nx=110/(x+paddingX);}
    if (ny*(paddingY+y)>30){ny=30/(y+paddingY);}

    for (int j = 0; j < ny; j++)
    {
        for (int i = 0; i < nx; i++)
        {
            for (int m = 0; m < x; m++)
            {
                lugar((m+paddingX)+(x+paddingX)*(i),paddingY+(y+paddingY)*(j));
                cout<<"*";
                lugar((m+paddingX)+(x+paddingX)*(i),(paddingY+y)*(j+1)-1);
                cout<<"*";
            }

            for (int n = 0; n < y; n++)
            {
                lugar(paddingX+(x+paddingX)*(i),(n+paddingY)+(y+paddingY)*(j));
                cout<<"*";
                lugar((x+paddingX)*(i+1)-1,(n+paddingY)+(y+paddingY)*(j));
                cout<<"*";
            }
        }
    }
}

/**
 * @brief Dibuja un cuadrado con un marco de unos y centro de ceros.
 * 
 * @param x Define el ancho del cuadrado.
 * @param y Define el alto del cuadrado.
 */
void DibujarCuadrado(int x, int y)
{
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            if((i>0 && i<(x-1))&&(j>0 && j<(y-1)))
            {
                cout<<"0";
            }
            else
            {
                cout<<"1";
            }
        }
        cout<<endl;
    }
}

#endif