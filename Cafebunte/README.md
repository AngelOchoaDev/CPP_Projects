# Cafebunte

Este programa fue realizado en el segundo semestre de mi carrera, en 
la asignatura de programacion orientada a objetos. Aca aprendimos las
clases virtuales (abstractas), encapsulamiento, polimorfismo, herencia,
clases de tipo HAS-A e IS-A (composición y agregación). Tambien pudimos
apreciar el problema del diamente en la poo solo que no se ve en este 
proyecto.

El proposito general del programa es poder administrar las ventas de un
local de cafe donde se venden tres tipos de cafe: americano, capuccino y
expreso. La clase vendedor tiene permisos para ver el almacen y la caja, asi como poder realizar ventas de cafe, retirando los insumos del almacen
requeridos. La clase almacenista tiene derecho a retirar dinero de la caja con el fin de poder reabastecer el almacen, ya sea por producto o todo el almacen, una vez que se inicia sesion como almacenista no permite la salida del programa al menos que el almacen este parcialmente lleno (no vacio). El duenio ironicamente es el que menos permisos tiene, solo puede ver cuantos cafes se han vendido, cuantos insumos hay en el almacen y el dinero en caja.

Cada tipo de usuario a parte de cumplir con su rol, puede cambiar su contraseña a voluntad.

Todos los datos son leidos y guardados en un archivo .dat adjunto, asi se puede recuperar la informacion de la sesion anterior asi como añadir informacion nueva.