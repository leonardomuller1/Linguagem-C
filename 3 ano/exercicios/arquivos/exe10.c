#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas vezes cada letra do alfabeto aparece dentro do arquivo.
 */
int main(void)
{
    FILE *file;
    char arquivo[100];
    printf("Localizacao do arquivo:");
    fgets(arquivo, sizeof(arquivo), stdin);
    arquivo[strcspn(arquivo, "\n")] = '\0';
    strcat(arquivo, ".txt");

    char texto[4000];
    int q=0,w=0,e=0,r=0,t=0,y=0,u=0,i=0,o=0,p=0,a=0,s=0,d=0,f=0,g=0,h=0,j=0,k=0,l=0,z=0,x=0,c=0,v=0,b=0,n=0,m=0;

    file = fopen(arquivo, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    while (fgets(texto, sizeof(texto), file))
    {
        for (int index = 0; index < strlen(texto); index++)
        {
            char letra = tolower(texto[index]);// deixando tudo minuscula
            if (letra == 'q')
            {
                q++;
            }else if(letra == 'w'){
                w++;
            }else if(letra == 'e'){
                e++;
            }else if(letra == 'r'){
                r++;
            }else if(letra == 't'){
                t++;
            }else if(letra == 'y'){
                y++;
            }else if(letra == 'u'){
                u++;
            }else if(letra == 'i'){
                i++;
            }else if(letra == 'o'){
                o++;
            }else if(letra == 'p'){
                p++;
            }else if(letra == 'a'){
                a++;
            }else if(letra == 's'){
                s++;
            }else if(letra == 'd'){
                d++;
            }else if(letra == 'f'){
                f++;
            }else if(letra == 'g'){
                g++;
            }else if(letra == 'h'){
                h++;
            }else if(letra == 'j'){
                j++;
            }else if(letra == 'k'){
                k++;
            }else if(letra == 'l'){
                l++;
            }else if(letra == 'z'){
                z++;
            }else if(letra == 'x'){
                x++;
            }else if(letra == 'c'){
                c++;
            }else if(letra == 'v'){
                v++;
            }else if(letra == 'b'){
                b++;
            }else if(letra == 'n'){
                n++;
            }else if(letra == 'm'){
                m++;
            }
        }
    }

    printf("A letra A tem : %i\n",a);
    printf("A letra B tem : %i\n",b);
    printf("A letra C tem : %i\n",c);
    printf("A letra D tem : %i\n",d);
    printf("A letra E tem : %i\n",e);
    printf("A letra F tem : %i\n",f);
    printf("A letra G tem : %i\n",g);
    printf("A letra H tem : %i\n",h);
    printf("A letra I tem : %i\n",i);
    printf("A letra J tem : %i\n",j);
    printf("A letra K tem : %i\n",k);
    printf("A letra L tem : %i\n",l);
    printf("A letra M tem : %i\n",m);
    printf("A letra N tem : %i\n",n);
    printf("A letra O tem : %i\n",o);
    printf("A letra P tem : %i\n",p);
    printf("A letra Q tem : %i\n",q);
    printf("A letra R tem : %i\n",r);
    printf("A letra S tem : %i\n",s);
    printf("A letra T tem : %i\n",t);
    printf("A letra U tem : %i\n",u);
    printf("A letra V tem : %i\n",v);
    printf("A letra W tem : %i\n",w);
    printf("A letra X tem : %i\n",x);
    printf("A letra Y tem : %i\n",y);
    printf("A letra Z tem : %i\n",z);

    fclose(file);

    return 0;
}
