 /***********************
 * Aluna: Beatriz Matias
 * Matricula: 2019107651
 * Exercicios 2
***********************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define NUM_MAX 100

typedef struct aluno{
    char* nome; 
    int matricula; 
    float p1, p2, p3;
} Aluno;

Aluno * cria_alunos (void);
Aluno ** carrega_turma (int qtd);
void imprime_aluno (Aluno*);
void imprime_turma (int, Aluno **);
void imprime_aprovados (int n, Aluno** turma);
float media_turma (int n, Aluno** turma);
void libera_aluno (Aluno *);
void libera_turma (int n, Aluno **);

int main () {
    Aluno ** turma;
    int qtdAlunos = 0;

    printf("Quantos alunos tem?\n");
    scanf(" %d%*c", &qtdAlunos);

    turma = carrega_turma(qtdAlunos);
    // system("clear");
    imprime_turma(qtdAlunos, turma);
    imprime_aprovados(qtdAlunos, turma);

    float mediaTurma;

    mediaTurma = media_turma(qtdAlunos, turma);
    printf ("\n\nMédia total: %.2f\n", mediaTurma);

    libera_turma(qtdAlunos, turma);
    return 0;
}

/*
  * Funcao auxiliar para a leitura dos nome dos alunos
  * Entrada: void
  * Saida: char*
  */
char * aux_nome (void) {
    char nomeAux [NUM_MAX], *nome;
    int tam;
    
    printf("Digite o nome do aluno:\n");
    scanf ("%[^\n]%*c", nomeAux);
    tam = strlen(nomeAux) + 1;

    nome = (char *) malloc (sizeof(char) * tam);
    strcpy(nome, nomeAux);

    return nome;
}

/*
  * Funcao para leitura de aluno
  * Entrada: void
  * Saida: Aluno*
  */
Aluno * cria_alunos (void) {
    Aluno * aluno;
    int matricula;
    float p1, p2, p3;

    aluno = (Aluno *) malloc  (sizeof(Aluno));
    aluno->nome = aux_nome();

    printf ("Digite a matrícula\n");
    scanf ("%d%*c", &matricula);

    printf ("Digite a nota das 3 provas:\n");
    scanf ("%f%f%f%*c", &p1,
                                              &p2,
                                              &p3);

    aluno->matricula = matricula;
    aluno->p1 = p1;
    aluno->p2 = p2;
    aluno->p3 = p3;

    return aluno;
}

/*
  * Funcao para a criacao da turma
  * Entrada: int
  * Saida: Aluno**
  */
Aluno ** carrega_turma (int qtd) {
    Aluno ** turma;

    turma = (Aluno **) malloc (sizeof(Aluno) * qtd);

    /*
     *  Deixei a criacao de alunos nesta funcao para facilitar a criacao da turma.
     * Porem, outra forma de fazer seria adicionar um aluno ja criado ha uma turma 
     * ja existente.
    */
    for (int i = 0; i < qtd; i++) {
        turma[i] = cria_alunos();
    }

    return turma; 
}

/*
  * Funcao auxiliar para apresentar o nome do aluno
  * Entrada: Aluno*
  * Saida: void
  */
void aux_imprime_nome(Aluno * aluno) {
    printf ("Aluno(a): %s\n", aluno->nome);
}
/*
  * Funcao para apresentar as informacoes do aluno
  * Entrada: Aluno*
  * Saida: void
  */
void imprime_aluno (Aluno* aluno) {
    printf ("\nInformações do aluno:\n");
    aux_imprime_nome(aluno);
    printf ("Matricula: %d\n", aluno->matricula);
    printf("P1: %.2f, P2: %.2f, P3: %.2f\n\n", aluno->p1, aluno->p2, aluno->p3);
}

/*
  * Funcao para apresentar todos da turma
  * Entrada: int, Aluno*
  * Saida: void
  */
void imprime_turma (int n, Aluno ** turma) {
    for(int i = 0; i < n; i++) {
        imprime_aluno(turma[i]);
    }
}

/*
  * Funcao auxiliar para o calculo da media das provas de um aluno
  * Entrada: Aluno*
  * Saida: float
  */
float aux_media (Aluno* aluno) {
    float media;
    media = aluno->p1 + aluno->p2 + aluno->p3;
    media /= 3;

    return media;
}

/*
  * Funcao auxiliar que analisa se a media eh igual ou acima de 5 (aprovado) ou se eh menor que 5 (reprovado)
  * Entrada: Aluno*
  * Saida: int
  */
int aux_aprovado(Aluno* aluno) {
    float media;
    media = aux_media(aluno);

    if (media >= 5) 
        return 1;
    return 0;
}

/*
  * Funcao apresentar a informacao dos alunos aprovados (media igual ou acima de 5)
  * Entrada: int, Aluno**
  * Saida: void
  */
void imprime_aprovados (int n, Aluno** turma) {
    
    printf ("\nAlunos aprovados:\n\n");

    for (int i = 0; i < n; i++) {
        if(aux_aprovado (turma[i]) ) 
            imprime_aluno (turma[i]);
    }
}

/*
  * Funcao que retorna a media geral dos alunos da turma
  * Entrada: int, Aluno**
  * Saida: float
  */
float media_turma(int n, Aluno** turma) {
    float media = 0;

    for(int i = 0; i < n; i++) {
        media += aux_media(turma[i]);
    }

    media /= n;
    return media;
}

/*
  * Funcao para liberar o espaco alocado para o aluno
  * Entrada: Aluno*
  * Saida: void
  */
void libera_aluno (Aluno * aluno)  {
    free(aluno->nome);
    free(aluno);
}

/*
  * Funcao para liberar o espaco alocado  pela turma e os alunos dela
  * Entrada: Aluno*
  * Saida: void
  */
void libera_turma(int n, Aluno ** turma) {
    /*
     *  Deixei a liberacao de espaco de alunos nesta funcao.
     *  Se os alunos fossem separados da turma, a liberacao deles nao estaria incluida nesta funcao.
    */
    for(int i = 0; i < n; i++) {
        libera_aluno(turma[i]);
    }

    free(turma);
}

