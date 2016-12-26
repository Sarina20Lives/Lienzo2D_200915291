echo "Proceso de compilación de lienzo"
bison -t -W -o sintactico_lienzo.cpp --defines=sintactico_lienzo.h --name-prefix=lienzo sintactico_lienzo.y

echo "Proceso de compilación de flex"
flex -d -i -o lexico_lienzo.cpp --header-file=lexico_lienzo.h --prefix=lienzo lexico_lienzo.l

echo "Compilación terminada"