
//LIBRERIAS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#define ESC 27

void gotoxy(int x, int y);
void ocultarCursor();
void cuadro();
void guardar_posicion();
void dibujar_cuerpo();
void borrar_cuerpo();
void teclear();
void cocina_comida();
bool perder();

//DECLARACION DE VARIABLES GLOBALES
int cuerpo[200][2];
int n = 1, tamanioSnake = 10, dir = 3;
int x = 10, y = 12;
int xc = 30, yc = 15;
int velocidad = 120;//mas alto menos velocidad
int puntos=0;
char tecla;
// char* ancho= "80 ";
// int ancho= 80;
// char* largo = "25";
// char* pantalla1 = "mode con cols=";
// char* pantalla2 = "lines=";
// strcat(pantalla1, ancho);
// strcat(pantalla1, pantalla2);
// strcat(pantalla1, largo);

//METODO DE INICIO DEL PROGRAMA
int main()
{
	gotoxy(1000, 1000);
	system("mode con cols=50 lines=25");
		// system(pantalla1);
	gotoxy (3,1); printf("SNAKE");
 	printf("\n\n");
	ocultarCursor();
 	cuadro();
 	gotoxy(xc, yc); printf("%c", 5);
 
 	while(tecla != ESC && perder()){
 		gotoxy (3,2); 
		printf("PUNTOS: %i",puntos);
		borrar_cuerpo();
		guardar_posicion();
		dibujar_cuerpo();
		cocina_comida();
		teclear();
		teclear();
 

		switch(dir)
		{
			case 1:
				y--;
			break;
			case 2:
				y++;
			break;
			case 3:
				x++;
			break;
			case 4:
				x--;
			break;
			
		}
 
		Sleep(velocidad);
 	}
 	
 	system("cls");
 	gotoxy (35,1); printf("SNAKE");
 	cuadro();
 	gotoxy (10,12); printf("TU PUNTUACION FUE: %i",puntos);
 	gotoxy (10,14); printf("Presione una tecla para continuar..");
 	getch();
	return 0;
}

//METODO QUE REALIZA EL RECTANGULO DEL JUEGO
void cuadro(){ 
	int i,v;
	
	for(i=2; i < 48; i++){
		gotoxy (i, 4); printf ("%c", 205);
 		gotoxy(i, 23); printf ("%c", 205); 
	}

	for(v=4; v < 23; v++){
 		gotoxy (2,v); printf ("%c", 186);
 		gotoxy(47,v); printf ("%c", 186); 
	}
	
 	gotoxy (2,4); printf ("%c", 201);
 	gotoxy (2,23); printf ("%c", 200);
 	gotoxy (47,4); printf ("%c", 187);
 	gotoxy(47,23); printf ("%c", 188); 
}

 
//FUNCION QUE GUARDA LA POSICION EN LA QUE SE ENCUENTRA LA SERPIENTE
void guardar_posicion(){
	cuerpo[n][0] = x;
 	cuerpo[n][1] = y;
 	n++;

	if (n == tamanioSnake)
		n = 1;
}

//FUNCION QUE BORRA EL CUERPO DE LA SERPIENTE (SE BORRA LA ULTIMA PARTE DEL CUERPO)
void borrar_cuerpo(){
	gotoxy(cuerpo[n][0] , cuerpo[n][1]); printf(" ");
}
//FUNCION QUE DIBUJA EL CUERPO DE LA SERPIENTE
void dibujar_cuerpo(){
	int i;
	for (i = 1; i < tamanioSnake; i++)
	{
		gotoxy(cuerpo[i][0] , cuerpo[i][1]); printf("*");
	}
}

//reaction_on_keyboard
void teclear(){
	if (kbhit()) //kbhit:verifica que se ha pulsado una tecla, devuelve un entero mayor que cero, si se tecleo alguna
	{
		tecla = getch();
	 	switch(tecla)
		 {
		 case 72: //FLECHA ARRIBA
			 if (dir != 2)
				 dir = 1;
			 break;
		 case 75: //FLECHA IZQUIERDA
			 if (dir != 3)
				 dir = 4;
			 break;
		 case 77: //FLECHA DERECHA
			 if (dir != 4)
				 dir = 3;
			 break;
		 case 80: //FLECHA ABAJO
			 if (dir != 1)
				 dir = 2;
			 break;
		}
 	}
}

//METODO QUE MUESTRA EN FORMA ALEATORIA LA COMIDA EN ALGUN LUGAR LA PANTALLA 
void cocina_comida(){
	if(x == xc && y == yc){
		xc = (rand() % 73) + 4;
 		yc = (rand() % 18) + 5;
		tamanioSnake++;
		puntos+=100;
 		gotoxy(xc, yc); printf("%c", 4);
	}
}

//METODO QUE OCULTA EL CURSOR
void ocultarCursor() {
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

//METODO QUE VALIDA HA TOPADO ALGUN LADO DEL RECTANGULO O A SI MISMA
bool perder(){
	int j;
	bool result = true;

	if (y == 23 ||  y == 4 || x == 2 || x == 47)
		result = false;

	for (j = tamanioSnake - 1; j > 0; j--)
	{
		if(cuerpo[j][0] == x && cuerpo[j][1] == y)
			result = false;
	}

	return result;
}


//METODO GOTOXY, SE ENVIAN COORDENADAS PARA X / Y, CON ESTO SE LOGRA POSICIONAR ALGUN MENSAJE EN UNA ZONA DETERMINADA DE LA PANTALLA
void gotoxy(int x, int y) 
{ 
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(h, c);
}




