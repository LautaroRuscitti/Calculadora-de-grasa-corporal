#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int genero;
    float altura, peso, imc;
    char datos[4];
    int valido;

    do
    {
        valido = 1; // Inicializamos la bandera de validacion como verdadera

        printf("\n1: Masculino");
        printf("\n2: Femenino");
        printf("\n3: Otro.");
        printf("\nIngrese su genero (1, 2 o 3): ");
        scanf("%i", &genero);

        // Verificar si el genero ingresado es valido (1, 2 o 3)
        switch (genero)
        {
        case 1:
        case 2:
        case 3:
            break; // Caso valido, continuamos
        default:
            printf("Opcion no valida. Por favor ingrese 1, 2 o 3.\n");
            valido = 0; // Cambiamos la bandera a falso para repetir el bucle
            break;
        }

    } while (!valido);

    do
    {
        // Si llegamos aqui, el genero es valido
        char unidad[3];
        printf("\nIngrese su altura seguida de la unidad (ej. 175cm o 1.75m): ");
        scanf("%f%s", &altura, unidad);

        // Convertir la altura a metros si es en centimetros
        if (strcmp(unidad, "cm") == 0)
        {
            altura /= 100.0; // Convertir de centimetros a metros
        }

        printf("\nIngrese su peso en kilogramos: ");
        scanf("%f", &peso);
        printf("¿Confirmar datos? (Escriba 'no' para volver a ingresar los datos): ");
        scanf("%s", datos);
    } while (strcmp(datos, "No") == 0 || strcmp(datos, "no") == 0);

    // Calcular el IMC
    imc = peso / (altura * altura);

    // Mostrar el porcentaje de grasa corporal segun el genero
    switch (genero)
    {
    case 1: // Masculino
        if (imc <= 15)
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal. Estas delgado.", imc);
        }
        else if (imc <= 25)
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal. Estas normal.", imc);
        }
        else if (imc <= 30)
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal. Estas gordo, ve al gimnasio!", imc);
        }
        else if (imc > 31)
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal. Estas muy obeso, tienes que empezar a ejercitarte.", imc);
        }
        else
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal.", imc);
        }
        break;
    case 2: // Femenino
        if (imc <= 15)
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal. Estas delgada.", imc);
        }
        else if (imc <= 25)
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal. Estas normal.", imc);
        }
        else if (imc <= 30)
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal. Estas gorda, ve al gimnasio!", imc);
        }
        else if (imc > 31)
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal. Estas muy obesa, tienes que empezar a ejercitarte.", imc);
        }
        else
        {
            printf("\nUsted tiene %0.1f porciento de grasa corporal.", imc);
        }
        break;
    case 3: // Otro
        printf("\nLo siento. A personas con discapacidades mentales no les hago el test. :(");
        break;
    default:
        break;
    }

    return 0;
}
