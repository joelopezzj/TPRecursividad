#include <stdio.h>
#include <stdlib.h>
int factorial (int x);
int potencia (int x, int pot);
void mostrarArreglo(int a[], int tam, int i);
void mostrarArregloInver(int a[], int tam, int i);
void capicua(int a[], int ini, int fin);
int sumarArreglo(int a[], int i, int tam);
int buscarMenor(int a[], int i, int tam);
void llenarArchivo(char nombre[]);
void mostrarArchivo(char nombre[]);
int buscarMenorArchivo(char nombre[]);
void invertirArchivo(char nombre[]);

int main()
{
    int a[] = {3,2,3,5,7,6,10,8};
    int tam = sizeof(a) / sizeof(a[0]);
    int rta;
    char arch[] = "archivito.bin";
    mostrarArchivo(arch);

}

///Ejercicios///
/* 1 */
int factorial (int x)
{
    int rta;
    if (x ==0)
    {
        return 1;
    }
    else
    {
        rta = x * factorial(x-1);
    }
    return rta;
}

/* 2 */
int potencia (int x, int pot)
{
    int rta;
    if(pot == 0)
    {
        return 1;
    }
    else
    {
        rta = x * potencia(x, pot-1);
    }
    return rta;
}

/* 3 */
void mostrarArreglo(int a[], int tam, int i)
{
    if(i == tam)
    {
        return ;
    }
    else
    {
        printf("%d\n",a[i]);
        mostrarArreglo(a, tam, i+1);
    }
}

/* 4 */
void mostrarArregloInver(int a[], int tam, int i)
{
    if(i == tam)
    {
        return ;
    }
    else
    {
        mostrarArregloInver(a, tam, i+1);
        printf("%d\n",a[i]);
    }
}

/* 5 */
void capicua(int a[], int ini, int fin)
{
    if(ini >= fin)
    {
        printf("ES CAPICUA");
    }
    else
    {
        if(a[ini] != a[fin])
        {
            printf("NO ES CAPICUA");
        }
        else
        {
            capicua(a, ini+1, fin-1);
        }
    }
}

/* 6 */
int sumarArreglo(int a[], int i, int tam)
{
    if(i == tam)
    {
        return 0;
    }
    else
    {
        return a[i] + sumarArreglo(a, i+1, tam);
    }
}

/* 7 */
int buscarMenor(int a[], int i, int tam)
{
    int sig;
    if( i == tam-1)
    {
        return a[i];
    }
    else
    {
        sig = buscarMenor(a, i+1, tam);
        if(sig < a[i])
        {
            return sig;
        }
        else
        {
            return a[i];
        }
    }
}

/* 8 */
int buscarMenorArchivo(char nombre[])
{
    int actual, sig;
    FILE *arch = fopen(nombre, "rb");
    if(fread(&actual, sizeof(int), 1, arch) < 1)
    {
        return 141231;
    }
    else
    {
        sig = buscarMenorArchivo(nombre);

        if(actual < sig)
        {
            return actual;
        }
        else
        {
            return sig;
        }
    }
}
/* AUX */
void llenarArchivo(char nombre[])
{
    FILE *arch = fopen(nombre, "wb");
    int a = 1;
    while(a < 5)
    {
        fwrite(&a, sizeof(int), 1, arch);
        a++;
    }
    fclose(arch);
}

void mostrarArchivo(char nombre[])
{
    FILE *arch = fopen(nombre, "rb");
    int num;

    if(arch == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    printf("Contenido del archivo:\n");

    while(fread(&num, sizeof(int), 1, arch) > 0)
    {
        printf("%d\n", num);
    }

    fclose(arch);
}

/* 9 */
void invertirArchivo(char nombre[])
{
    FILE *arch = fopen(nombre, "r+b");
    int num;

    if(arch == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    // Intenta leer un número
    if(fread(&num, sizeof(int), 1, arch) == 1)
    {
        // Guarda la posición actual antes de la llamada recursiva
        long pos = ftell(arch);
        fclose(arch);
        // Llamada recursiva
        invertirArchivo(nombre);

        // Regresa a la posición y escribe el número
        arch = fopen(nombre, "r+b");
        fseek(arch, pos, SEEK_SET);
        fwrite(&num, sizeof(int), 1, arch);
        fclose(arch);
    }
    else
    {
        fclose(arch);
    }
}
