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
void invertirArchivo(char nombre[], int inicio, int ultimo);
void mostrarArchivoInvertido (char nombre[], int a);
void mostrarInverso();
void arregloCondicion(int arr[], int condicion, int i, int tam);
int sumarDigitos (int num);
int sumarCantDigitos (int num);
int esPrimo (int num, int div);
int contarMayores(int arr[], int condicion, int i, int tam);
void invertirDigitos(int num);


int main()
{
    int a[] = {1,2,3,4,5};
    int tam = sizeof(a) / sizeof(a[0]);
    int rta;
    char arch[] = "archivito.bin";
    FILE *archi = fopen("archivito.bin", "rb");
    fseek(archi, 0, SEEK_END);  // Ir al final
    int cant = ftell(archi) / sizeof(int);
    fclose(archi);  // Cerrar archivo
    invertirDigitos(123);
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
void invertirArchivo(char nombre[], int inicio, int ultimo)
{
    FILE *arch = fopen(nombre, "r+b");
    if(inicio >= ultimo)
    {
        printf("\n Archivo invertido correctamente");
        return;
    }

    int a,b;

    // posicionarse en el primer registro y leer
    fseek(arch,inicio * sizeof(int),SEEK_SET);
    fread(&a,sizeof(int),1,arch);

    // posicionarse en el ultimo registro y leer
    fseek(arch,ultimo * sizeof(int),SEEK_SET);
    fread(&b,sizeof(int),1,arch);

    // moverse e intercambiar
    fseek(arch,inicio * sizeof(int),SEEK_SET);
    fwrite(&b, sizeof(int),1,arch);

    fseek(arch,ultimo * sizeof(int),SEEK_SET);
    fwrite(&a, sizeof(int),1,arch);

    fclose(arch);

    invertirArchivo(nombre, inicio + 1, ultimo - 1);
}

/* 10 Mostrar contenido de archivo de forma invertida */
void mostrarArchivoInvertido (char nombre[], int inicio)
{
    FILE *arch = fopen(nombre, "rb");
    int aux;

    if(arch != NULL)
    {
        fseek(arch, inicio * sizeof(int), SEEK_SET);
        if(fread(&aux, sizeof(int), 1, arch) > 0)
        {
            fclose(arch);
            mostrarArchivoInvertido(nombre, inicio + 1);
            printf("\n%d",aux);

        }
        else
        {
            fclose(arch);
        }
    }

}

/* 11 Mostrar de manera inversa los caracteres hasta que haya un * */
void mostrarInverso()
{
    char c;
    printf("Ingrese un caracter, si desea finalizar ingrese *:\n");
    fflush(stdin);
    scanf("%c", &c);

    if(c == '*')
    {
        return;
    }

    mostrarInverso();
    printf("%c", c);
}

/* 12 Determinar si un arreglo tiene determinado elemento */
void arregloCondicion(int arr[], int condicion, int i, int tam)
{
    if(i<tam)
    {
        if(arr[i] == condicion)
        {
            printf("El arreglo contiene el elemento.");
        }
        else
        {
            arregloCondicion(arr, condicion, i+1, tam);

        }
    }
}

/* 13 Sumar digitos de un numero */
int sumarDigitos (int num)
{
    if(num == 0)
    {
        return 0;
    }
    else
    {
        return (num%10) +sumarDigitos(num/10);
    }
}

/* 14 Sumar cantidad de digitos */
int sumarCantDigitos (int num)
{
    int cont = 0;
    if(num == 0)
    {
        return 0;
    }
    else
    {
        return (cont+1) + sumarCantDigitos(num/10);
    }
}

/* 15 Indicar si es primo */
int esPrimo (int num, int div)
{
    if(num == div)
    {
        return 1;
    } else if (num % div == 0 && div != 1)
    {
        return 0;
    }
    else
    {
        return esPrimo(num, div+1);
    }
}

/* 16 Contar los numeros mayores a uno pasado como parametro de un arreglo */
int contarMayores(int arr[], int condicion, int i, int tam)
{
    if(i == tam)
    {
        return 0;
    }
    if(arr[i] > condicion)
    {
        return 1 + contarMayores(arr, condicion, i+1, tam);
    }else
    {
    return contarMayores(arr, condicion, i+1, tam);
    }
}

/* 17 Invertir digitos de un numero */
void invertirDigitos(int num)
{
    if(num % 10 == 0)
    {
        return;
    }
    printf("%d",num%10);
    invertirDigitos(num/10);
}
