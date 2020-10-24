#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "bicicleta.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"
#include "informes.h"

#define QTY_BICICLETA 100
#define QTY_TIPO 4
#define QTY_COLOR 5
#define QTY_SERVICIO 4
#define QTY_TRABAJO 100
#define QTY_CLIENTE 5

int main()
{
    eBicicleta arrayBicicleta[QTY_BICICLETA];
    eTrabajo arrayTrabajo[QTY_TRABAJO];
    eTipo arrayTipo[QTY_TIPO]={
        {1000,"Rutera"},
        {1001,"Carrera"},
        {1002,"Mountain"},
        {1003,"BMX"}
    };
    eColor arrayColor[QTY_COLOR]={
        {5000,"Gris"},
        {5001,"Negro"},
        {5002,"Blanco"},
        {5003,"Azul"},
        {5004,"Rojo"}
    };
    eServicio arrayServicio[QTY_SERVICIO]={
        {20000,"Limpieza"},
        {20001,"Parche"},
        {20002,"Centrado"},
        {20003,"Cadena"}
    };
    eCliente arrayCliente[QTY_CLIENTE]={
        {6000,"Luis", 'm'},
        {6001,"Mariana", 's'},
        {6002,"Juan", 'm'},
        {6003,"Lucas", 'm'},
        {6004,"Guadalupe", 's'}
    };

    int opcion;
    int idBicicletas = 3000;
    int auxiliaryIndex;
    int triggerRegister = 0;
    int auxiliaryId;
    int auxiliaryIndexTrabajo;
    int idTrabajos = 0;


    if(initBicicletas(arrayBicicleta,QTY_BICICLETA) == 0)
    {
        printf("Bicicletas inicializadas con exito!!\n\n");
    }
    else
    {
        printf("Problemas al inicializar bicicletas\n\n");
    }

    if(initTrabajos(arrayTrabajo,QTY_TRABAJO) == 0)
    {
        printf("Trabajos inicializados con exito!!\n\n");
    }
    else
    {
        printf("Problemas al inicializar trabajos\n\n");
    }

    idBicicletas += hardcodearBicicleta(arrayBicicleta, QTY_BICICLETA, 10);

    do
    {
        if (( utn_getNumero (&opcion, "\n ****** MENU DE OPCIONES ******\n\n"
                             " 1. ALTA BICICLETA\n"
                             " 2. MODIFICAR BICICLETA\n"
                             " 3. BAJA BICICLETA\n"
                             " 4. LISTAR BICICLETAS\n"
                             " 5. LISTAR TIPOS\n"
                             " 6. LISTAR COLORES\n"
                             " 7. LISTAR SERVICIOS\n"
                             " 8. ALTA TRABAJO\n"
                             " 9. LISTAR TRABAJOS\n"
                             " 10. INFORMES\n"
                             " 11. SALIR\n\n"
                             " Ingrese una opcion: ",
                             " Opcion invalida. Vuelva a intentarlo, solo puede ingresar numeros de 1 al 10.\n\n", 1, 11, 3 )) == 0 )
        {

            switch(opcion)
            {
            case 1:
                auxiliaryIndex = getEmptyIndexBicicletas(arrayBicicleta,QTY_BICICLETA);
                if(auxiliaryIndex >= 0)
                {
                    if(addBicicletas(arrayBicicleta,QTY_BICICLETA,auxiliaryIndex,&idBicicletas, arrayCliente, QTY_CLIENTE) == 0)
                    {
                        idBicicletas++;
                        triggerRegister = 1;
                        printf("\nAlta de bicicleta con exito!!\n\n");
                    }
                }
                else
                {
                    printf("\nNo hay mas lugar\n\n");
                }
                break;
            case 2:
                if (triggerRegister)
                {
                    printBicicletas(arrayBicicleta, QTY_BICICLETA, arrayTipo, QTY_TIPO, arrayColor, QTY_COLOR, arrayCliente, QTY_CLIENTE);
                    if(utn_getNumero(&auxiliaryId,"\n\nIndique el numero de ID de la bicicleta que desea modificar: ",
                                                  "\nID invalido\n\n",0,idBicicletas,0) == 0)
                    {
                        auxiliaryIndex = findBicicletaById(arrayBicicleta,QTY_BICICLETA,auxiliaryId, arrayTipo, QTY_TIPO, arrayColor, QTY_COLOR, arrayCliente, QTY_CLIENTE);
                        if( auxiliaryIndex >= 0 &&
                            menuModifyBicicletas(arrayBicicleta,QTY_BICICLETA,auxiliaryIndex) == 0)
                            {
                                printf("\nLa modificacion se realizo con exito\n\n");
                            }
                    }
                }
                else
                {
                    printf ("\nNo puede ingresar a esta opcion sin haber registrado una bicicleta en la opcion 1\n\n");
                }
				break;
            case 3:
                if (triggerRegister)
                {
                    printBicicletas(arrayBicicleta, QTY_BICICLETA, arrayTipo, QTY_TIPO, arrayColor, QTY_COLOR, arrayCliente, QTY_CLIENTE);
                    if(utn_getNumero(&auxiliaryId,"\n\nIndique el numero del id de la bicicleta que desea eliminar: ",
                                                 "\nID invalido\n\n",0,idBicicletas,0) == 0)
                    {
                        auxiliaryId = findBicicletaById(arrayBicicleta,QTY_BICICLETA,auxiliaryId, arrayTipo, QTY_TIPO, arrayColor, QTY_COLOR, arrayCliente, QTY_CLIENTE);
                        if( auxiliaryId >= 0 &&
                            removeBicicleta(arrayBicicleta,QTY_BICICLETA,auxiliaryId) == 0)
                            {
                                printf("\nSe realizo la eliminacion con exito!!!\n\n");
                            }
                    }
                }
                else
                {
                    printf ("\nNo puede ingresar en esta opcion sin haber dado de alta una bicicleta en la opcion 1\n\n");
                }
                break;
            case 4:
                system("cls");
                printBicicletas(arrayBicicleta, QTY_BICICLETA, arrayTipo, QTY_TIPO, arrayColor, QTY_COLOR, arrayCliente, QTY_CLIENTE);
                break;
            case 5:
                system("cls");
                printTipos(arrayTipo, QTY_TIPO);
                break;
            case 6:
                system("cls");
                printColores(arrayColor, QTY_COLOR);
                break;
            case 7:
                system("cls");
                printServicios(arrayServicio, QTY_SERVICIO);
                break;
            case 8:
                system("cls");
                auxiliaryIndexTrabajo = getEmptyIndexTrabajos(arrayTrabajo,QTY_TRABAJO);
                if(auxiliaryIndexTrabajo >= 0)
                {

                    if(addTrabajo(arrayTrabajo,QTY_TRABAJO,auxiliaryIndexTrabajo,&idTrabajos, arrayBicicleta, QTY_BICICLETA, arrayTipo, QTY_TIPO, arrayColor, QTY_COLOR, arrayCliente, QTY_CLIENTE) == 0)
                    {
                        idTrabajos++;
                        printf("\nAlta de trabajo con exito!!\n\n");
                    }
                }
                else
                {
                    printf("\nNo hay mas lugar\n\n");
                }
                break;
            case 9:
                system("cls");
                printTrabajos(arrayTrabajo, QTY_TRABAJO, arrayBicicleta, QTY_BICICLETA, arrayServicio, QTY_SERVICIO);
                break;
            case 10:
                menuModifyInformes(arrayBicicleta, QTY_BICICLETA, arrayColor, QTY_COLOR, arrayTipo, QTY_TIPO, arrayCliente, QTY_CLIENTE);
                break;
            }
            system("pause");
            system("cls");
        }
    }
    while(opcion!=11);

    return 0;
}
