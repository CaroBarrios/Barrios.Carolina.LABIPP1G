#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define NOMBRE_LEN 20

typedef struct{
    int id;
    char nombre[NOMBRE_LEN];
    char sexo;
}eCliente;

int cliente_print(eCliente* pElement);
int printCliente(eCliente* list, int length);
int obtenerDescripcionCliente(eCliente* list, int len, int id, char nombre[]);

#endif // CLIENTE_H_INCLUDED
