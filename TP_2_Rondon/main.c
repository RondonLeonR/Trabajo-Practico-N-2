#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20


int main()
{
    ePersona listadoPer[CANT];
    ePer_init(listadoPer,CANT);

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                ePer_alta(listadoPer,CANT);
                break;
            case 2:
                ePer_baja(listadoPer,CANT);
                break;
            case 3:
                ePer_mostrarListado(listadoPer,CANT);
                getch();
                break;
            case 4:
                ePer_MostrarGraficoEdades(listadoPer,CANT);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
