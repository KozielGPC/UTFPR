#include <stdio.h>

int main(void) {
  int voto = 1, totalVotos = 0, totalVotos1 = 0, totalVotos2 = 0, totalVotos3 = 0,totalVotos4 = 0,totalVotosNulos = 0, totalVotosbrancos = 0;

  float votosNulos = 0, votosBrancos = 0, votosVencedor = 0;

  while(voto != 0){
    printf("Candidatos: 1, 2, 3, 4 \n");
    printf("Voto nulo: 5 \n");
    printf("Voto Branco: 6 \n");
    printf("Sair: 0 \n");
    printf("Voto: ");
    scanf(" %d", &voto);
    while(voto != 1 && voto != 2 && voto != 3 && voto != 4 && voto != 5 && voto != 6  && voto != 0){
      printf("Voto Invalido, digite novamente: \n");
      scanf(" %d", &voto);
    }

    switch(voto){
      case 1:
        totalVotos1 += 1;
        break;
      case 2:
        totalVotos2 += 1;
        break;
      case 3:
        totalVotos3 += 1;
        break;
      case 4:
        totalVotos4 += 1;
        break;
      case 5:
        totalVotosNulos += 1;
        break;
      case 6:
        totalVotosbrancos += 1;
        break;
      default:
        printf("Saiu \n");
        break;
    }
  }
  totalVotos = totalVotos1 + totalVotos2 + totalVotos3  + totalVotos4 + totalVotosNulos + totalVotosbrancos;

  if(totalVotos != 0){
    votosNulos = (float)totalVotosNulos/totalVotos*100;

    votosBrancos = (float)totalVotosbrancos/totalVotos*100;

    if(totalVotos1 >= totalVotos2 && totalVotos1 >= totalVotos3 && totalVotos1 >= totalVotos4){
        votosVencedor = (float)totalVotos1/totalVotos*100;
    }

    else if(totalVotos2 >= totalVotos1 && totalVotos2 >= totalVotos3 && totalVotos2 >= totalVotos4){
        votosVencedor = (float)totalVotos2/totalVotos*100;
    }

    else if(totalVotos3 >= totalVotos1 && totalVotos3 >= totalVotos2 && totalVotos3 >= totalVotos4){
        votosVencedor = (float)totalVotos3/totalVotos*100;
    }

    else {
        votosVencedor = (float)totalVotos4/totalVotos*100;
    }
  }
    

    printf("Total de votos: %d\n", totalVotos);
    printf("Total de votos Nulos: %d\n", totalVotosNulos);
    printf("Total de votos em branco: %d\n", totalVotosbrancos);
    printf("Total de votos para o candidato 1: %d\n", totalVotos1);
    printf("Total de votos para o candidato 2: %d\n", totalVotos2);
    printf("Total de votos para o candidato 3: %d\n", totalVotos3);
    printf("Total de votos para o candidato 4: %d\n", totalVotos4);
    printf("Porcentagem de votos nulos: %'.2f \n", votosNulos);
    printf("Porcentagem de votos em branco: %'.2f \n", votosBrancos);
    printf("Porcentagem de votos do vencedor: %'.2f \n", votosVencedor);
    
  return 0;
}