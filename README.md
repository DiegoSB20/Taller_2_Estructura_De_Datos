# Taller_2_Estructura_De_Datos


Proyecto desarrollado en C++ para el Taller 2 de Estructura de Datos.

El sistema permite cargar pacientes desde un archivo de texto, almacenarlos inicialmente en una Queue, procesarlos mediante un árbol binario de decisión y enviarlos posteriormente al servicio correspondiente, donde son almacenados dentro de un árbol AVL.

# Integrantes

## Integrante 1

* Nombre: Diego Ivan Seco Burgos 

* RUT: 21.892.538-3

* Nombre en GitHub: DiegoSB20

* Carrera: Ingeniería Civil en Computación e Informática

* Paralelo: C1

## Integrante 2

* Nombre: David Sebastián Rodríguez Guevara 

* RUT: 21.806.579-1

* Nombre en GitHub: DatCursed

* Carrera: Ingeniería Civil en Computación e Informática

* Paralelo: C2 

# Requisitos

Para compilar el proyecto se necesita:

* Compilador compatible con C++17.

* CMake.

* Entorno Linux o GitHub Codespaces.

El proyecto fue compilado y ejecutado correctamente utilizando GitHub Codespaces.

# Instrucciones de compilacion y ejecucion 

## Compilación en GitHub Codespaces

El proyecto fue desarrollado y probado utilizando GitHub Codespaces.
desde el menú de github se abre la opción de codespace, luego se pone new Codespace y se marca la carpeta del repositorio 

## comentario
El sistema tiene funciones para consultar servicios, buscar pacientes y recorrer los AVL en inorden, preorden y postorden. Sin embargo, el menú principal como tal no tiene la opcion de verlos 
para ser mas apegados al diseño del menú como tal, pero si se llaman de forma manual se comprueba que cumple con eso. 

La estructura principal del repositorio es:
```text
Taller_2_Estructura_De_Datos/
├── Clases/
├── Core/
├── Data_structures/
├── .gitignore
├── CMakeLists.txt
├── Pacientes.txt
├── README.md
└── main.cpp
```

El archivo CMakeLists.txt se encuentra directamente en la raíz del repositorio.

Al abrir el repositorio mediante GitHub Codespaces, se puede verificar la ubicación actual utilizando:

```text
pwd
```

* La carpeta del proyecto corresponde a:
* 
```text
/workspaces/Taller_2_Estructura_De_Datos
```
* En caso de no encontrarse en esa carpeta:

```text
cd /workspaces/Taller_2_Estructura_De_Datos
```

## Compilación

Para realizar una compilación limpia:

```text
rm -rf build
cmake -S . -B build
cmake --build build
```

Si la compilación termina correctamente, debería aparecer un mensaje similar a:

```text
[100%] Built target Taller_2_Estructura_De_Datos
```

## Ejecución

Una vez compilado el proyecto, se ejecuta mediante:


```text
./build/Taller_2_Estructura_De_Datos
```

Por lo tanto, el procedimiento completo de compilación y ejecución es:

```text
rm -rf build
cmake -S . -B build
cmake --build build
./build/Taller_2_Estructura_De_Datos
```


# Criterio del árbol de decisión

El criterio fue organizado buscando identificar primero situaciones específicas y posteriormente condiciones más generales.

La estructura implementada es:
```text
¿Trauma?
|
|-- Sí:
|   ¿Requiere cirugía?
|   |
|   |-- Sí: Cirugía
|   |
|   |-- No: Traumatología
|
|-- No:
    ¿Edad < 14?
    |
    |-- Sí: Pediatría
    |
    |-- No:
        ¿Presenta síntomas neurológicos?
        |
        |-- Sí: Neurología
        |
        |-- No:
            ¿Dolor de pecho o Presión arterial >= 140?
            |
            |-- Sí: Cardiología
            |
            |-- No:
                ¿Temperatura >= 38.5 o Dolor >= 8?
                |
                |-- Sí: Urgencias
                |
                |-- No:
                    ¿Días de hospitalización >= 2?
                    |
                    |-- Sí: Hospitalización
                    |
                    |-- No: Medicina General
```
# Justificación del criterio de decisión

### Trauma

La primera condición evaluada corresponde a la presencia de trauma.

Cuando:

Trauma == 1

se analiza inmediatamente si el paciente requiere una intervención quirúrgica.

Si:

RequiereCirugia == 1

el paciente es asignado a:

 Cirugía

Si presenta trauma pero no requiere cirugía:

Traumatología

De esta manera se separan directamente los pacientes con una condición traumática según la necesidad de intervención quirúrgica.

Edad

Si el paciente no presenta trauma, se analiza su edad.

Cuando:

Edad < 14

el paciente es asignado a:

Pediatría

Este criterio permite identificar tempranamente a los pacientes pertenecientes al grupo definido para atención pediátrica dentro del modelo del sistema.

Síntomas neurológicos

Si el paciente no presenta trauma y su edad es igual o superior a 14 años, se evalúa:

SintomasNeurologicos

Cuando:

SintomasNeurologicos == 1

el paciente es enviado a:

Neurología

Esto permite detectar una condición específica antes de continuar evaluando otros factores.

Riesgo cardiológico

Si el paciente no presenta síntomas neurológicos, se evalúa una condición utilizada para determinar su envío a Cardiología.

La condición definida por el grupo es:

TipoDolor == "pecho"
O
PresionArterial >= 140

Si alguna de las dos condiciones es verdadera, el paciente es enviado a:

Cardiología

El valor de presión arterial utilizado corresponde a un umbral definido para efectos del modelo de clasificación implementado en el taller.

De esta manera se utiliza tanto el tipo de dolor como la presión arterial disponible en la información del paciente.

Urgencias

Cuando el paciente no cumple con los criterios anteriores se evalúa:

Temperatura >= 38.5
O
Dolor >= 8

Si cualquiera de estas condiciones es verdadera, el paciente es enviado a:

Urgencias

Esto permite identificar pacientes con temperatura elevada o un nivel alto de dolor según los valores definidos para el sistema.

Hospitalización

Cuando el paciente no cumple con ninguna de las condiciones anteriores se evalúa:

DiasHospitalizacion >= 2

Si se cumple:

Hospitalización

Medicina General

Cuando ninguna de las condiciones anteriores resulta verdadera, el paciente es enviado a:

Medicina General

De esta forma, todos los pacientes válidos poseen una ruta que finaliza en uno de los servicios disponibles.                            


# Atributos utilizados por el árbol de decisión

* El árbol utiliza los siguientes atributos:

* Trauma.

* Requiere cirugía.

* Edad.

* Síntomas neurológicos.

* Tipo de dolor.

* Presión arterial.

* Temperatura.

* Nivel de dolor.

* Días de hospitalización.

Por lo tanto, el árbol utiliza nueve atributos diferentes del paciente.

# funcionamiento general 

Servicios
El sistema administra los siguientes ocho servicios:
1. Urgencias.
2. Medicina General.
3. Cardiología.
4. Neurología.
5. Traumatología.
6. Cirugía.
7. Pediatría.
8. Hospitalización.
Cada servicio posee su propio árbol AVL.

## AVL
Cada servicio contiene un árbol AVL implementado manualmente.

Los pacientes almacenados dentro del AVL son ordenados utilizando:
ID del paciente
como clave de ordenamiento.

Por ejemplo:
ID menor -> subárbol izquierdo
ID mayor -> subárbol derecho

El AVL permite realizar:
- Inserción de pacientes.
- Búsqueda por ID.
- Búsqueda por nombre.
- Eliminación por ID.
- Recorrido inorden.
- Recorrido preorden.
- Recorrido postorden.
- Cálculo de altura.
- Cálculo del factor de balance.
- Visualización de factores de balance.

## Balance del AVL

El factor de balance se calcula utilizando:
Altura del subárbol izquierdo - Altura del subárbol derecho

El AVL implementa manualmente:
- Rotación simple a la derecha.
- Rotación simple a la izquierda.
- Rotación doble izquierda-derecha.
- Rotación doble derecha-izquierda.
Después de cada inserción se actualizan las alturas y se comprueba el factor de balance.

Cuando es necesario se realiza la rotación correspondiente para mantener la propiedad AVL.

Procesamiento de pacientes
El procesamiento sigue el siguiente procedimiento:
1. Se obtiene el primer paciente de la Queue.
2. Se evalúa mediante el árbol de decisión.
3. El árbol determina el servicio.
4. Se asigna el servicio al paciente.
5. Se busca el servicio correspondiente.
6. El paciente se inserta en el AVL del servicio.
7. La atención se registra en el historial.

## Recorridos

Árbol de decisión
El árbol de decisión implementa manualmente los recorridos:
Inorden
Preorden
Postorden
AVL
Los árboles AVL de los servicios también permiten ejecutar:
Inorden
Preorden
Postorden
Esto permite consultar y verificar el contenido y la estructura de los árboles.

Búsqueda de pacientes
El sistema permite realizar búsquedas de pacientes utilizando:
- ID.
- Nombre.
La búsqueda por ID aprovecha directamente el ordenamiento del árbol AVL.

Eliminación de pacientes
El sistema permite eliminar pacientes del AVL mediante su ID.

La eliminación contempla:
- Nodo sin hijos.
- Nodo con un hijo.
- Nodo con dos hijos.
Después de eliminar un nodo se vuelve a calcular la altura y se aplican las rotaciones necesarias para conservar el balance del AVL.

Manejo de memoria
Las estructuras dinámicas utilizadas por el proyecto liberan su memoria mediante destructores y métodos clear().

En particular:
- El árbol AVL libera recursivamente todos sus nodos.
- El árbol de decisión libera recursivamente todos sus nodos.
- Queue libera sus nodos.
- Stack libera sus nodos.
- List libera sus nodos.
De esta manera se evita dejar memoria dinámica asignada al finalizar la ejecución.



