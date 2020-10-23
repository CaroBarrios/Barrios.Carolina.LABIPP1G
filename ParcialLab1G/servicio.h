#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

#define DESCIPCION_LEN 25

typedef struct{
    int id;
    char descripcion[DESCIPCION_LEN];
    int precio;
}eServicio;

int servicio_print(eServicio* pElement);
int printServicios(eServicio* list, int length);
int obtenerDescripcionServicio(eServicio* list, int len, int id, char descripcion[]);

#endif // SERVICIO_H_INCLUDED
