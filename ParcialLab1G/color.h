#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#define COLOR_LEN 20

typedef struct{
    int id;
    char nombreColor[COLOR_LEN];
}eColor;

int color_print(eColor* pElement);
int printColores(eColor* list, int length);
int obtenerDescripcionColor(eColor* list, int len, int id, char descripcion);

#endif // COLOR_H_INCLUDED
