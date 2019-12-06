#include<stdio.h>
#include<math.h>



int main(){
	int i, m, b, c[30], d, r = 0, d1, err[10] = {0}, esc_parity; 
	
	printf("Digite a quantidade de bits de dados que você deseja inserir:\n");
	scanf("%d", &m);

	printf("Qual a paridade? 1-IMPAR ou 0-PAR:\n");
	scanf("%d", &esc_parity);

	/*2 r ≥ m + r + 1 (Fórmula)
	>Onde r é o número de bits redudantes
	>m é número de bits de dados 
	*/
	while (m + r + 1 > pow(2, r))
	{
		r++;
	}
	
	printf("Número de bits de dados redundantes a serem adicionados: %d\n", r);
	printf("Total de Bits(dados+ redudante): %d", m+r);

	printf("Insira os bits de dados(UM A UM):\n");
	for(i=1;i<=m; i++){
		scanf("%d", &c[i]);
	}
	
	printf("Bits de dados inseridos:\n");
	for(i=1;i<=m;i++){
		printf("%d", c[i]);
	}

	int data[m + r], res[m+r];
    d = 0;
    d1 = 1;
	for (i = 1; i <= m + r; i++)
    {
      if ((i) == pow (2, d))
        {
        data[i] = 0;
        d++;
        }
      else
        {
        data[i] = c[d1];
        d1++;
        }
    }

	printf("Os bits de dados são codificados com bits de paridade(0):\n");
	for(i=1; i<=m+r;i++){
		printf("%d", data[i]);
	}

	return 0;
}
