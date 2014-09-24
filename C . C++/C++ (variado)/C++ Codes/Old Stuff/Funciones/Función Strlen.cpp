int strlen(char* cadena)      // Se utiliza int como declarante por que
{                            // el valor de retorno es el numero de caracteres.
    int i;                  // -------------------------------------------------
    for(i=0;cadena[i];i++);// Se declara un puntero hacia "cadena" por que las
    return i;             // cademas se leen como un puntero.
}                        // ----------------------------------------------------
                        // El valor de "cadena[ i ]" vale '\0' osea CERO cuando 
                       // la cadena termina, el CERO es interpretado como falso,
                      // por lo que el bucle termina.
