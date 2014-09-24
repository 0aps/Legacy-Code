    ; Escrito por mDrinky
include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'
    .data
	    cadena	    db 'hoola tiio jiii',0 ; Cadena a comprimir
	    buffer	    rb 50 ; Buffer con la cadena comprimida
	    BufferDes	    rb 50 ; Buffer con la cadena descomprimida
     
    .code
    start:
	    mov esi,cadena	    ; ESI = Puntero a Cadena
	    mov edi,0
     
	    BucleCorredizo:  ; Compresion
	    mov al,byte[esi]
     
	    cmp byte[esi+1],al
	    jne NoCoincide	    ; Si no hay coincidencias....
     
	    ; aqui se marcaría el bit
     
	    mov cl,byte[esi]
	    mov al,0x80
     
	    or al,cl   ; byte marcado
     
	    mov byte[buffer+edi],al
	    inc esi
     
	    jmp SiCoincidia
     
	    NoCoincide:
	    mov al,byte[esi]
	    ; aqui se desmarca el byte
	    rcl al,1
	    clc
	    rcr al,1
     
	    mov byte[buffer+edi],al
     
	    SiCoincidia:
     
	    inc edi
	    inc esi
     
	    cmp byte[esi],0
	    jne BucleCorredizo
     
     
	    invoke MessageBoxA,0,buffer,'Datos Comprimidos',0
     
     
	    ; Descompresion
     
	    mov esi,buffer
	    xor edi,edi
     
	    BucleDescompresion:
	    mov al,byte[esi]
	    mov cl,al
     
	    shr cl,7
	    cmp cl,1
	    jne  NoCom ; No esta comprimido
	    ; Si esta comprimido
     
	    rcl al,1
	    clc
	    rcr al,1
     
	    mov byte[BufferDes+edi],al ; Copiamos en el buffer 2 veces lo mismo
	    inc edi
	    mov byte[BufferDes+edi],al
     
	    NoCom: ; No esta comprimido.
	    mov byte[BufferDes+edi],al
     
	    siEstaba:
     
	    inc esi
	    inc edi
     
	    cmp byte[esi],0
	    jne BucleDescompresion
     
	    invoke MessageBoxA,0,BufferDes,'Datos Descomprimidos',0
	    ret
    .end start
