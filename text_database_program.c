#include <stdio.h>
#include <string.h>
#include <locale.h>

#define QTD_EMPRESA 1000
#define TAM_EMPRESA 30
#define ARQUIVO_EMPRESA "employees.txt"


//FUNCTION - WRITE/SAVE IN employees.txt
void empresa_write(int qtd_funcionarios){
  setlocale(LC_ALL, "pt-BR");

FILE *arquivo_w;
int count_w, ord=1;
  
char fun_codigo[QTD_EMPRESA][TAM_EMPRESA];
char fun_nome[QTD_EMPRESA][TAM_EMPRESA];
char fun_cargo[QTD_EMPRESA][TAM_EMPRESA];
char fun_salario[QTD_EMPRESA][TAM_EMPRESA];
char fun_endereco[QTD_EMPRESA][TAM_EMPRESA];
char fun_telefone[QTD_EMPRESA][TAM_EMPRESA];
char fun_status[QTD_EMPRESA][TAM_EMPRESA];

  for(count_w=0; count_w < qtd_funcionarios; count_w++){

    if(count_w==0)
      scanf("%*c");
    
    printf("\n > Code (%dth employee): ", ord);
      fgets(fun_codigo[count_w], TAM_EMPRESA, stdin);
        fflush(stdin);
    printf("\n > Name (%dth employee): ", ord);
      fgets(fun_nome[count_w], TAM_EMPRESA, stdin);
        fflush(stdin);
    printf("\n > Role (%dth employee): ", ord);
      fgets(fun_cargo[count_w], TAM_EMPRESA, stdin);
        fflush(stdin);
    printf("\n > Salary(%dth employee): ", ord);
      fgets(fun_salario[count_w], TAM_EMPRESA, stdin);
        fflush(stdin);
    printf("\n > Adress(%dth employee): ", ord);
      fgets(fun_endereco[count_w], TAM_EMPRESA, stdin);
        fflush(stdin);
    printf("\n > Phone Number(%dth employee): ", ord);
      fgets(fun_telefone[count_w], TAM_EMPRESA, stdin);
        fflush(stdin);
    printf("\n > Status(%dth employee)([+] if active / [-] if removed): ", ord);
      fgets(fun_status[count_w], TAM_EMPRESA, stdin);
        fflush(stdin);

    printf("\n");

    arquivo_w = fopen(ARQUIVO_EMPRESA, "a+");

    if(arquivo_w == NULL){
      printf("- ! < Registrarion failure, the file was not opened > !");
      exit(1);
    }
    
    fprintf(arquivo_w, "%s%s%s%s%s%s%s#\n\n", fun_codigo[count_w], fun_nome[count_w], fun_cargo[count_w], fun_salario[count_w], fun_endereco[count_w], fun_telefone[count_w], fun_status[count_w]);
    ord++;

    printf("- Registration success!\n\n");

    fclose(arquivo_w);
  }
}  


//FUNCTION - READ THE employees.txt
void empresa_read(){
  setlocale(LC_ALL, "pt-BR");

FILE *arquivo_r;
char funcionarios_reader[TAM_EMPRESA];
int count_r=0, pos;

  arquivo_r = fopen(ARQUIVO_EMPRESA, "r");

    if(arquivo_r != NULL){
      printf("\n- List of all registers:\n\n");
    }
    else {
      printf("- ! < Read failure, the file was not opened > !");
    }
  
  while (fgets(funcionarios_reader, TAM_EMPRESA, arquivo_r) != NULL) {
    printf("%s", funcionarios_reader);
  }
    
  fclose(arquivo_r);
}

//FUNCTION - SEARCH A REGISTER BY THE EMPLOYEE CODE
void empresa_read_cod(){
  setlocale(LC_ALL, "pt-BR");

FILE *arquivo_r;
char funcionarios_reader[TAM_EMPRESA];
char cod_funcionario[TAM_EMPRESA];
char quebra_de_linha[TAM_EMPRESA] = "\n";
int not_found=0;

  arquivo_r = fopen(ARQUIVO_EMPRESA, "r");

  if(arquivo_r == NULL){
      printf("- ! < Read failure, the file was not opened > !");
  }

  printf("\n> Type the unployee code: ");
    scanf("%s", cod_funcionario);

  strcat(cod_funcionario, quebra_de_linha);

  printf("\n");

  while (fgets(funcionarios_reader, TAM_EMPRESA, arquivo_r) != NULL) {
    
    if(strcmp(funcionarios_reader, cod_funcionario) == 0){

      not_found = 1;

      printf("- Search result:\n\n");
      
      for(int count_rc=0; count_rc < 6; count_rc++){
        fgets(funcionarios_reader, TAM_EMPRESA, arquivo_r);

          switch(count_rc){
            case 0: printf("| Name: %s", funcionarios_reader);
              break;
            case 1: printf("| Role: %s", funcionarios_reader);
              break;
            case 2: printf("| Salary: US$ %s", funcionarios_reader);
              break;
            case 3: printf("| Adress: %s", funcionarios_reader);
              break;
            case 4: printf("| Phone Number: %s", funcionarios_reader);
              break;
            case 5: printf("| Status: %s\n", funcionarios_reader);
              break;
          }
      }
      
    }
  }

  if(not_found == 0)
    printf("- Register not found!\n\n");
  
  fclose(arquivo_r);
}  


int main(void){
  setlocale(LC_ALL, "pt-BR");

int choice=1, qtd_funcionarios;
char cod_funcionario[5];

  while(choice != 0){
    printf("\n|-><><><><><><><><>< MENU ><><><><><><><><><-|\n\n- Choose an action:\n\n[1] - Employee registration\n[2] - Show all registers\n[3] - Search a register by the employee code\n[0] - Exit\n\n");
      scanf("%d", &choice);
  
    if(choice == 1){
      printf("\n- How many enployees do you wish to register? ");
        scanf("%d", &qtd_funcionarios);
          empresa_write(qtd_funcionarios);
    }
      
    else if(choice == 2)
      empresa_read();

    else if(choice == 3)
      empresa_read_cod('4');
      
    else if(choice == 0)
      continue;
    
    else
      printf("\n- Invalid Option!\n\n");
  }
  
  return 0;
}