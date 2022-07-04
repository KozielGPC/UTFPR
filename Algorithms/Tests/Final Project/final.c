#include <stdio.h>
#include <conio.h>
void main()
{
  FILE *arq;
  int i;
  int resultado = 1;
  int linha1[5];
  int linha2[5];
  arq = fopen("entrada.txt", "r");  
  if (arq == NULL) 
  {
     printf("Arquivo nao encontrado\n");
     return;
  }

  fscanf(arq, "%d %d %d %d %d", &linha1[0], &linha1[1], &linha1[2], &linha1[3], &linha1[4]);
  fscanf(arq, "%d %d %d %d %d", &linha2[0], &linha2[1], &linha2[2], &linha2[3], &linha2[4]);

  for (i = 0; i<5;i++)
  {
      if (linha1[i] == linha2[i])
      {
          resultado = 0;
      }
      
  }

  if (resultado == 1)
  {
      printf("Sao compativeis! ");
  }

  else
  {
      printf("Nao sao compativeis! ");
  }
  
  
}
 