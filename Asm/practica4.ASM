include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

;- Implementar la instrucción IF de los lenguajes de alto nivel con saltos condicionales

;- Hacer un programa que sume dos números que indikemos en el código y si la suma es mayor que 5 muestre un mensaje, si no salga (para mostrar el mensaje poner esa línea: invoke MessageBox, 0, 'Mayor que 5', '', 0 )

.data

   variable dd 4
   variable2 dd 4

.code

codigo:

   mov eax, [variable]
   cmp eax, [variable2]

   je iguales

    invoke MessageBoxA, 0, "Advertencia$", "No iguales$", 0

    iguales:

    invoke MessageBoxA, 0, "Bien", "Son iguales", 0


    invoke ExitProcess, 0

.end codigo