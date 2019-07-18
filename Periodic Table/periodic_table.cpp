#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>


void mainwin(void);

struct element{
                 int atomicno;
                 char sym[5];
                 char name[50];
                 char ec[50];
                 int group;
                 int period;
                 char block;
                 float atomicw;
                 float en;
                 int atomicr;
                 float meltp;
                 float boilp;
                 float density;
              }elem;


int main()
{
    int i,no,found=0;
    char a,d,k,nam[20];
    FILE *fp;
    system("COLOR 8e");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t***Modern Periodic Table***");
    Sleep(3000);
    for(i=0;i<=100;i=i+10)
    {
        system("cls");
        printf("\n\n\n\t\t\t\t\t\t*****Welcome*****");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tLOADING %d%%...",i);
        Sleep(500);
    }
    mainwin();
    system("pause");
    lb2:
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tWhat would you like to do");
    Sleep(300);
    printf("\n\n\n\t\t\t1. Search An Element.");
    Sleep(200);
    printf("\n\n\n\t\t\t2. Add A New Element.");
    Sleep(200);
    printf("\n\n\n\t\t\t3. View Periodic Table.");
    Sleep(200);
    printf("\n\n\n\n\n\t\t\t\t\tEnter Your Choice...  ");
    a=getch();
    switch (a)
    {
        case '1':
            system("cls");
            printf("\n\n\n\n\t\t\t\t1. Search Element By Atomic Number.");
            Sleep(300);
            printf("\n\n\n\t\t\t\t2. Search Element By Name.");
            Sleep(300);
            printf("\n\n\n\t\tEnter Your Choice... ");
            k=getch();
            if (k=='1')
            {
                system("cls");
                fp=fopen("element.dll","r");
                if (fp==NULL)
                {
                    printf("File is not opened successfully...");
                    exit(0);
                }
                printf("\n\n\n\n\t\t\t\tEnter Atomic Number: ");
                scanf("%d",&no);
                while(fread(&elem,sizeof(elem),1,fp)==1)
                {
                    if(no==elem.atomicno)
                    {
                        found=1;
                        printf("\n\n\n\t\t\t\t***Detail Of The Element***");
                        printf("\n\n\n\t\t\tName: %s",elem.name);
                        printf("\n\t\t\tSymbol: %s",elem.sym);
                        printf("\n\t\t\tAtomic Num: %d",elem.atomicno);
                        printf("\n\t\t\tElectronic Config: %s",elem.ec);
                        printf("\n\t\t\tBlock: %c",elem.block);
                        printf("\n\t\t\tGroup: %d",elem.group);
                        printf("\n\t\t\tPeriod: %d",elem.period);
                        printf("\n\t\t\tAtomic Weight: %.2f",elem.atomicw);
                        printf("\n\t\t\tAtomic Radius: %d pm",elem.atomicr);
                        printf("\n\t\t\tElectronegativity: %.2f (Pauling Scale)",elem.en);
                        printf("\n\t\t\tMelting Point: %.2f K",elem.meltp);
                        printf("\n\t\t\tBoiling Point: %.2f K",elem.boilp);
                        printf("\n\t\t\tDensity: %.5f g/cm3\n\n",elem.density);
                        printf("\a");
                        system("pause");
                        fclose(fp);
                        break;
                    }
                }

                fflush(stdin);
                if (found==0)
                    printf("\n\n\n\n\t\t\t\tNo element found of entered atomic number...\n\n\n");
                goto lb3;
            }

            else if (k=='2')
            {
                system("cls");
                fp=fopen("element.dll","r");
                if (fp==NULL)
                {
                    printf("File is not opened successfully...");
                    exit(0);
                }
                printf("\n\n\n\n\t\t\t\tEnter Element Name (capitalize first letter): ");
                scanf("%s",&nam);
                while(fread(&elem,sizeof(elem),1,fp)==1)
                {
                    if(strcmp(nam,elem.name)==0)
                    {
                        found=1;
                        printf("\n\n\n\t\t\t\t***Detail Of The Element***");
                        printf("\n\n\n\t\t\tName: %s",elem.name);
                        printf("\n\t\t\tSymbol: %s",elem.sym);
                        printf("\n\t\t\tAtomic Num: %d",elem.atomicno);
                        printf("\n\t\t\tElectronic Config: %s",elem.ec);
                        printf("\n\t\t\tBlock: %c",elem.block);
                        printf("\n\t\t\tGroup: %d",elem.group);
                        printf("\n\t\t\tPeriod: %d",elem.period);
                        printf("\n\t\t\tAtomic Weight: %.3f",elem.atomicw);
                        printf("\n\t\t\tAtomic Radius: %d pm",elem.atomicr);
                        printf("\n\t\t\tElectronegativity: %.3f (Pauling Scale)",elem.en);
                        printf("\n\t\t\tMelting Point: %.3f K",elem.meltp);
                        printf("\n\t\t\tBoiling Point: %.3f K",elem.boilp);
                        printf("\n\t\t\tDensity: %.5f g/cm3\n\n",elem.density);
                        printf(" \a");
                        system("pause");
                        fclose(fp);
                        break;
                    }
                }
                fflush(stdin);
                if (found==0)
                    printf("\n\n\n\n\t\t\t\tNo element found of entered name...\n\n\n");
                goto lb3;
            }

            else
            {
                system("cls");
                printf("\n\n\n\n\t\t\t\tNot a valid choice...\n\n\n");
                system("pause");
                goto lb2;
            }

            break;

        case '2':
            system("cls");
            fp=fopen("element.dll","a");
            if (fp==NULL)
            {
                printf("File is not opened successfully...");
                exit(0);
            }
            printf("\n\n\t\t\t\t\tEnter The Detail Of Element...");
            printf("\n\n\t\t\t\tName: ");
            scanf(" %[^\n]",&elem.name);
            printf("\t\t\t\tSymbol: ");
            scanf(" %s",&elem.sym);
            printf("\t\t\t\tAtomic Num: ");
            scanf(" %d",&elem.atomicno);
            printf("\t\t\t\tElectronic Config: ");
            scanf(" %[^\n]",elem.ec);
            printf("\t\t\t\tBlock: ");
            scanf(" %c",&elem.block);
            printf("\t\t\t\tGroup: ");
            scanf(" %d",&elem.group);
            printf("\t\t\t\tPeriod: ");
            scanf(" %d",&elem.period);
            printf("\t\t\t\tAtomic Weight: ");
            scanf(" %f",&elem.atomicw);
            printf("\t\t\t\tAtomic Radius: ");
            scanf(" %d",&elem.atomicr);
            printf("\t\t\t\tElectronegativity: ");
            scanf(" %f",&elem.en);
            printf("\t\t\t\tMelting Point: ");
            scanf(" %f",&elem.meltp);
            printf("\t\t\t\tBoiling Point: ");
            scanf(" %f",&elem.boilp);
            printf("\t\t\t\tDensity: ");
            scanf(" %f",&elem.density);
            fwrite(&elem,sizeof(elem),1,fp);
            printf("\n\t\t\tData of element added successfully...");
            fclose(fp);
            goto lb3;
            break;

        case '3':
            mainwin();
            lb3:
            printf("\n\n\t\t\t\t\tWould You Like To Continue (Y/N)... ");
            d=getch();
            if (d=='y'||d=='Y')
                goto lb2;
            else if (d=='n'||d=='N')
            {
                system("cls");
                printf("\n\n\n\n\t\t\t\t\tThank You!");
                printf("\n\n\n\n\t\t\t\t\tPress Any Key To Exit...");
                getch();
                exit(0);
            }
            else
            {
                system("cls");
                printf("\n\n\n\n\t\t\t\t\tNot a valid choice...\n\n\n");
                system("pause");
                goto lb3;
            }
            break;

        default:
            system("cls");
            printf("\n\n\n\n\t\t\t\tNot a valid choice...\n\n\n");
            system("pause");
            goto lb2;
    }


}

void mainwin()
{
    system("cls");
    printf("\n\t\t\tTHE MODERN PERIODIC TABLE\n");
    printf("\t\t\t-------------------------\n");
    printf("\tH                                                      He\n\n");
    printf("\tLi Be                                 B  C   N  O   F  Ne\n\n");
    printf("\tNa Mg                                 Al Si  P  S   Cl Ar\n\n");
    printf("\tK  Ca Sc Ti V  Cr Mn Fe Co Ni Cu  Zn  Ga Ge  As Se  Br Kr\n\n");
    printf("\tRb Sr Y  Zr Nb Mo Tc Ru Rh Pd Ag  Cd  In Sn  Sb Te  I  Xe\n\n");
    printf("\tCs Ba La Hf Ta W  Re Os Ir Pt Au  Hg  Tl Pb  Bi Po  At Rn\n\n");
    printf("\tFr Ra Ac Rf Db Sg Bh Hs Mt Ds Uuu Uub -  Uuq -  Uuh\n\n\n");
    printf("\t\t Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu\n\n");
    printf("\t\t Th Pa U  Np Pu Am Cm Bk Cf Es Fm Md No Lr\n\n\n");
}
