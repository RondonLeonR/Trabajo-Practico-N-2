#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAMANIO 10
#define OCUP 1
#define LIB  -1

void ePer_init(ePersona listaPersonas[],int limite)
{
    int i;
        for(i=0;i<limite; i++)
        {
            listaPersonas[i].estado=LIB;
        }
}

int ePer_obtenerEspacioLibre(ePersona listaPersonas[],int limite)
{
    int retorno = -1;
    int i;

        //retorno = -2;
        for(i=0;i<=limite;i++)
        {
            if(listaPersonas[i].estado == LIB)
            {
                retorno = i;
                break;
            }
        }
    return retorno;
}

int ePer_buscarPorDni(ePersona listaPersonas[], int dni,int limite)
{
    int i;
        for(i=0;i<limite;i++)
        {
            if(listaPersonas[i].dni==dni)
            {
                return i;
            }
        }
        return -1;
}

void ePer_Ordenamiento(ePersona listado[],int limite)
{
    ePersona auxiliar;
    int i;
    int j;
        for(i=0;i<limite-1;i++)
            {
            if(listado[i].estado==-1)
                {
                    continue;
                }
                for(j=i+1;j<limite;j++)
                {
                     if(listado[j].estado == -1)
                    {
                            continue;
                    }
                    if(strcmp(listado[i].nombre,listado[j].nombre)>0)
                    {
                        auxiliar=listado[j];
                        listado[j]=listado[i];
                        listado[i]=auxiliar;
                    }

                }
        }
}

void ePer_mostrarUno(ePersona parametro)
{
     printf("    %s",parametro.nombre);
     printf("         %d",parametro.dni);
     printf("         %d",parametro.edad);
}

void ePer_mostrarListado(ePersona listaPersonas[] ,int limite)
{
    int i;
        system("cls");
        printf("\n  Listado de Usuarios:\n\n    Nombre        DNI        Edad\n");
        for(i=0;i<limite;i++)
        {
            if(listaPersonas[i].estado==OCUP)
            {
                ePer_Ordenamiento(listaPersonas,limite);
                ePer_mostrarUno(listaPersonas[i]);
            }
        }
}

void ePer_alta(ePersona listaPersonas[] ,int limite)
{
    int indice;

        indice = ePer_obtenerEspacioLibre(listaPersonas,limite);
        if(indice==-1)
        {
            printf("No hay mas lugar.");
            getch();
        }
        else{
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(listaPersonas[indice].nombre);
            printf("Ingrese el DNI: ");
            scanf("%d",&listaPersonas[indice].dni);
            printf("Ingrese su edad: ");
            scanf("%d",&listaPersonas[indice].edad);
            system("cls");
            printf("\n\n      El usuario '%s' ha sido ingresado con exito.",listaPersonas[indice].nombre);
            getch();
            system("cls");
        }
            listaPersonas[indice].estado = OCUP;
}

void ePer_baja(ePersona listaPersonas[] ,int limite)
{
    //int i;
    int DniIngresado;
    int DniEncontrado;
    int opc;

    ePer_mostrarListado(listaPersonas,limite);
    printf("\nIngrese el DNI del usuario que desea borrar: ");
    scanf("%d",&DniIngresado);
    DniEncontrado = ePer_buscarPorDni(listaPersonas,DniIngresado,limite);
    if(DniEncontrado==-1)
    {
        printf("     El DNI ingresado no existe.");
        getch();
    }
    else{
        printf("El usuario que desea borrar es %s?",listaPersonas[DniEncontrado].nombre);
        printf("\nOpcion 1) SI\nOpcion 2) NO");
        scanf("%d",&opc);
            switch(opc){
            case 1:{
                listaPersonas[DniEncontrado].estado=-2;
                system("cls");
                printf("\nEl usuario ha sido eliminado.");
                getch();
                break;
                }
            case 2:{
                printf("\nLa baja ha sido cancelada.");
                getch();
                break;
                }
            }
        }
}


void ePer_MostrarGraficoEdades(ePersona listaPersonas[], int limite)
{
    ePer_GraficoEdades(listaPersonas,limite);
    printf("\n   <18     19-35     35>");
    getch();
}

void ePer_GraficoEdades(ePersona listaPersonas[],int limite)
{
    int contadorEdadMenor[50];
    int contadorEdadMedio[50];
    int contadorEdadMayor[50];
    int i;
    int j;
    for(i=0;i<limite;i++)
    {
        if(listaPersonas[i].estado==OCUP){
        if(listaPersonas[i].edad<=18)
            {
                contadorEdadMenor[i]=1;
                contadorEdadMedio[i]=0 ;
                contadorEdadMayor[i]=0;
            }
        else if(listaPersonas[i].edad>18&&listaPersonas[i].edad<36)
            {
                contadorEdadMenor[i]=0;
                contadorEdadMedio[i]=1;
                contadorEdadMayor[i]=0;
            }
        else if(listaPersonas[i].edad>35)
            {
                contadorEdadMenor[i]=0;
                contadorEdadMedio[i]=0;
                contadorEdadMayor[i]=1;
            }
        }
    }

    for(j=0;j<limite;j++)
    {
        if(listaPersonas[j].estado==OCUP){
        printf("    %d        %d        %d\n",contadorEdadMenor[j],contadorEdadMedio[j],contadorEdadMayor[j]);
        }
    }
}
