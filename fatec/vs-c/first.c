#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//toda linha deve ser terminada com ";"!!

//função que não retornam resultado podem ser declaradas como VOID
//caso a função retornar resultado, o VOID precisa ser alterado para o tipo da variavel de retorno (Int, Char, Double, Float...)
void func(int a,char b[]){
    printf("Teste de função: %d e \'%s\'",a,b);
}

int func_2(int a, int b){
    a = a + b;
    return a;
}

//Zera buffer do Scanf() já que ele recebe o ENTER como caracter ASCII
void flush_in(){
    int ch;
    while((ch=fgetc(stdin)) !=EOF && ch != '\n') {}
}

void calc(char op){
        //declaração de variaveis
        float a = 0,b = 0;
        //solicitação de inputs
        printf("Digite primeiro número:");
        scanf("%f",&a);
        flush_in();
        //há operações que somente pedem 1 input
        if (op != 'p' && op != 'c' && op != 'f'){
            printf("Digite segundo número:");
            scanf("%f",&b);
            flush_in();}
      //seleção com base no input de operação
        switch (op)
        {
        //soma simples
        case '+':
            printf("\nSoma de a = %.2f e b = %.2f é %.2f:",a,b,a+b);
            break;
        //substração simples
        case '-':
            printf("\nSubtração de a = %.2f e b = %.2f é %.2f:",a,b,a-b);
            break;
        //multiplicação simples        
        case '*':
            printf("\nMultiplicação de a = %.2f e b = %.2f é %.2f:",a,b,a*b);
            break;
        //divisão simples
        case '/':
            (b==0) ? printf("\nSegundo número não pode ser 0!") : printf("\nDivisão de a = %.2f e b = %.2f é %.2f:",a,b,a/b);
            break;
        //MOD para saber se resultado é 0, logo par.
        case 'p':
            ((int)a % 2 == 0) ? printf("\nNumero %.2f é Par!",a) : printf("\nNumero %.2f é Impar!",a);
            break;
        case 'c':
            printf("\nCº em Fº é: %.4f",(a*1.8)+32);
            break; 
        case 'f':
            printf("\nFº em Cº é: %.4f",(a-32)/1.8);
            break;                                     
        default:
            break;
        }//fim do switch
}

int main(){

    //HelloWorld por que não né?
    printf("Hello World!");

    //variaveis devem ser declaradas TIPO e NOME, em sequência INICIALIZADAS
    //short int entre -32.768 a +32.767
    //unsigned short int entre 0 e 65.535
        //UNSIGNED variavel retira a parte negativa numérica de alocação de memória
    //int entre -2.147.483.648 e 2.147.483.647
    int x = 1; //inteiro inicializado com valor 1
    float y = 2.1; //tipo decimal
    char w = 'a'; //um simples caracter deve ser usado o '' 
    char nome[25] = "Eu Mesmo"; //um texto deve ser do tipo array "[]" e usar ""
    const short int a = 1;
    char algoai[25];

    //demonstrando variaveis deve-se usar uma ancora declarado por "%"+sigla exe:
    //siglas:
    //%c = para string simples
    //%s = para string complexa
    //%f = para pontos flutuantes decimais até 7 casas decimais
    //%lf = para pontos flutuantes decimais até 16 casas decimais
    //%d = usado ara Integer ou Char(tabela ASCII)

    //const = constant em C; CONST <tipo> <variavel>
    printf("Variavel X = %d, variavel Y = %f, variável W = %c e variavel Nome = %s \n",x,y,w,nome);

    //scanf() para coletar dados de usuários, porém se String possui espaço em branco irá bugar
    //para usar o scanf() necessário declarar o tipo de variável entre "" seguido por ",&<variavel>" ; o "&" endereça na memória
    //scanf() precisa ser zerado a buffer para próximo uso
    printf("Digita algo ai:");
    scanf("%s",&w);
    flush_in();
    printf("Digitou: %c",w);

    //fgets() é usado para capturar informação
    //exemplo para coletar uma string com 25 caracteres, STDIN = standart input 
    //fgets() recebe naturalmente um "\n" (quebra de linha)
    //flush_in zera buffer do scan() para o fgets() funfar
    printf("\nDigita algo ai, denovo:");
    fgets(algoai,25,stdin);
    //com inclusão da biblioteca STRING.H é possível retirar o "\n" (quebra de linha) do fgets() com comando abaixo na variavel de destino da STRING
    algoai[strlen(algoai)-1] = '\0';
    printf("\nDigitou: %s",algoai);

    //IF trabalha igual PHP
    printf("\nPara \'If\'");
    if(w == 'a'){
        printf("\na = %c",w);
    }else{
        printf("\na <> %c",w);
    }

    //SWITCH trabalha igual a DAX
    printf("\nPara \'Switch\'");   
    switch (w)
    {
    case 'a':
        printf("\na = %c",w);
        break;
    case 'b':
        printf("\na <> %c",w);
    default:
        printf("\n yep! ");
        break;
    }

    printf("\nChamando primeira função: ");
    func(x,algoai);

    printf("\nChamando segunda função: ");
    printf("%d",func_2(2,3));


    //FOR() é o loop padrão executa enquanto uma condição for verdade
    printf("\nLoop FOR");
    for(int i=1;i <= 10;i+=3){
        printf("\n%d",i);
    }

    //While e Do..While
    //While verifica primeiro condição de verdade antes de rodar o loop, e o faz enquanto a condição for verdade
    //Do...While executa o while ao menos uma vez
    printf("\nLoop WHILE"); 
    while (x <= 10)
    {
        printf(" %d",x);
        x+=3;
    }

    printf("\nLoop DO...WHILE");
    //reiniciando variavel
    x=1;

    do
    {
        printf(" %d",x);
        x+=3;
    } while (x <= 10);
    
    //velha e boa calculadora
    //variaveis de operacao e saida do loop
    char op;
    char opt[]="+-/*pcf";
    do
    {
    //lista de opções
     printf("\n\nDigite Operação a ser realizada");
     printf("\n\'+\' para adição");
     printf("\n\'-\' para subtração"); 
     printf("\n\'*\' para multiplicação"); 
     printf("\n\'/\' para divisão");
     printf("\n\'p\' para saber se é Par");
     printf("\n\'c\' para converter de Celcius para Fahrenheit");
     printf("\n\'f\' para converter de Fahrenheit para Celcius");              
     printf("\n\'s\' para sair! \nOperação: ");
     scanf("%c",&op);
     flush_in();
    
    //bool iniciada como falso para opção
    bool vf = false;

    //for() para verificar se opção está dentro de disponíveis
    for(int i=0;i<strlen(opt);i++){
        if(op == opt[i]){vf=true;}
        }

    //if para chamada de função de calculo ou erro em opção
    if(vf == true)
         //chamada de função de calculo
        {calc(op);}
        else if (op != 's'){
            printf("\nOpção inválida!");
        }

    } while (op != 's');

    printf("\n");
    return 0;

}