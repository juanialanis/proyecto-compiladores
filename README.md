# Proyecto de Taller de Diseño de Software.

## Compilacion

El programa se compila con <code> ./script.sh </code>  o <code> bash script.sh </code>, que se encarga de tirar los comandos:

<ul>
    <li><code>flex calc-lexico.l </code></li>
    <li><code>bison -d calc-sintaxis.y </code></li>
    <li><code>gcc lex.yy.c calc-sintaxis.tab.c </code></li>

## Ejecucion

### Ejecucion de un caso determinado

Para probar un caso determinado se pone el codigo del caso en el archivo <code> input.txt </code>, y se corre el mismo con <code>./a.out input.txt</code>.

### Ejecucion de todos los casos de test.

Para correr todos los test de success y fail que estan dentro de la carpeta de test, se usa el script <code>run_tests.sh</code>, y se usa con <code>./run_tests.sh</code> o <code> bash run_tests.sh</code>. 