//Chamando as bibliotecas
#include <stdlib.h> // Aloca��o de mem�ria, controle de processos, convers�es, gera��o de n�meros aleat�rios e outras opera��es gerais
#include <stdio.h> // Para uso de opera��es de entrada e sa�da
#include <locale.h> //Para definir localiza��o
#include <stdbool.h> //Para uso de express�es booleanas (true and false)
#include <string.h> //Para manipula��es de textos
#include <unistd.h> // Para uso do delay no terminal

//Defini��o de variaveis com valores padr�es a serem usados no programa principalmente para definir tamanho de vetores.
#define MAX_NOME 50 //variavel usada para definir o tamanho m�ximo de caracteres permitidos no nome
#define MAX_ALUNO 5 //variavel usada para definir a quantidade m�xima de alunos a serem cadastrados no sistema
#define MAX_PROFESSOR 3 //variavel usada para definir a quantidade m�xima de professores a serem cadastrados no sistema
#define MAX_DISCIPLINA 4 //variavel usada para definir a quantidade m�xima de disciplinas a serem cadastradas no sistema
#define MAX_NOTAS 40 //variavel usada para definir a quantidade m�xima de notas a serem cadastradas no sistema

// Defini��o de variaveis de forma global fora da fun��o principal "main".
int serial_matricula = 1;
int serial_codigo = 1;
int escolha = 0;
int quantidade = 0;
int quantidade_aluno = 0;
int quantidade_professor = 0;
int quantidade_disciplina = 0;
int quantidade_notas = 0;
int quantidade_professor_disciplina = 0;
int alunos_notas = 0;

// Criando tipo de dados "Data" atrav�s de uma estrutura.
typedef struct Data{
    int dia,mes,ano;
} tipo_data;

// Criando tipo de dados "notas" atrav�s de uma estrutura.
typedef struct Notas{  
    char nome_disciplina[MAX_NOME];
    char nome_aluno[MAX_NOME];
    float nota1;
    float nota2;
} tipo_notas; //definindo um alias para a struct Notas.

// Criando tipo de dados "aluno" atrav�s de uma estrutura.
typedef struct Aluno{
   char nome[MAX_NOME];
   char sobrenome[MAX_NOME];
   int idade;
   char sexo;
   int matricula;
   char turma;
   tipo_data nascimento; //criando uma coluna com base no tipo de dados "tipo_data" criado atrav�s de uma estrutura.
} tipo_aluno; //definindo um alias para a struct Aluno.

// Criando tipo de dados "professor" atrav�s de uma estrutura.
typedef struct Professor{
    char nome[MAX_NOME];
    char sobrenome[MAX_NOME];
    char sexo;
    int cpf;
    int idade;
    tipo_data nascimento; //criando uma coluna com base no tipo de dados "tipo_data" criado atrav�s de uma estrutura.
} tipo_professor; //definindo um alias para a struct Professor.

// Criando tipo de dados "disciplina" atrav�s de uma estrutura.
typedef struct Disciplina{
    int codigo;
    char nome[MAX_NOME];
    int carga_horaria;
} tipo_disciplina; //definindo um alias para a struct Disciplina.

// Criando tipo de dados "professor_disciplina" atrav�s de uma estrutura.
typedef struct Professor_Disciplina{
    //Todos os campos foram criados com base em tipos de dados definidos em outras structs.
    tipo_disciplina disciplina;
    tipo_professor nome_professor;
} tipo_professor_disciplina; //definindo um alias para a struct Professor_Disciplina.

//Criando vetores de estruturas
tipo_aluno alunos[MAX_ALUNO];
tipo_professor professores[MAX_PROFESSOR];
tipo_disciplina disciplinas[MAX_DISCIPLINA];
tipo_professor_disciplina professores_disciplinas[MAX_DISCIPLINA];
tipo_notas notas_alunos[MAX_NOTAS];
// Fun��o para limpar o terminal verificando o SO

void limparTerminal() {
#ifdef _WIN32
    system("cls");  // Comando para Windows
#else
    system("clear");  // Comando para Unix/Linux/Mac
#endif
}
// Criando fun��o para definir o menu principal do sistema.
void menu_principal (){
    //Atribuindo o valor NULL para a var escolha sempre que a fun��o for chamada
    //Isso servir� para garantir que n�o haver� sujeira de hist�rico para atrapalhar
    escolha = 0;
    
    while (1) {

        printf("-------------------------------------\n");
        printf("|       1 - Cadastrar               |\n");
        printf("|       2 - Informa��es de alunos   |\n");
        printf("|       3 - Gerar relat�rios        |\n");
        printf("|       4 - Sair                    |\n");
        printf("-------------------------------------\n");
        printf("Escolha uma op��o: ");
        
        if (scanf("%d", &escolha) != 1) {
            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
            while (getchar() != '\n');
            limparTerminal();
            printf("Entrada inv�lida! Por favor, insira um n�mero entre 1 e 4.\n");
            continue;
        }
        
        if (escolha >= 1 && escolha <= 4) {
            // Saindo do loop se a escolha for v�lida
            break;
        } else {
            limparTerminal();
            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e 4.\n");
        }
    }
    getchar();

}
// Criando fun��o para definir o menu de cadastro do sistema.
void menu_cadastro (){
    //Atribuindo o valor NULL para a var escolha sempre que a fun��o for chamada
    //Isso servir� para garantir que n�o haver� sujeira de hist�rico para atrapalhar
    escolha = 0; 
    while (1) {

        printf("-------------------------------------\n");
        printf("|       1 - Cadastrar aluno         |\n");
        printf("|       2 - Cadastrar professor     |\n");
        printf("|       3 - Cadastrar disciplina    |\n");
        printf("|       4 - Sair                    |\n");
        printf("-------------------------------------\n");
        printf("Escolha uma op��o: ");
        
        if (scanf("%d", &escolha) != 1) {
            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
            while (getchar() != '\n');
            limparTerminal();
            printf("Entrada inv�lida! Por favor, insira um n�mero entre 1 e 4.\n");
            continue;
        }    
        if (escolha >= 1 && escolha <= 4) {
            // Saindo do loop se a escolha for v�lida
            break;
        } else {
            limparTerminal();
            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e 4.\n");
        }
    }
    getchar();
}
// Criando fun��o para definir o menu de informa��es de aluno.
void menu_info_alunos (){
    //Atribuindo o valor NULL para a var escolha sempre que a fun��o for chamada
    //Isso servir� para garantir que n�o haver� sujeira de hist�rico para atrapalhar
    escolha = 0;
    
    while (1) {
        printf("-------------------------------------\n");
        printf("|       1 - Registrar notas         |\n");
        printf("|       2 - Notas por aluno         |\n");
        printf("|       3 - Alunos reprovados       |\n");
        printf("|       4 - Sair                    |\n");
        printf("-------------------------------------\n");
        printf("Escolha uma op��o: ");   
        if (scanf("%d", &escolha) != 1) {
            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
            while (getchar() != '\n');
            limparTerminal();
            printf("Entrada inv�lida! Por favor, insira um n�mero entre 1 e 3.\n");
            continue;
        }     
        if (escolha >= 1 && escolha <= 3) {
            // Saindo do loop se a escolha for v�lida
            break;
        } else {
            limparTerminal();
            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e 4.\n");
        }
    }
    getchar();
}
// Criando fun��o para definir o menu de relat�rios.
void menu_relatorios (){
    //Atribuindo o valor NULL para a var escolha sempre que a fun��o for chamada
    //Isso servir� para garantir que n�o haver� sujeira de hist�rico para atrapalhar
    escolha = 0; 
    while (1) {
        printf("------------------------------------------------------------\n");
        printf("|       1 - Alunos cadastrados e suas notas                |\n");
        printf("|       2 - Professores e suas disciplinas                 |\n");
        printf("|       3 - Sair                                           |\n");
        printf("------------------------------------------------------------\n");
        printf("Escolha uma op��o: ");
        if (scanf("%d", &escolha) != 1) {
            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
            while (getchar() != '\n');
            limparTerminal();
            printf("Entrada inv�lida! Por favor, insira um n�mero entre 1 e 3.\n");
            continue;
        }   
        if (escolha >= 1 && escolha <= 3) {
            // Saindo do loop se a escolha for v�lida
            break;
        } else {
            limparTerminal();
            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e 3.\n");
        }
    }
    getchar();
}
void menu_retorna(){

    escolha = 0;
    while (1) {
        printf("------------------------------------------------------------\n");
        printf("|               1 - Retornar ao menu principal              |\n");
        printf("|               2 - Encerrar o programa                     |\n");
        printf("------------------------------------------------------------\n");
        printf("Escolha uma op��o: "); 
        if (scanf("%d", &escolha) != 1) {
            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
            while (getchar() != '\n');
            limparTerminal();
            printf("Entrada inv�lida! Por favor, escolha a op��o 1 ou 2.\n");
            continue;
        } 
        if (escolha >= 1 && escolha <= 2) {
            // Saindo do loop se a escolha for v�lida
            break;
        } else {
            limparTerminal();
            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e 4.\n");
        }
    }
    getchar();
}
// Fun��o para remover o caractere de nova linha, se presente
void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
//fun��o para adicionar os alunos
 tipo_aluno AdicionarAluno (){

    tipo_aluno aluno;
    printf("Nome: ");
    fgets(aluno.nome, MAX_NOME, stdin);
    removerNovaLinha(aluno.nome);

    printf("Sobrenome: ");
    fgets(aluno.sobrenome, MAX_NOME, stdin);
    removerNovaLinha(aluno.sobrenome);

    printf("Idade: ");
    scanf("%d", &(aluno.idade));
    getchar(); // Consumir o newline deixado por scanf

    printf("Sexo F ou M: ");
    scanf(" %c", &(aluno.sexo));
    getchar(); // Consumir o newline deixado por scanf
    //Matricula
    aluno.matricula = serial_matricula++;

    printf("Turma: ");
    scanf(" %c", &(aluno.turma));
    getchar(); // Consumir o newline deixado por scanf

    printf("Data de nascimento (dd mm yyyy): ");
    scanf("%d %d %d", &(aluno.nascimento.dia), &(aluno.nascimento.mes), &(aluno.nascimento.ano));
    getchar(); // Consumir o newline deixado por scanf

    return aluno;
}
//fun��o para adicionar informa��es sobre disciplinas
tipo_disciplina AdicionarDisciplina (){

    tipo_disciplina disciplina;
    //c�digo 
    disciplina.codigo = serial_codigo++;

    printf("Nome: ");
    fgets(disciplina.nome, MAX_NOME, stdin);
    removerNovaLinha(disciplina.nome);

    printf("Carga hor�ria: ");
    scanf("%d", &(disciplina.carga_horaria));
    getchar(); // Consumir o newline deixado por scanf

    return disciplina;
}
//Fun��o para adicionar informa��es sobre professores
tipo_professor AdicionarProfessor (){

    tipo_professor professor;
    
    printf("Nome: ");
    fgets(professor.nome, MAX_NOME, stdin);
    removerNovaLinha(professor.nome);

    printf("Sobrenome: ");
    fgets(professor.sobrenome, MAX_NOME, stdin);
    removerNovaLinha(professor.sobrenome);

    printf("Sexo M ou F: ");
    scanf(" %c",&(professor.sexo));
    getchar();

    printf("CPF(Somente n�meros): ");
    scanf("%d",&(professor.cpf));
    getchar();

    printf("Idade: ");
    scanf("%d",&(professor.idade));
    getchar();

    printf("Data de nascimento (yyyy mm dd): ");
    scanf("%d %d %d", &(professor.nascimento.dia), &(professor.nascimento.mes), &(professor.nascimento.ano));
    getchar(); // Consumir o newline deixado por scanf

    return professor;

}
void imprimirAlunos(tipo_aluno aluno[], int quantidade) {

    for (int i = 0; i < quantidade; i++)
    {
        printf("Nome: %s %s\n", aluno[i].nome, aluno[i].sobrenome);
        printf("Idade: %d\n", aluno[i].idade);
        printf("Sexo: %c\n", aluno[i].sexo);
        printf("Matricula: %d\n", aluno[i].matricula);
        printf("Turma: %c\n", aluno[i].turma);
        printf("Data de nascimento: %02d/%02d/%04d\n\n", aluno[i].nascimento.dia, aluno[i].nascimento.mes, aluno[i].nascimento.ano);
    }

}
void imprimirProfessores(tipo_professor professor[], int quantidade) {

    for (int i = 0; i < quantidade; i++)
    {
        printf("Nome: %s %s\n", professor[i].nome, professor[i].sobrenome);
        printf("Idade: %d\n", professor[i].idade);
        printf("Sexo: %c\n", professor[i].sexo);
        printf("CPF: %d\n", professor[i].cpf);
        printf("Data de nascimento: %02d/%02d/%04d\n\n", professor[i].nascimento.dia, professor[i].nascimento.mes, professor[i].nascimento.ano);
    }

}

void imprimirDisciplinas(tipo_disciplina disciplina[], int quantidade) {

    for (int i = 0; i < quantidade; i++)
    {
        printf("C�digo: %d\n", disciplina[i].codigo);
        printf("Nome: %s\n", disciplina[i].nome);
        printf("Carga: %dh\n", disciplina[i].carga_horaria);
    }

}
void VerificarDisponibilidade (int qtd){

    if (qtd == 0)
    {
        printf("N�o temos vagas para cadastro.");
        sleep(5);
        return;
    }
}
float calcular_media(float nota1, float nota2) {
    return (nota1 + nota2) / 2;
}
void RegistrarNotas(tipo_notas notas[], int *quantidade_notas,tipo_aluno alunos[], tipo_disciplina disciplinas[], int quantidade_aluno, int quantidade_disciplina) {
    int escolha = 0;
    tipo_notas nova_nota;

    limparTerminal();
    printf("Vai registrar quantas notas?\n\n");

    while (1) {
        printf("-------------------------------------\n");
        printf("|       1 - Uma nota                |\n");
        printf("|       2 - Duas notas              |\n");
        printf("-------------------------------------\n");
        printf("Escolha uma op��o: ");
        
        if (scanf("%d", &escolha) != 1) {
            while (getchar() != '\n'); // Limpar o buffer de entrada
            limparTerminal();
            printf("Entrada inv�lida! Por favor, escolha 1 ou 2.\n");
            continue;
        }  
        if (escolha >= 1 && escolha <= 2) {
            break;
        } else {
            limparTerminal();
            printf("Op��o inv�lida! Por favor, escolha 1 ou 2.\n");
        }
    }
    getchar();
    limparTerminal();

    switch (escolha) {
        case 2:
            printf("Aluno: ");
            fgets(nova_nota.nome_aluno, MAX_NOME, stdin);
            removerNovaLinha(nova_nota.nome_aluno);

            int aluno_existe = 0;
            for (int i = 0; i < quantidade_aluno; i++) {
                if (strcmp(nova_nota.nome_aluno, alunos[i].nome) == 0) {
                    aluno_existe = 1;
                    break;
                }
            }
            if (!aluno_existe) {
                printf("Esse aluno n�o existe na base de dados.\n");
                sleep(5);
                return;
            }

            printf("Disciplina: ");
            fgets(nova_nota.nome_disciplina, MAX_NOME, stdin);
            removerNovaLinha(nova_nota.nome_disciplina);

            int disciplina_existe = 0;
            for (int i = 0; i < quantidade_disciplina; i++) {
                if (strcmp(nova_nota.nome_disciplina, disciplinas[i].nome) == 0) {
                    disciplina_existe = 1;
                    break;
                }
            }
            if (!disciplina_existe) {
                printf("Essa disciplina n�o existe na base de dados.\n");
                sleep(5);
                return;
            }

            printf("Digite a primeira nota: ");
            scanf("%f", &nova_nota.nota1);
            getchar(); // Limpar o buffer de entrada

            printf("Digite a segunda nota: ");
            scanf("%f", &nova_nota.nota2);
            getchar(); // Limpar o buffer de entrada

        break;

        case 1:
            escolha = 0;
            printf("Vai registrar a primeira ou a segunda nota?\n\n");

            while (1) {
                printf("-------------------------------------\n");
                printf("|       1 - Primeira                |\n");
                printf("|       2 - Segunda                 |\n");
                printf("-------------------------------------\n");
                printf("Escolha uma op��o: ");
                
                if (scanf("%d", &escolha) != 1) {
                    while (getchar() != '\n'); // Limpar o buffer de entrada
                    limparTerminal();
                    printf("Entrada inv�lida! Por favor, escolha 1 ou 2.\n");
                    continue;
                }        
                if (escolha >= 1 && escolha <= 2) {
                    break;
                } else {
                    limparTerminal();
                    printf("Op��o inv�lida! Por favor, escolha 1 ou 2.\n");
                }
            }
                getchar();

                printf("Aluno: ");
                fgets(nova_nota.nome_aluno, MAX_NOME, stdin);
                removerNovaLinha(nova_nota.nome_aluno);

                aluno_existe = 0;
                for (int i = 0; i < quantidade_aluno; i++) {
                    if (strcmp(nova_nota.nome_aluno, alunos[i].nome) == 0) {
                        aluno_existe = 1;
                        break;
                    }
                }
                if (!aluno_existe) {
                    printf("Esse aluno n�o existe na base de dados.\n");
                    sleep(5);
                    return;
                }

                printf("Disciplina: ");
                fgets(nova_nota.nome_disciplina, MAX_NOME, stdin);
                removerNovaLinha(nova_nota.nome_disciplina);

                disciplina_existe = 0;
                for (int i = 0; i < quantidade_disciplina; i++) {
                    if (strcmp(nova_nota.nome_disciplina, disciplinas[i].nome) == 0) {
                        disciplina_existe = 1;
                        break;
                    }
                }
                if (!disciplina_existe) {
                    printf("Essa disciplina n�o existe na base de dados.\n");
                    sleep(5);
                    return;
                }
                if (escolha == 1) {
                    printf("Digite a primeira nota: ");
                    scanf("%f", &nova_nota.nota1);
                    getchar(); // Limpar o buffer de entrada
                } else {
                    printf("Digite a segunda nota: ");
                    scanf("%f", &nova_nota.nota2);
                    getchar(); // Limpar o buffer de entrada
                }
         break;
    }
    notas[*quantidade_notas] = nova_nota;
    (*quantidade_notas)++;
}

void imprimir_notas_por_aluno(tipo_notas notas[]) {
    limparTerminal();
    for (int i = 0; i < quantidade_notas; i++) {
        printf("Aluno: %s\n\n", notas[i].nome_aluno);
        printf(" Disciplina: %s\n", notas[i].nome_disciplina);
        printf(" Nota 1: %.2f\n", notas[i].nota1);
        printf(" Nota 2: %.2f\n", notas[i].nota2);
        printf(" M�dia: %.2f\n\n", calcular_media(notas[i].nota1, notas[i].nota2));
    }

}
void imprimir_alunos_reprovados(tipo_notas notas[]){
    limparTerminal();
    for (int i = 0; i < quantidade_notas; i++) {
        if(calcular_media(notas[i].nota1, notas[i].nota2) < 7){
            printf("Aluno: %s\n\n", notas[i].nome_aluno);
            printf(" Disciplina: %s\n", notas[i].nome_disciplina);
            printf(" M�dia: %.2f\n\n", calcular_media(notas[i].nota1, notas[i].nota2));
        }
    }
    printf("N�o temos alunos reprovados ainda....\n\n");
}

void gerar_relatorio_alunos_notas(tipo_notas notas[], tipo_aluno alunos[]) {
    limparTerminal();
    for (int i = 0; i < quantidade_aluno; i++) {
        printf("Aluno: %s %s\n", alunos[i].nome, alunos[i].sobrenome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Sexo: %c\n", alunos[i].sexo);
        printf("Nascimento: %02d/%02d/%04d\n", alunos[i].nascimento.dia, alunos[i].nascimento.mes, alunos[i].nascimento.ano);
        printf("Turma: %c\n", alunos[i].turma);
        printf("Matr�cula: %d\n", alunos[i].matricula);
        bool encontrou = false;
        for (int j = 0; j < quantidade_notas; j++) {
            if (strcmp(notas[j].nome_aluno, alunos[i].nome) == 0) {
                printf("  Disciplina: %s\n", notas[j].nome_disciplina);
                printf("  Nota 1: %.2f\n", notas[j].nota1);
                printf("  Nota 2: %.2f\n", notas[j].nota2);
                printf("  M�dia: %.2f\n", calcular_media(notas[j].nota1, notas[j].nota2));
                encontrou = true;
            }
        }
        if (!encontrou) {
            printf("  Nenhuma nota encontrada.\n");
        }
        printf("\n");
    }

}
void 
VerificarSeTemNotas(int quantidade_notas){
    if(quantidade_notas == 0){
        limparTerminal();
        printf("Sem notas registradas no sistema.");
        sleep(4);
        main();
    }
}
int main()
{
    limparTerminal();
    setlocale(LC_ALL, "Portuguese"); // Definindo localiza��o para uso de acentua��o.
    printf("Seja bem vindo ao nosso sistema de gerenciamento de alunos.\n");
    printf("O que deseja fazer agora?\n");
    menu_principal();
    switch (escolha){
        case 1: //Op��o de cadastro
            
            limparTerminal();
            printf("�timo, vamos dar inicio ao processo de cadastro.\n\n");

            printf("Por onde gostaria de come�ar?\n\n");
            menu_cadastro();
            switch (escolha){
                case 1: //op��o de cadastro de aluno

                    quantidade = 0;
                    
                    limparTerminal();
                    int qtd_disponivel_aluno = MAX_ALUNO - quantidade_aluno; //Calculando disponibilidade de cadastro
                    VerificarDisponibilidade(qtd_disponivel_aluno);
                    printf("�timo, vamos dar inicio ao processo de cadastro de aluno.\n\n");
                    printf("No momento, temos %d vaga(s).\n\n",qtd_disponivel_aluno);

                    while (1) {

                        printf("Quantos alunos ser�o cadastrados?\n");
                        
                        if (scanf("%d", &quantidade) != 1) {
                            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
                            while (getchar() != '\n');
                            limparTerminal();
                            printf("Entrada inv�lida!\n");
                            printf("Por favor, escolha um n�mero entre 1 e %d.\n", qtd_disponivel_aluno);
                            continue;
                        }
                        if (quantidade >= 1 && quantidade <= qtd_disponivel_aluno) {
                            // Saindo do loop se a escolha for v�lida
                            break;
                        } else {
                            limparTerminal();
                            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e %d.\n", qtd_disponivel_aluno);
                        }
                    }
                    getchar();
                    printf("Que �timo, vamos dar inicio ao processo\n\n");
                    for (int i = 0; i < quantidade; i++){

                        alunos[i] = AdicionarAluno();
                        quantidade_aluno ++; 
                        printf("\n\n");
                        
                    }
                    limparTerminal();
                    printf("\nCadastro(s) finalizado(s) com sucesso."); 
                    sleep(2);                   
                    limparTerminal();           
                    menu_retorna(); 
                    switch (escolha){
                        case 1:
                            limparTerminal();
                            main();
                        break;
                        case 2:
                            printf("Encerrando programa...");
                            exit(0);
                        break;
                    }
                    
                break;
                case 2: //op��o de cadastro de professor

                    quantidade = 0;

                    limparTerminal();
                    int qtd_disponivel_professor = MAX_PROFESSOR - quantidade_professor; 
                    VerificarDisponibilidade(qtd_disponivel_professor);
                    printf("�timo, vamos dar inicio ao processo de cadastro de professores.\n\n");
                    printf("No momento, temos %d vaga(s).\n\n",qtd_disponivel_professor);

                    while (1) {

                        printf("Quantos professores ser�o cadastrados?\n");
                        
                        if (scanf("%d", &quantidade) != 1) {
                            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
                            while (getchar() != '\n');
                            limparTerminal();
                            printf("Entrada inv�lida!\n");
                            printf("Por favor, escolha um n�mero entre 1 e %d.\n", qtd_disponivel_professor);
                            continue;
                        }                
                        if (quantidade >= 1 && quantidade <= qtd_disponivel_professor) {
                            // Saindo do loop se a escolha for v�lida
                            break;
                        } else {
                            limparTerminal();
                            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e %d.\n", qtd_disponivel_professor);
                        }
                    }
                    getchar();
                    printf("Que �timo, vamos dar inicio ao processo\n\n");
                    for (int i = 0; i < quantidade; i++){

                        professores[i] = AdicionarProfessor(); 
                        quantidade_professor ++; 
                        printf("\n\n");
                        
                    }
                    limparTerminal();
                    printf("\nCadastro(s) finalizado(s) com sucesso."); 
                    sleep(2); // Pausa por 2 segundos
                    limparTerminal(); //Limpando terminal
                    menu_retorna(); 
                    switch (escolha){
                        case 1:
                            limparTerminal();
                            main();
                        break;
                        case 2:
                            printf("Encerrando programa...");
                            exit(0);
                        break;
                    }
                break;
                case 3: //op��o de cadastro de disciplina

                    quantidade = 0;
                    limparTerminal();
                    int qtd_disponivel_disciplina = MAX_DISCIPLINA - quantidade_disciplina; 
                    VerificarDisponibilidade(qtd_disponivel_disciplina);
                    printf("�timo, vamos dar inicio ao processo de cadastro de disciplina.\n\n");
                    printf("No momento, temos %d vaga(s).\n\n",qtd_disponivel_disciplina);
                    while (1) {
                        printf("Quantas disciplinas ser�o cadastradas?\n");
                        
                        if (scanf("%d", &quantidade) != 1) {
                            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
                            while (getchar() != '\n');
                            limparTerminal();
                            printf("Entrada inv�lida!\n");
                            printf("Por favor, escolha um n�mero entre 1 e %d.\n", qtd_disponivel_disciplina);
                            continue;
                        }                  
                        if (quantidade >= 1 && quantidade <= qtd_disponivel_disciplina) {
                            // Saindo do loop se a escolha for v�lida
                            break;
                        } else {
                            limparTerminal();
                            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e %d.\n", qtd_disponivel_disciplina);
                        }
                    }
                    getchar();
                    printf("Que �timo, vamos dar inicio ao processo\n\n");
                    for (int i = 0; i < quantidade; i++){

                        disciplinas[i] = AdicionarDisciplina(); 
                        quantidade_disciplina ++; 
                        printf("\n\n");
                        
                    }
                    limparTerminal();
                    printf("\nCadastro(s) finalizado(s) com sucesso."); 
                    sleep(2); 
                    limparTerminal(); 
                    menu_retorna(); 
                    switch (escolha){
                        case 1:
                            limparTerminal();
                            main();
                        break;
                        case 2:
                            printf("Encerrando programa...");
                            exit(0);
                        break;
                    }
                break;
                case 4: //op��o de sair
                    limparTerminal();
                    printf("At� logo...\n\n");
                    exit(0);//encerrando o programa com status de sucesso.
                break;
            }
        break;
        case 2: //Informa��es de aluno

            limparTerminal();
            printf("�timo, vamos dar inicio ao processo.\n\n");
            printf("Por onde gostaria de come�ar?\n\n");
            menu_info_alunos();

            switch (escolha){
                case 1: //registro de notas
                    quantidade = 0;
                    int qtd_disponivel_notas = MAX_NOTAS - quantidade_notas; //Calculando disponibilidade de cadastro
                    VerificarDisponibilidade(qtd_disponivel_notas);
                    if (quantidade_aluno == 0 || quantidade_disciplina == 0){

                        printf("Vi que n�o temos alunos ou disciplinas cadastrados no sistema....\n");
                        printf("Cadastre no minimo 1 aluno e 1 disciplina para habilitar as op��es.\n");
                        sleep(5);
                        limparTerminal();
                        main();
                    } 
                    limparTerminal();
                    printf("Show de bola! Vamos registrar as notas.\n\n");

                    while (1) {
                        printf("Vai registrar notas em quantos alunos?\n");                
                        if (scanf("%d", &quantidade) != 1) {
                            // Limpar o buffer de entrada caso a entrada n�o seja um n�mero v�lido
                            while (getchar() != '\n');
                            limparTerminal();
                            printf("Entrada inv�lida!\n");
                            printf("Por favor, escolha um n�mero entre 1 e %d.\n", MAX_ALUNO);
                            continue;
                        }                 
                        if (quantidade >= 1 && quantidade <= MAX_ALUNO) {
                            // Saindo do loop se a escolha for v�lida
                            break;
                        } else {
                            limparTerminal();
                            printf("Op��o inv�lida! Por favor, escolha um n�mero entre 1 e %d.\n", MAX_ALUNO);
                        }
                    }
                    getchar();
                    printf("Que �timo, vamos dar inicio ao processo\n\n");
                    for (int i = 0; i < quantidade; i++){

                        RegistrarNotas(notas_alunos,&quantidade_notas,alunos,disciplinas,quantidade_aluno,quantidade_disciplina); 
                        printf("\n\n");
                        
                    }
                    limparTerminal();
                    printf("\nCadastro(s) finalizado(s) com sucesso."); 
                    sleep(2);      
                    limparTerminal(); 
                    menu_retorna(); 
                    switch (escolha){
                        case 1:
                            limparTerminal();
                            main();
                        break;
                        case 2:
                            printf("Encerrando programa...");
                            exit(0);
                        break;
                    }
                break;
                case 2: //Notas por aluno
                    limparTerminal();
                    VerificarSeTemNotas(quantidade_notas);
                    imprimir_notas_por_aluno(notas_alunos);
                    sleep(4);  
                    printf("\n\n");    
                    menu_retorna(); 
                    switch (escolha){
                        case 1:
                            limparTerminal();
                            main();
                        break;
                        case 2:
                            printf("Encerrando programa...");
                            exit(0);
                        break;
                    }
                break;
                case 3://alunos reprovados
                    limparTerminal();
                    imprimir_alunos_reprovados(notas_alunos);
                    sleep(4);    
                    menu_retorna(); 
                    switch (escolha){
                        case 1:
                            limparTerminal();
                            main();
                        break;
                        case 2:
                            printf("Encerrando programa...");
                            exit(0);
                        break;
                    }
                break;
                case 4: //op��o de sair
                    limparTerminal();
                    printf("At� logo...\n\n");
                    exit(0);
                break;
            }
        break;
        case 3: //Gerar relat�rios
            limparTerminal();
            menu_relatorios();
            switch (escolha){
                case 1:
                    VerificarSeTemNotas(quantidade_notas);
                    gerar_relatorio_alunos_notas(notas_alunos,alunos);
                    sleep(4); 
                    menu_retorna(); 
                    switch (escolha){
                        case 1:
                            limparTerminal();
                            main();
                        break;
                        case 2:
                            printf("Encerrando programa...");
                            exit(0);
                        break;
                    }
                break;
                case 2:

                break;
            }
        break;
        case 4: //Sair
            printf("Encerrando programa...");
            exit(0);
        break;
    }
    return 0;
}