int copiaArchivo(char archivoorigen[], char archivodestino[]){
    unsigned int c;
    FILE *f1 = fopen(archivoorigen, "rb");
    FILE *f2 = fopen(archivodestino, "wb");
 
    if(f1 == NULL || f2 == NULL){
          printf("El archivo de origen o la ruta de destino son erroneas");
          return 1;
    }
 
    while(!feof(f1)){      
        c = getc(f1);
        fputc(c, f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
 
}
