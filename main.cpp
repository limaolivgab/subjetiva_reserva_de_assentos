#include <iostream>
#include <unistd.h>
// ... (código das funções exibirMapa e reservarAssento)

void exibirMapa(char vetor[10][6]) {
    // ... Código para exibir o mapa de assentos ...
    printf("\n*-*-*-*-*   Reserva   de   Assentos   *-*-*-*-*\n");
	printf("[ ] --> Assento disponivel para reserva\n[x] --> Assento nao disponivel para reserva\n");	
	printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
		for (int x=0; x<10; x++){
			if (x!=9)	printf("\n\t0%d\t", x+1);
			else		printf("\n\t%d\t", x+1);		
				for (int y=0; y<6; y++){
                printf("[%c] ", vetor[x][y]);
				if (y==2){
				printf("\t");
				}
				}
			}
	printf("\n\n------------------------------------------------\n");
}


void reservarAssento(char reserva[10][6]) {
    int fileira, coluna;
    char col_assento, assento;
    while (true) {
        // ... (solicitar tipo de assento, fileira e coluna)
        bool fil_bool = false; 
		bool col_bool = false;
        printf("Deseja reservar um assento executivo ou economico? Digite 1 para executivo ou 2 para economico: ");
	   	scanf(" %i", &assento);
	   	getchar();
		    if ((assento == 1) || (assento == 2)) {
			   	do {
			   		printf("\nDigite a fileira do assento (1-10): ");
			   		scanf(" %i", &fileira);	
			   		getchar();
			   		sleep(1);
			   		if(fileira >= 1 && fileira <= 10) {
			   			do {
			   			if(assento == 1) {
				   			printf("Digite a coluna do assento (A ou F): ");
				   			scanf(" %c", &col_assento);	 
				   			sleep(1);
				   			if ((toupper(col_assento) == 'A') || (toupper(col_assento)) == 'F') {
				   				col_bool = true;
				   				fil_bool = true;
							}else{
								printf("\nEntrada invalida! Digite apenas A ou F.");
							}
						}else{
							printf("Digite a coluna do assento (B, C, D ou E): ");
				   			scanf(" %c", &col_assento);
				   			sleep(1);
				   			if ((toupper(col_assento) == 'B') || (toupper(col_assento) == 'C') || (toupper(col_assento) == 'D') || (toupper(col_assento) == 'E')) {
				   				col_bool = true;
				   				fil_bool = true;
							}else{
								printf("\nEntrada invalida! Digite apenas B, C, D ou E.");
								sleep(1);
							}
						}
						switch(toupper(col_assento)){
							case 'A': 
								coluna = 0;
								break;
							case 'B':
								coluna = 1;
								break;
							case 'C': 
								coluna = 2;
								break;
	   	 					case 'D':
								coluna = 3;
								break;
							case 'E': 
								coluna = 4;
								break;
							case 'F': 
								coluna = 5;
								break;
						}
						} while (col_bool == false);
						
					} else {
						printf("Entrada invalida! Digite apenas um numero de 1 a 10.");
						sleep(1);
					}
			  		
				} while (fil_bool == false);
			   
		      		  // Validar a entrada do usuário
		            if (reserva[fileira-1][coluna] != 'x') {
		            	reserva[fileira-1][coluna] = 'x';
		            	sleep(1);
		            	printf("\nReserva efetuada!\n");
		            	sleep(1);
		            	exibirMapa(reserva);
		                break; // Sair do loop se a reserva foi feita
		            } else {
		            	sleep(1);
		            	printf("\nAssento reservado anteriormente! Consulte a tabela de assentos, escolha um diferente e tente novamente!\n");
		            	sleep(2);
		            	exibirMapa(reserva);
					}
		        
    		} else {
    			sleep(1);
    			printf("\nEntrada invalida. Tente novamente. ");
    			break;
			}
    }
}

int main() {
    // ... (código principal)
    char encerrar;
    char reserva[10][6] = {
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'x', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'x', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{'x', ' ', ' ', ' ', ' ', ' '}
	};
	exibirMapa(reserva);	

    while (true) {
        // ... (solicitar se o usuário deseja reservar mais assentos)
        printf("\nDeseja reservar um assento? [S/N] ");
        scanf(" %c", &encerrar);
        if (toupper(encerrar) == 'N') {
        	sleep(1);
        	printf("\nEncerrando...\n");
        	sleep(3);
            break;
        } else if (toupper(encerrar) == 'S'){
			reservarAssento(reserva);
		} else {
			printf("\nResposta invalida! Digite apenas S para sim ou N para nao");	
		}
    }
    return 0;
}
