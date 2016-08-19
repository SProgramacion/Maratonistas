# Contribuir
Para realizar una contribución es necesario conocer los conceptos básicos en el manejo del sistema de control de versiones **[git](http://rogerdudler.github.io/git-guide/index.es.html)**


# Tutorial #
1. Descargar e instalar **git**

	> __Linux:__ ```sudo apt-get install git ```
	> __Windows:__  https://git-scm.com/download/win

2. Tener una cuenta de [github](https://github.com/) (Iniciar sesión)
3. Abrir el repositorio de [Maratonistas](https://github.com/YeisonGomez/Maratonistas) desde el navegador web.
4. Click en el botón **Fork** y posteriormente en la ventana emergente seleccionar tu cuenta de usuario.
5. Abrir el repositorio _forkeado_ (Ubicado en tu cuenta de GitHub)
6. Click en el botón verde **Clone or Download** y copiar la dirección que se muestra. (Ej.:  https://github.com/*tunombreusuario*/Maratonistas.git)
7. Abrir la consola de comandos (CMD en windows o Bash en Linux) y escribir lo siguiente:
	```git clone https://github.com/tunombreusuario/Maratonistas.git
	cd Maratonistas
	```
8. Cargar los cambios necesarios (nuevos ejercicios solucionados, correcciones de documentación, etc.)
9. Subir modificaciones al repositorio (Desde la consola):
	```git add .
	git commit -m "aqui la descripción de los nuevos cambios"
	git push origin master
	```
10. Finalmente tu repositorio _forkeado_ tiene los cambios cargados, se procede a realizar un **pull request** para subir los cambios al repositorio principal.
11. s


# Recomendaciones #

Procuren no hacer sus commits en otra rama.
Clasifiquen sus ejercicios de forma entendible para los demas.
