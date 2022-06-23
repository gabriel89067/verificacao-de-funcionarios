#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(int argc, char *argv[]){
int x,y,b,parametro2,numdfun;
char parametro1[100],parametro3[100];
char nomealfa[100][30], copiaalfa[100];
char nomealfaDEP[100][30], copiaalfaDEP[100];
int i, j;
 char arquivo1[20],arquivo2[20],operacao[20],arquivo3[3][20];



 strcpy(arquivo1,argv[1]);
 arquivo2[0] = *argv[2];

 FILE *arq;
  arq = fopen(arquivo1,"r+");
  if(arq == NULL){
    printf("erro na abertura do arquivo\n");
    exit(1);
}
 int anoold ,anopadrao ,mesold,dep[1000],auxdep;
int mespadrao ,diaold ,printdata;
int anooldDEP,anopadraoDEP,mesoldDEP,mespadraoDEP,diaoldDEP,printdataDEP;
float somasalarial,mediasalarial;
int auxmed,med[1000];
float somasalarialDEP,mediasalarialDEP;

struct data{
   int dia;
   int mes;
   int ano;
};
struct lista{

  char nome[50];
  float salario;
  struct data d;
  char departamento[50];
}funcionario[1000];





 if(arquivo2[0] == '1'){   //Exportar Lista de Funcionarios  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 FILE *param3;
  param3 = fopen(argv[3],"w+");
  if(param3 == NULL){
    printf("erro na abertura do arquivo\n");
    exit(3);
}
 fscanf(arq,"%i\n",&numdfun);
x=0;
while ( (fgets(funcionario[x].nome,50,arq))
       &&(fscanf(arq,"%f",&funcionario[x].salario))
       &&(fscanf(arq,"%d/%d/%d",&funcionario[x].d.dia,&funcionario[x].d.mes,&funcionario[x].d.ano))
       &&(fscanf(arq,"%s\n",&funcionario[x].departamento))!= EOF){
x++;
}
 for(x=0;x<numdfun;x++){
  strcpy(nomealfa[x],funcionario[x].nome);
  }

for ( i = 0; i < (numdfun - 1) ; i ++ )
   for( j = i + 1; j < numdfun; j ++ )
if ( strcmp( nomealfa[i], nomealfa[j] ) > 0 ){
         strcpy ( copiaalfa, nomealfa[i] );
         strcpy( nomealfa[i], nomealfa[j] );
         strcpy( nomealfa[j], copiaalfa) ;}


for(y=0;y<numdfun;y++){
      for(x=0;x<numdfun;x++){
            if(strcmp(funcionario[y].nome,nomealfa[x])==0){
                fprintf(param3,"%s",funcionario[x].nome);
                fprintf(param3,"%.2f\n",funcionario[x].salario);
            if(funcionario[x].d.dia < 10){
                   fprintf(param3,"0%d/",funcionario[x].d.dia);
                }else{
                fprintf(param3,"%d/",funcionario[x].d.dia);}
            if(funcionario[x].d.mes < 10){
                fprintf(param3,"0%d/",funcionario[x].d.mes);
                  }else{
                    fprintf(param3,"%d/",funcionario[x].d.mes);}
                fprintf(param3,"%d\n",funcionario[x].d.ano);
                fprintf(param3,"%s\n",funcionario[x].departamento);}
    }}
fclose(param3);
fclose(arq);
                        }//Exportar Lista de Funcionarios  ####### PARADA ######



 if(arquivo2[0] == '2'){ //Listar Funcionarios por Departamento//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


 fscanf(arq,"%i\n",&numdfun);
x=0;
while ( (fgets(funcionario[x].nome,50,arq))
       &&(fscanf(arq,"%f",&funcionario[x].salario))
       &&(fscanf(arq,"%d/%d/%d",&funcionario[x].d.dia,&funcionario[x].d.mes,&funcionario[x].d.ano))
       &&(fscanf(arq,"%s\n",&funcionario[x].departamento))!= EOF){
x++;
}
 for(x=0;x<numdfun;x++){
  strcpy(nomealfaDEP[x],funcionario[x].nome);
  }


for ( i = 0; i < (numdfun - 1) ; i ++ )
   for( j = i + 1; j < numdfun; j ++ )
if ( strcmp( nomealfaDEP[i], nomealfaDEP[j] ) > 0 ){
         strcpy ( copiaalfaDEP, nomealfaDEP[i] );
         strcpy( nomealfaDEP[i], nomealfaDEP[j] );
         strcpy( nomealfaDEP[j], copiaalfaDEP) ;}



for(y=0;y<numdfun;y++){
      for(x=0;x<numdfun;x++){
            if(strcmp(funcionario[x].nome,nomealfaDEP[y])==0){
               if(strcmp(funcionario[x].departamento,argv[3])==0){
                printf("%s",funcionario[x].nome);
                printf("%0.2f\n",funcionario[x].salario);
                if(funcionario[x].d.dia < 10){
                   printf("0%d/",funcionario[x].d.dia);
                  }else{
                   printf("%d/",funcionario[x].d.dia);}
                 if(funcionario[x].d.mes < 10){
                 printf("0%d/",funcionario[x].d.mes);
                    }else{
                    printf("%d/",funcionario[x].d.mes);}
                    printf("%d\n",funcionario[x].d.ano);
                    printf("%s\n",funcionario[x].departamento);}}}}


fclose(arq);
                     }//Listar Funcionarios por Departamento ####### PARADA ######



if(arquivo2[0] == '3'){//Encontrar Funcion�ario Mais Antigo//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  fscanf(arq,"%i\n",&numdfun);
x=0;
while ( (fgets(funcionario[x].nome,50,arq))
       &&(fscanf(arq,"%f",&funcionario[x].salario))
       &&(fscanf(arq,"%d/%d/%d",&funcionario[x].d.dia,&funcionario[x].d.mes,&funcionario[x].d.ano))
       &&(fscanf(arq,"%s\n",&funcionario[x].departamento))!= EOF){
x++;
}

 fclose(arq);

            anoold = funcionario[0].d.ano;



                for(x=1;x<numdfun;x++){//mostra qual o ano menor(mais antigo)
                    if(funcionario[x].d.ano < anoold){
                    anoold = funcionario[x].d.ano;
                    if(funcionario[x].d.ano == anoold){//se caso existir dois ou mais anos menores passa o ano padrao
                        anopadrao = anoold;
                     }}}

                  mesold = 1000;
                for(x=0;x<numdfun;x++){//
                    if(funcionario[x].d.ano == anoold){//a partir do ano padrao puxamos os meses menores
                          if(funcionario[x].d.mes < mesold){
                           mesold = funcionario[x].d.mes;
                            }}}

                     diaold = 100000;
                    for(x=0;x<numdfun;x++){//mostra a partir do mes paddrao qual o menor ddia
                     if(funcionario[x].d.mes == mesold){
                          if(funcionario[x].d.dia < diaold){
                          diaold = funcionario[x].d.dia;//caso afirmativo printf assume o numero do funcionario
                          printdata = x;
                          }}}
                printf("%s",funcionario[printdata].nome);//depois imprime todos os daddo ddo funcionario
                printf("%.2f\n",funcionario[printdata].salario);
                if(funcionario[printdata].d.dia < 10){
                   printf("0%d/",funcionario[printdata].d.dia);
                  }else{
                   printf("%d/",funcionario[printdata].d.dia);}
                 if(funcionario[printdata].d.mes < 10){
                 printf("0%d/",funcionario[printdata].d.mes);
                    }else{
                    printf("%d/",funcionario[printdata].d.mes);}
                printf("%d\n",funcionario[printdata].d.ano);
                printf("%s\n",funcionario[printdata].departamento);
fclose(arq);
                              }//Encontrar Funcion�ario Mais Antigo ####### PARADA ######


if(arquivo2[0] == '4'){ //Encontrar Funcion�ario Mais Antigo do Departamento //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



  fscanf(arq,"%i\n",&numdfun);
x=0;
while ( (fgets(funcionario[x].nome,50,arq))
       &&(fscanf(arq,"%f",&funcionario[x].salario))
       &&(fscanf(arq,"%d/%d/%d",&funcionario[x].d.dia,&funcionario[x].d.mes,&funcionario[x].d.ano))
       &&(fscanf(arq,"%s\n",&funcionario[x].departamento))!= EOF){
x++;
}

         for(x=0;x<numdfun;x++){//acha quais funcionarios pertecem a esse ddepartamento
            if (strcmp(funcionario[x].departamento,argv[3]) == 0){
            dep[auxdep] = x;
            auxdep++;
            }}
            anooldDEP = funcionario[dep[0]].d.ano;


            for(x=0;x<auxdep;x++){//mostra qual o ano menor(mais antigo)
                    if(funcionario[dep[x]].d.ano < anooldDEP){
                    anooldDEP = funcionario[dep[x]].d.ano;
                    if(funcionario[dep[x]].d.ano == anooldDEP){//se caso existir dois ou mais anos menores passa o ano padrao
                        anopadraoDEP = anooldDEP;
                     }}}

                  mesoldDEP = 1000;
                for(x=0;x<auxdep;x++){//
                    if(funcionario[dep[x]].d.ano == anooldDEP){//a partir do ano padrao puxamos os meses menores
                          if(funcionario[dep[x]].d.mes < mesoldDEP){
                           mesoldDEP = funcionario[dep[x]].d.mes;
                            }}}
                     diaoldDEP = 100000;
                    for(x=0;x<auxdep;x++){//mostra a partir do mes paddrao qual o menor ddia
                     if(funcionario[dep[x]].d.mes == mesoldDEP){
                          if(funcionario[dep[x]].d.dia < diaoldDEP){
                          diaoldDEP = funcionario[dep[x]].d.dia;//caso afirmativo printf assume o numero do funcionario
                          printdataDEP = dep[x];
                          }}}
                printf("%s",funcionario[printdataDEP].nome);//depois imprime todos os daddo ddo funcionario
                printf("%.2f\n",funcionario[printdataDEP].salario);
                if(funcionario[printdataDEP].d.dia < 10){
                   printf("0%d/",funcionario[printdataDEP].d.dia);
                   }else{
                    printf("%d/",funcionario[printdataDEP].d.dia);}
                if(funcionario[printdataDEP].d.mes < 10){
                   printf("0%d/",funcionario[printdataDEP].d.mes);
                   }else{
                   printf("%d/",funcionario[printdataDEP].d.mes);}
                printf("%d\n",funcionario[printdataDEP].d.ano);
                printf("%s\n",funcionario[printdataDEP].departamento);
                                            fclose(arq);
                                             }//Encontrar Funcion�ario Mais Antigo do Departamento ####### PARADA ######




if(arquivo2[0] == '5'){//Calcular M�edia Salarial//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  fscanf(arq,"%i\n",&numdfun);
x=0;
while ( (fgets(funcionario[x].nome,50,arq))
       &&(fscanf(arq,"%f",&funcionario[x].salario))
       &&(fscanf(arq,"%d/%d/%d",&funcionario[x].d.dia,&funcionario[x].d.mes,&funcionario[x].d.ano))
       &&(fscanf(arq,"%s\n",&funcionario[x].departamento))!= EOF){
x++;
}
  for(x=0;x<numdfun;x++){
    somasalarial += funcionario[x].salario;
    }
  mediasalarial = somasalarial/numdfun;
printf("%0.2f\n",mediasalarial);
fclose(arq);
                            }//Calcular M�edia Salarial ####### PARADA ######




if(arquivo2[0] == '6'){//Calcular M�edia Salarial por Departamento //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  strcpy(argv[3],argv[3]);

  fscanf(arq,"%i\n",&numdfun);
x=0;
while ( (fgets(funcionario[x].nome,50,arq))
       &&(fscanf(arq,"%f",&funcionario[x].salario))
       &&(fscanf(arq,"%d/%d/%d",&funcionario[x].d.dia,&funcionario[x].d.mes,&funcionario[x].d.ano))
       &&(fscanf(arq,"%s\n",&funcionario[x].departamento))!= EOF){
x++;
}
 auxmed=0;
   for(x=0;x<numdfun;x++){//acha quais funcionarios pertecem a esse departamento
            if (strcmp(funcionario[x].departamento,argv[3]) == 0){
            med[auxmed] = x;
            auxmed++;
            }}

  for(x=0;x<auxmed;x++){
    somasalarialDEP += funcionario[med[x]].salario;
    }
  mediasalarialDEP = somasalarialDEP/auxmed;
printf("%0.2f\n",mediasalarialDEP);



fclose(arq);

//Calcular M�edia Salarial por Departamento  ####### PARADA ######


  }
system("pause");










return 0;
}
