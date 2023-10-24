#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct votante
{
    int voto;
    char cpf[30];
    char data_nasc[30];
    char nome [30];
}votante;

typedef struct candidato
{
    char nome[30];
    int num;
    int num_voto;
}candidato;

int menu () {

    int opc;

    printf("\n==========menu========\n");
    printf("\n1 - Cadastrar eleitor");
    printf("\n2 - Cadastrar candidato");
    printf("\n3 - Votar");
    printf("\n4 - Mostrar eleitores");
    printf("\n5 - Mostrar candidatos");
    printf("\n6 - Mostrar resultados");
    printf("\n0 - Sair");

    printf("\nInsira a opcao...: ");
    fflush(stdin);
    scanf("%d", &opc);


    return opc;
}

void receberEleitor (votante *eleitor1, int cont){

    //eleitor1 = realloc (eleitor1, sizeof(votante) * cont);
    int i = cont - 1;
    //system("cls");

    printf("\nInsira o nome..[%d]: ", i);
    fflush(stdin);
    scanf("%s", eleitor1[i].nome);

    printf("Insira o cpf.......[%d]: ", i);
    fflush(stdin);
    scanf("%s", eleitor1[i].cpf);

    printf("Data de nascimento.[%d]: ", i);
    fflush(stdin);
    scanf("%s", eleitor1[i].data_nasc);

    printf("\nPressione qualquer tecla para continuar\n");
    getch();

}

void mostrarEleitor(votante *eleitor1, int cont){

    //system("cls");

    printf("\n%d\n", cont);

    for(int i = 0; i<cont; i++){
        printf("\nNOME DO ELEITOR [%d]......: %s", i, eleitor1[i].nome);
        printf("\nCPF DO ELEITOR [%d].......: %s", i, eleitor1[i].cpf);
        printf("\nDATA NASC DO ELEITOR [%d].: %s\n", i, eleitor1[i].data_nasc);
    }

    printf("\nPressione qualquer tecla para continuar\n");
    getch();
}

void receberCandidato(candidato *candidato1, int n){

    //candidato1 = realloc (candidato1, sizeof(candidato)*n);
    int i = n - 1;

    printf("\nInsira o nome do candidato...[%d]: ", i);
    fflush(stdin);
    scanf("%s", candidato1[i].nome);

    printf("\nInsira o numero do candidato.[%d]: ", i);
    fflush(stdin);
    scanf("%d", &candidato1[i].num);

    printf("\nPressione qualquer tecla para continuar\n");
    getch();

}


void mostrarCandidatos(candidato *candidato1, int n){

    for (int i = 0; i<n; i++){
        printf("\nnome do candidato: %s", candidato1[i].nome);
        printf("\nnumero do candidato: %d\n", candidato1[i].num);
    }

    printf("\nPressione qualquer tecla para continuar\n");
    getch();
}

int votar(votante *eleitor1, int cont, candidato *candidato1, int n){

    int flag = 0;
    int voto_nulo = 0;

    //inicializando num voto em candidato1
    for(int i = 0; i<n; i++){
        candidato1[i].num_voto = 0;
    }

    //mostrando opcoes de voto
    for (int i = 0; i<n; i++){
        printf("\nCANDIDATO : %s     NUMERO: %d", candidato1[i].nome, candidato1[i].num);

    }

    //pedindo voto de acordo com o cpf do eleitor
    for(int i = 0; i<cont; i++){
        printf("\n\n");
        printf("ELEITOR DE CPF '[%s]' INSIRA SEU VOTO: ", eleitor1[i].cpf);
        fflush(stdin);
        scanf("%d", &eleitor1[i].voto);
    }
        for (int i = 0; i<cont; i++){
            for(int j = 0; j<n; j++){
                if(eleitor1[i].voto == candidato1[j].num){
                    candidato1[j].num_voto++;
                    flag = 1;
                }
            }
            if(flag == 0)
                voto_nulo++;

            flag = 0;
        }

    return voto_nulo;


    printf("\nPressione qualquer tecla para continuar\n");
    getch();
}




void mostrarResultados(candidato *candidato1, int n, int votos_nulos){

    for (int i = 0; i<n; i++){
        printf("\nnome do candidato: %s", candidato1[i].nome);
        printf("\nnumero do candidato: %d", candidato1[i].num);
        printf("\nquantidade de votos: %d\n", candidato1[i].num_voto);
    }

    printf("\nvotos nulos/brancos: %d\n", votos_nulos);

    printf("\nPressione qualquer tecla para continuar\n");
    getch();
}


int main (){

    int cont = 0;
    int n = 0;
    int opc = 0;
    int votos_nulos = 0;
    votante *eleitor1 = malloc(cont*sizeof(votante));
    candidato *candidato1 = malloc(n*sizeof(candidato));

    do{
        opc = menu();

        switch (opc)
        {
        case 1:

            cont++;

            receberEleitor(eleitor1, cont);

            //printf("\n==========recebeu==========\n");

            break;

        case 2:

            n++;

            receberCandidato(candidato1, n);

            //printf("\n==========recebeu==========\n");
            break;

        case 3:

            if(n >= 3 && cont >= 10)
                votos_nulos = votar(eleitor1, cont, candidato1, n);
            else
                printf("\n\nquantidade de eleitores ou candidatos invalida\n\n");
            break;

        case 4:

            mostrarEleitor(eleitor1, cont);

            //printf("\n==========mostrou==========\n");

            break;

        case 5:

            mostrarCandidatos(candidato1, n);

            //printf("\n==========mostrou==========\n");

            break;

        case 6:

            mostrarResultados(candidato1, n, votos_nulos);

            //printf("\n==========mostrou==========\n");

            break;

        default:
            break;
        }
    }while(opc != 0);

    return 0;
}
