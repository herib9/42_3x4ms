# 🧠 42cursus - Nivel de examen 04
Este repositorio contiene mis soluciones para el **examen 42cursus Exam Rank 04** , que se compone de tres niveles de ejercicios de codificación cada vez más difíciles.

## ⚙️ Nivel 1
### ✅ `ft_popen`
- **Objetivo** : Implementar una versión simplificada de `popen()`para ejecutar comandos de shell a través de `fork`, `pipe`y `execvp`.
- **Enfoque** : Configuración de tuberías, gestión de descriptores de archivos y control de procesos.
### ✅ `picoshell`
- **Objetivo** : crear un shell pequeño que analice una cadena de comandos canalizados (por ejemplo, `ls | grep a | wc -l`) y los ejecute correctamente.
- **Conceptos clave** : `fork`, `execvp`, `pipe`, `dup2`, análisis de comandos.
### ✅ `sandbox`
- **Objetivo** : detectar si una función falla, se bloquea (se agota el tiempo de espera) o sale normalmente.
- **Técnicas utilizadas** :
  - `fork()`, `alarm()`, `sigaction()`
  - Detección de fallos de segmentación o tiempos de espera
  - Análisis de los estados de salida `waitpid`
-----
## 🌲 Nivel 2
### ✅ `argo`
- **Objetivo** : analizar una cadena de entrada simplificada similar a JSON en un árbol de sintaxis abstracta (AST).
- **Tipo de analizador** : Descenso recursivo
- **Salida** : Árbol estructurado que representa objetos, matrices, cadenas y números.
### ✅ `vbc`(compilador muy básico)
- **Objetivo** : Implementar un compilador que convierta expresiones aritméticas ( `+`, `*`, paréntesis) en instrucciones tipo ensamblaje basadas en pila.
- **Conceptos clave** :
  - Tokenización
  - Construcción AST
  - Generación de código recursivo
-----
## 📌 Notas
- Todos los proyectos se implementan en **C** , sin utilizar bibliotecas externas a menos que esté explícitamente permitido.
- Cada nivel tenía un límite de tiempo estricto durante el examen.
- El repositorio está organizado en carpetas por nivel, cada una de las cuales contiene código fuente y casos de prueba.
- Me salté `tsp` debido a limitaciones de tiempo, pero planeo completarla más tarde para practicar.
-----
## 📚 Aprendizajes
- Dominio de la recursión, retroceso y estructuras de árbol.
- Conocimiento profundo del control de procesos de Unix ( `fork`, `exec`, `pipe`, `wait`).
- Escribir analizadores y compiladores desde cero sin bibliotecas.
- Manejo de errores de bajo nivel y depuración mediante señales y llamadas al sistema.
-----
## 🏁Reflexiones finales
El examen Rank 04 fue un paso importante en el dominio del pensamiento algorítmico complejo y la programación en C a nivel de sistema. Estos ejercicios me ayudaron a perfeccionar mis habilidades en recursión, análisis sintáctico, gestión de memoria y comunicación entre procesos.
