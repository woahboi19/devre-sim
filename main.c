#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char hchar[10], lchar[10];
char girisCikis[1][2];
int degeri[10];
char giris1[10], giris2[10], giris3[10], giris4[10], giris5[10];
int degerGiris[10];
char cikis1[10], cikis2[10], cikis3[10], cikis4[10];
int j,k;
char array[200][20];
int i=0;
char arrayY[1000];
FILE *logdosya;

void devreYukle()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  devre.txt sisteme yuklendi.\n",  tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("devre.txt","r");
    i=0;
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%c",&arrayY[i]);
            if(!feof(file))
                printf("%c",arrayY[i]);
            i++;
        }
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);

    FILE *file2;
    file2=fopen("devre.txt","r");
    if(file2!=NULL)
    {

        while(!feof(file2))
        {
            fscanf(file,"%s",&array[i]);
            //printf("%s ",array[i]);
            i++;
        }
    }
    else
        printf("Dosya bulunamadi!");


    fclose(file);
    printf("\n\n");

    printf("Devreye girisler :");
    for(j=0; j<i-1; j++)
    {
        if(strcmp(array[j],".giris")==0)
        {
            if(strcmp(array[j+1],"#girisler")!=0)
            {

                strcpy(giris1,array[j+1]);
                printf("%s  ",giris1);
            }
            else
                break;
            if(strcmp(array[j+2],"#girisler")!=0)
            {
                strcpy(giris2,array[j+2]);
                printf("%s  ",giris2);
            }
            else
                break;
            if(strcmp(array[j+3],"#girisler")!=0)
            {
                strcpy(giris3,array[j+3]);
                printf("%s  ",giris3);
            }
            else
                break;
            if(strcmp(array[j+4],"#girisler")!=0)
            {
                strcpy(giris4,array[j+4]);
                printf("%s  ",giris4);
            }
            else
                break;
            if(strcmp(array[j+5],"#girisler")!=0)
            {
                strcpy(giris5,array[j+5]);
                printf("%s  ",giris5);
            }
            else
                break;
        }
    }
    printf("\n");
    printf("Devreden cikislar : ");
    for(j=0; j<i-1; j++)
    {
        if(strcmp(array[j],".cikis")==0)
        {
            if(strcmp(array[j+1],"#cikis")!=0)
            {
                strcpy(cikis1,array[j+1]);
                printf("%s  ",cikis1);
            }
            else
                break;
            if(strcmp(array[j+2],"#cikis")!=0)
            {
                strcpy(cikis2,array[j+2]);
                printf("%s  ",cikis2);
            }
            else
                break;
            if(strcmp(array[j+3],"#cikis")!=0)
            {
                strcpy(cikis3,array[j+3]);
                printf("%s  ",cikis3);
            }
            else
                break;
            if(strcmp(array[j+4],"#cikis")!=0)
            {
                strcpy(cikis4,array[j+4]);
                printf("%s  ",cikis4);
            }
            else
                break;
        }
    }
    printf("\n");
    for(j=0; j<i-1; j++)
    {
        if(strcmp(array[j],".kapi")==0)
        {
            {
                printf("%s kapisinin : ",array[j+1]);
                printf("%s girisi var, ",array[j+2]);
                printf(" cikisi  %s, ",array[j+3]);
                printf("girisleri %s   %s, ",array[j+4], array[j+5]);
                printf("gecikme suresi %s. ",array[j+6]);
            }
            printf("\n");
        }
    }
    return 0;
}

void devreIliklendir()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  Degerler sisteme yuklendi.\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        printf("\n");
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            degerGiris[i]=degeri[i];
            if(!feof(file))
            {
                printf("%s ucuna  %d degeri atandi.\n",girisCikis[i],degeri[i]);
            }
            i++;

        }
        printf("\n");
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);
}

void yukselt()
{
    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            if(!feof(file))
            {
                printf("%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;
        }
        printf("Degerini yukseltmek istediginiz girisi seciniz : ");
        printf("\n> ");
        scanf("%s",&hchar);
        if(strcmp(girisCikis[0],hchar)==0 && degeri[0]==0)
        {
            degeri[0]=1;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  a'nin degeri 0 dan 1 e duzeltildi.\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[1],hchar)==0 && degeri[1]==0)
        {
            degeri[1]=1;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  b'nin degeri 0 dan 1 e duzeltildi. \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[2],hchar)==0 && degeri[2]==0)
        {
            degeri[2]=1;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  c'nin degeri 0 dan 1 e duzeltildi. \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[3],hchar)==0 && degeri[3]==0)
        {
            degeri[3]=1;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  d'nin degeri 0 dan 1 e duzeltildi. \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[4],hchar)==0 && degeri[4]==0)
        {
            degeri[4]=1;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  e'nin degeri 0 dan 1 e duzeltildi. \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[5],hchar)==0 && degeri[5]==0)
        {
            degeri[5]=1;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  a'nin degeri 0 dan 1 e duzeltildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);


    FILE *file2;
    file2=fopen("deger.txt","w");
    int j;
    if(file!=NULL)
    {
        for(j=0; j<6; j++)
        {
            printf("%s   %d\n",girisCikis[j],degeri[j]);
            fprintf(file2,"%s   %d\n",girisCikis[j],degeri[j]);
        }
    }
    else
    {
        printf("Dosya bulunamadi!");
    }

    fclose(file);
}

void alcalt()
{
    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            if(!feof(file))
            {
                printf("%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;
        }
        printf("Degerini alcaltmak istediginiz girisi seciniz : ");
        printf("\n\n> ");
        scanf("%s",&lchar);
        if(strcmp(girisCikis[0],lchar)==0 && degeri[0]==1)
        {
            degeri[0]=0;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  a'nin degeri 1 den 0 a duzeltildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[1],lchar)==0 && degeri[1]==1)
        {
            degeri[1]=0;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  b'nin degeri 1 den 0 a duzeltildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[2],lchar)==0 && degeri[2]==1)
        {
            degeri[2]=0;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  c'nin degeri 1 den 0 a duzeltildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[3],lchar)==0 && degeri[3]==1)
        {
            degeri[3]=0;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  d'nin degeri 1 den 0 a duzeltildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

       if(strcmp(girisCikis[4],lchar)==0 && degeri[4]==1)
        {
            degeri[4]=0;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  e'nin degeri 1 den 0 a duzeltildi.\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

        if(strcmp(girisCikis[5],lchar)==0 && degeri[5]==1)
        {
            degeri[5]=0;
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  f'nin degeri 1 den 0 a duzeltildi. \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
        }

    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);


    FILE *file2;
    file2=fopen("deger.txt","w");
    int j;
    if(file!=NULL)
    {
        for(j=0; j<6; j++)
        {
            printf("%s   %d\n",girisCikis[j],degeri[j]);
            fprintf(file2,"%s   %d\n",girisCikis[j],degeri[j]);
        }
    }
    else
    {
        printf("Dosya bulunamadi!");
    }

    fclose(file);
}

void simuleEt()
{
    printf("S komutu alindi\n");
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  Devre simule edildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);
}

void ilgilia()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  a ucu ve degeri konsolda gosterildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            if(i==0)
            {
                printf("\n%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;

        }
        printf("\n");
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);
}
void ilgilib()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  b ucu ve degeri konsolda gosterildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            if(i==1)
            {
                printf("\n%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;

        }
        printf("\n");
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);
}
void ilgilic()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d c ucu ve degeri konsolda gosterildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
   if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            if(i==2)
            {
                printf("\n%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;

        }
        printf("\n");
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);
}
void ilgilid()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  d ucu ve degeri konsolda gosterildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            if(i==3)
            {
                printf("\n%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;

        }
        printf("\n");
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);
}
void ilgilie()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  e ucu ve degeri konsolda gosterildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            if(i==4)
            {
                printf("\n%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;

        }
        printf("\n");
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);
}
void ilgilif()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  e ucu ve degeri konsolda gosterildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            if(i==5)
            {
                printf("\n%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;

        }
        printf("\n");
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);
}

void tumUclar()
{
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  Tum uclar ve degerleri konsolda gosterildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);

    FILE *file;
    file=fopen("deger.txt","r");
    int i=0;
    if(file!=NULL)
    {
        printf("\n");
        while(!feof(file))
        {
            fscanf(file,"%s%d",&girisCikis[i],&degeri[i]);
            degerGiris[i]=degeri[i];
            if(!feof(file))
            {
                printf("%s   %d\n",girisCikis[i],degeri[i]);
            }
            i++;

        }
        printf("\n");
    }
    else
    {
        printf("Dosya bulunamadi!");
    }
    fclose(file);
}

void komutlar()
{
    printf("K komutu alindi\n");
    logdosya=fopen("log.txt","a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(logdosya,"%d-%d-%d %d:%d:%d  K komutu alindi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(logdosya);
}


int main()
{
    int dondur;
    char komut[15], Y1[2]="Y", I2[2]="I", H3[2]="H", L4[2]="L", S5[2]="S", G6[2]="G", G7[3]="G*", K8[2]="K", C9[2]="C";
    char Y11[2]="y", I22[2]="i", H33[2]="h", L44[2]="l", S55[2]="s", G66[2]="g", G77[3]="g*", K88[2]="k", C99[2]="c";
    char ga[3]="ga", gb[3]="gb", gc[3]="gc", gd[3]="gd", ge[3]="ge", gf[3]="gf";
    char ga1[3]="Ga", gb1[3]="Gb", gc1[3]="Gc", gd1[3]="Gd", ge1[3]="Ge", gf1[3]="Gf";
    do
    {
        dondur=0;  // bunu yapmazsak yanlis komut girdigimizde hata veriyor.
        printf("\n> ");
        gets(komut);
        if(strcmp(Y1,komut)==0 || strcmp(Y11,komut)==0)
            dondur=1;
        else if(strcmp(I2,komut)==0 || strcmp(I22,komut)==0)
            dondur=2;
        else if(strcmp(H3,komut)==0 || strcmp(H33,komut)==0)
            dondur=3;
        else if(strcmp(L4,komut)==0 || strcmp(L44,komut)==0)
            dondur=4;
        else if(strcmp(S5,komut)==0 || strcmp(S55,komut)==0)
            dondur=5;
        else if(strcmp(ga,komut)==0 || strcmp(ga1,komut)==0)
            dondur=61;
        else if(strcmp(gb,komut)==0 || strcmp(gb1,komut)==0)
            dondur=62;
        else if(strcmp(gc,komut)==0 || strcmp(gc1,komut)==0)
            dondur=63;
        else if(strcmp(gd,komut)==0 || strcmp(gd1,komut)==0)
            dondur=64;
        else if(strcmp(ge,komut)==0 || strcmp(ge1,komut)==0)
            dondur=65;
        else if(strcmp(gf,komut)==0 || strcmp(gf1,komut)==0)
            dondur=66;
        else if(strcmp(G7,komut)==0 || strcmp(G77,komut)==0)
            dondur=7;
        else if(strcmp(K8,komut)==0 || strcmp(K88,komut)==0)
            dondur=8;
        else if(strcmp(C9,komut)==0 || strcmp(C99,komut)==0)
            dondur=9;
        // else
        //printf("Yanlis komut girdiniz tekrar komut giriniz!\n");

        switch(dondur)
        {
        case 1:
            devreYukle();
            // (Y) devre.txt yukle
            break;
        case 2:
            devreIliklendir();
            // (I) deger.txt iliklendir
            break;
        case 3:
            yukselt();
            // (H) yukselt 0->1
            break;
        case 4:
            alcalt();
            // (L) alcalt 1->0
            break;
        case 5:
            simuleEt();
            // (S) simule eder
            break;
        case 61:
            ilgilia();
            // (Ga) ilgili uclaryn degerlerini konsolda gosterir
            break;
        case 62:
            ilgilib();
            // (Gb) ilgili uclaryn degerlerini konsolda gosterir
            break;
        case 63:
            ilgilic();
            // (Gc) ilgili uclaryn degerlerini konsolda gosterir
            break;
        case 64:
            ilgilid();
            // (Gd) ilgili uclaryn degerlerini konsolda gosterir
            break;
        case 65:
            ilgilie();
            // (Ge) ilgili uclaryn degerlerini konsolda gosterir
            break;
        case 66:
            ilgilif();
            // (Gf) ilgili uclaryn degerlerini konsolda gosterir
            break;
        case 7:
            tumUclar();
            break;
        case 8:
            komutlar();
            // (K) komut.txt uygular
            break;
        case 9:
        {
            printf("Programdan cikis yaptiniz.");
            logdosya=fopen("log.txt","a");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            fprintf(logdosya,"%d-%d-%d %d:%d:%d  Sistemden cikis yapildi.  \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fclose(logdosya);
            // (C) cikar
        }

        break;
        default:
            break;
        }
    }
    while(dondur!=9);

    return 0;
}
