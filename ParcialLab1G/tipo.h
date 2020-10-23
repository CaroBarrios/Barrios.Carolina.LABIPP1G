#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

#define TIPO_LEN 20

typedef struct{
    int id;
    char descripcion[TIPO_LEN];
}eTipo;

int tipo_print(eTipo* pElement);
int printTipos(eTipo* list, int length);
int obtenerDescripcionTipo(eTipo* list, int len, int id, char descripcion[]);

#endif // TIPO_H_INCLUDED
