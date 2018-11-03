#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef struct 
	{
		char Nompac[34];int numsocial;int edad;float estatura;float peso;char diagnostico[45672];char fecha[34];char fechas[87];char medico[45];char medicomparte[67];
	}pacientes;
pacientes *pac;
typedef struct{char nombre[56];int telefono;char login[67];char pasword[87];char cedula[98];
}medicos;
medicos *ARRdin;

int menumed(int *opci);void verconsultas(char name[30]);void altapac(pacientes *pac, int *conta);void alta(medicos *med, int *conta);void menu(char *opcion);
void creararchivo(char NOM[30]);void muestraarchivo(char NOM[30]);void creararchivopac(char name[56]);
void altapac(pacientes *pac, int *contra);void menu_usocompartido(char *res);void verconsultas_nocompartidas();
int conta(int *be,char NOM[30]);int busqueda_login(char NOM[30],int *resp);int busqueda_pasword(char NOM[30],int *NUM);int conta_pa(int *fe,char NOMB[56]);
void buscar_pacientes(char na[56]);void mostrar_pa(char na[56]);int menumodificar(int *te);void modificar_3(char NUme[56]);void eric(char pe[56]);
void copiar (char nuce[56]);
FILE *A;FILE *B;FILE *aux; FILE *C;
char name[56]="paciente.txt";char NOMBRE[30]="agenda.txt";
int b,x=0;int d,y=0;
/*Funcion principal*/
int main(void)
{
	char opc;
	char nomarc[67];
	int op,cont=0,opcd=0,bum,bam;x=conta(&b,NOMBRE);
	printf("             *********  BIENVENIDO A HOSPITAL BUAP   *********\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");system("pause");	
	creararchivo(NOMBRE);
	creararchivopac(name);
	do
		{
			system("cls");
			menu(&opc);
			switch(opc)
			{
			case 'D':
				system("cls");printf("\n\n\n");
				printf("  ------------->DARSE DE ALTA COMO MEDICO<---------------\n\n");fflush(stdin);
				printf("Si desea continuar presione 1 de lo contrario presione 0 \n");fflush(stdin);scanf("%d",&op);
				if (op==1)
				{
					system("cls");
					printf("\n\n\n------->BIENVENIDO AL ALTA DE MEDICOS<--------\n\n\n\n");
					ARRdin=(medicos*)realloc(ARRdin,(cont+1)*sizeof(medicos));alta(&ARRdin[cont],&cont);fflush(stdin);
					A=fopen(NOMBRE,"ab");fwrite(&ARRdin[cont-1],sizeof(medicos),1,A);fclose(A);
				}
				else 
					{
						printf("----->  Usted ha decidido cancelar la operacion");
					}
				getchar();
				break;
			case 'I':
				system("cls");
				printf("\n\n\n\n\n");
				printf("                 ***********  BIENVENIDO AL SISTEMA  ***********\n\n");fflush(stdin);busqueda_login(NOMBRE,&bum);printf("\n\n");
				busqueda_pasword(NOMBRE,&bam);system("cls");printf("\n\n\n\n\nSE ESTA VERIFICANDO SU CUENTA ESPERE UN MOMENTO...\n\n\n\n\n");printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");system("pause");
				while(bum==0 && bam==0)
				{
					system("cls");menumed(&opcd);
					switch(opcd)
					{
					case 1:
						system("cls");fflush(stdin);
						pac=(pacientes*)realloc(pac,(cont+1)*sizeof(pacientes));
						C=fopen(nomarc,"wb");
						altapac(&pac[cont],&cont);/*FUNCION QUE REGRESA UNA ESTRUCTURA*/
							fflush(stdin);
							B=fopen(name,"ab");/*ABRIMOS ARCHIVO PARA METER LA ESTRUCTURA DE LAS CONSULTAS COMPARTIDAS*/
							fwrite(&pac[cont-1],sizeof(pacientes),1,B);/*ESCRIBIMOS LA ESTRUCTURA COMPARTIDA*/
							fclose(B);/*Cerramos archivo*/
							printf("SU CONSULTA HA SIDO GUARDADA\n");
						
						getchar();
						break;
					case 2:
						system("cls");fflush(stdin);buscar_pacientes(name);break;
					case 3:
						system("cls");
						fflush(stdin);
						eric(name);
						break;
					case 4:
							fflush(stdin); mostrar_pa(name);
						break;
					case 5:
						system("cls");
						printf("\n------>>>>>>>USTED HA DECIDIDO SALIR<<<<<<<<--------\n\n\n\n");
						printf("                    *********    HOSPITAL BUAP   *********\n\n\n\n");
						printf("                      Teléfono : +52 (222)  2  229 55 00\n");
						printf("                        Fax : +52 (222)  2  229  56  72\n");
						printf("                         Av.   San   Claudio  y 14 Sur\n");
						printf("                          Recepcion   Extension  7200\n");
						printf("                           Puebla,   Puebla.  México\n");
						printf("                            Ciudad    Universitaria\n");
						printf("                                  C.P. 72570\n");
						exit(1);
						break;
					} /*CIERRE DEL SWITCH*/
				}
				if(bum!=0 && bam!=0)
				{
					system("cls");
					printf("\n\n\n");
					printf("SU LOGIN Y PASWORD SON INCORRECTOS VUELVA A INTENTARLO...");
					getchar();
					
				}
				break;			
			case 'M':
				system("cls");fflush(stdin);muestraarchivo(NOMBRE);getchar();break;
			}/*CIERRE DEL SWITCH*/
		}/*CIERRE DEL DO*/
	while(opc!='S');
	return 0;
}
void creararchivo(char NOM[30])
{
	A=fopen(NOM,"rb");
	if (A==NULL)
	{
		A=fopen(NOM,"wb");
		fclose(A);
	}
	else
		{
			fclose(A);
		}
}
void creararchivopac(char name[56])
{
	B=fopen(name,"rb");
	if(B==NULL)
	{
		B=fopen(name,"wb");
		fclose(B);
	}
	else
		{
			fclose(B);
		}
}
void menu(char *opcion)
{
	printf("\n\n\n");
	printf("    ------  ELIJA UNA DE LAS SIGUIENTES OPCIONES------   \n\n\n\n\n\n");printf("D.-Darse de alta en el sistema:\n\n");printf("I.-Ingresar.\n\n");
	printf("M.-Ver medicos dados de alta\n\n");printf("S.-Salir");printf("                                              --> Opcion:");
	*opcion=toupper(getchar());
}
void alta(medicos *med, int *conta)
{
	char NomBre[34];char Logi[56];char pas[56];int i,nu;
	fflush(stdin);
	printf("Cual es su nombre:\n");
	gets(NomBre);
	for (i=0;i<strlen(NomBre);i++)
	{
		NomBre[i]=toupper(NomBre[i]);
	}
	strcpy((*med).nombre,NomBre);/*COPIA LA CADENA EN LA ESTRUCTURA*/
	fflush(stdin);printf("Proporcione su telefono:\n");fflush(stdin);scanf("%d",&(*med).telefono);
	printf("Proporcione su cedula profesional:\n");fflush(stdin);gets((*med).cedula);
	fflush(stdin);
	fflush(stdin);
	printf("Cual sera su login:\n");
	gets(Logi);
	for (i=0;i<strlen(Logi);i++)
	{
		Logi[i]=toupper(Logi[i]);
	}
	printf("VUELVA A ESCRIBIR SU LOGIN\n");
	fflush(stdin);busqueda_login(NOMBRE,&nu);
	if (nu!=0)
	{
		strcpy((*med).login,Logi);
	}	
	else
		{
			printf("NO SE PUEDE CONCLUIR DEBIDO AQUE YA EXISTE ESA LOGIN\n");
			exit(1);
		}
	printf("Su login si coincidio\n");
	fflush(stdin);
	printf("Cual sera su pasword\n");
	gets(pas);
	for (i=0;i<strlen(pas);i++)
	{
		pas[i]=toupper(pas[i]);
	}
	strcpy((*med).pasword,pas);
	*conta=(*conta)+1;printf("\n\n < Usted ha sido de alta ...>");
	getchar();fflush(stdin);fflush(stdin);
	
}	
int menumed(int *opci)
{
	printf("\n\n\n");
	printf("        -------->BIENVENIDO AL MENU PARA MEDICOS<---------\n\n\n\n"); printf("Seleccione una de las siguientes opciones:\n\n\n\n");
	printf("1.-Nueva consulta.\n\n");printf("2.-Buscar paciente\n\n");printf("3.-Modificar datos del paciente\n\n");
	printf("4.-Ver consultas\n\n");printf("5.-Salir\n\n");printf("                                              --> Opcion:");
	scanf("%d",&(*opci));return *opci;
}
void muestraarchivo(char NOM[30])	
{
	medicos MED;
	A=fopen(NOM,"rb");
	system("cls");
	printf("\n\n\n\n");
	printf("--------->>>>LOS MEDICOS DE ESTE HOSPITAL SON:<<<<-------\n\n\n\n\n");
	while (!feof(A))
	{
		if (  fread(&MED,sizeof(medicos),1,A) )
		{
			printf("NOmbre del medico:\n\n");puts(MED.nombre);printf("--------------------\n");	printf("Numero de telefono:\n\n");printf("%d\n",MED.telefono);
			printf("--------------------\n");printf("Cedula profesional:\n\n");puts(MED.cedula);printf("--------------------\n");	
		}
		printf("\n\n\n");
	}
	fclose(A);
}
void altapac(pacientes *pac, int *conta)
{
	char nombre[34];
	char login[56];
	char logincom[67];
	char cade[4];
	int i,b;
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];
	strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
	
	printf("\n\n                  BIENVENIDO AL ALTA DE PACIENTES:\n\n");fflush(stdin);printf("Cual es el nombre del paciente:\n");
	gets(nombre);
	for (i=0;i<strlen(nombre);i++)
	{
		nombre[i]=toupper(nombre[i]);
	}
	strcpy((*pac).Nompac,nombre);
	fflush(stdin);
	printf("Cual es el numero social del paciente:\n");fflush(stdin);	fgets(cade,5,stdin);b=atoi(cade);
	((*pac).numsocial)=b;
	printf("Proporcione la edad del paciente:\n");fflush(stdin);scanf("%d",&(*pac).edad);printf("Proporcione la estatura del paciente:\n");
	scanf("%f",&(*pac).estatura);printf("Proporcione el peso del paciente:\n");fflush(stdin);scanf("%f",&(*pac).peso);printf("Cual es su diagnostico medico:\n");
	fflush(stdin);gets((*pac).diagnostico);printf("Cual sera la fecha de la proxima cita.?\n");fflush(stdin);gets((*pac).fecha);strcpy((*pac).fechas,output);
	printf("Login del medico que consulto:\n");
	gets(login);
	for (i=0;i<strlen(login);i++)
	{
		login[i]=toupper(login[i]);
	}
	strcpy((*pac).medico,login);
	fflush(stdin);
	printf("Login del medico que podra tener acceso a ella(SI NO KIERES COMPARTIR SOLO DA ENTER)\n");fflush(stdin);
	gets(logincom);
	for (i=0;i<strlen(logincom);i++)
	{
		logincom[i]=toupper(logincom[i]);
	}
	strcpy((*pac).medicomparte,logincom);
	*conta=(*conta)+1;
	getchar();fflush(stdin);fflush(stdin);
}
int conta(int *be,char NOM[30])
{
	int bes=0;	
	medicos MED;
	A=fopen(NOM,"rb");
	if(A==NULL)
	{
		fclose(A);
	}
	else
		{
			system("cls");
			printf("\n\n\n\n");
			while (!feof(A))
			{
				if (  fread(&MED,sizeof(medicos),1,A) )
				{
					bes++;
				}
				printf("\n\n\n");
			}
			*be=bes;
			return *be;
			getchar();
			fclose(A);
		}
	return 0;
}
int busqueda_login(char NOM[30],int *resp)
{
	medicos MED;int i;char cad[34];A=fopen(NOM,"rb");
	fflush(stdin);
	printf("CUAL ES LA LOGIN:\n");
	gets(cad);
	
	for (i=0;i<strlen(cad);i++)
	{
		cad[i]=toupper(cad[i]);
	}
	while(!feof(A))
	{
		for(i=0;i<x+20;i++)
		{
			fread(&MED,sizeof(medicos),1,A);
			*resp=strcmp(MED.login,cad);
			if(*resp==0)
			{
				return *resp;
				break;
			}
		}
		if(*resp!=0)
		{
			return 3;
		}
	}
	return 0;
	fclose(A);
	getchar();	
}
int busqueda_pasword(char NOM[30],int *NUM)
{
	medicos MED;
	char cadena[34];int i=0;A=fopen(NOM,"rb");
	fflush(stdin);printf("CUAL ES SU PASWORD:\n");gets(cadena);
	for (i=0;i<strlen(cadena);i++)
	{
		cadena[i]=toupper(cadena[i]);
	}
	while(!feof(A))
	{
		for(i=0;i<x+20;i++)
		{
			if (fread(&MED,sizeof(medicos),1,A) )
			{
				*NUM=strcmp(MED.pasword,cadena);
				if(*NUM==0)
				{
					return *NUM;
					break;
				}
				else 
					{
						break;
					}
			}
		}
	}
	return 0;
	fclose(A);
}
void buscar_pacientes(char na[56])
{
	
	pacientes PAC;int d,i,j,f;char cade[34];
	
	char fer[56];
	y=conta_pa(&d,name);
	B=fopen(na,"rb");
	system("cls");fflush(stdin);
	printf("CUAl ES EL  NOMBRE DEL PACIENTE:\n");
	gets(cade);
	for(j = 0; cade[j]; j++) 
	{
		cade[j] = toupper(cade[j]);
	}
	fflush(stdin);
	printf("Cual es login:\n");
	gets(fer);
	for(j = 0; fer[j]; j++) 
	{
		fer[j] = toupper(fer[j]);
	}
	for(i=0;i<y;i++)
	{
		fread(&PAC,sizeof(pacientes),1,B);
		d=strcmp(fer,PAC.medico);
		b=strcmp(fer,PAC.medicomparte);
		if(d==0 || b==0)
		{
			f=strcmp(cade,PAC.Nompac);
			if(f==0)
			{
				system("cls");
				printf("\n\n\n EL PACIENTE QUE USTED BUSCO ES EL SIGUIENTE:\n\n\n");
				printf("Nombre del paciente:\n");printf("--------------------\n");	puts(PAC.Nompac);
				printf("\n");printf("Fecha de la consulta:\n");printf("--------------------\n");	puts(PAC.fechas);printf("\n");
				printf("Edad del paciente:\n");printf("--------------------\n");printf("%d\n",PAC.edad);
				printf("\n");printf("Numero del seguro social del paciente:\n");printf("--------------------\n");
				printf("%d\n",PAC.numsocial);printf("\n");printf("Estatura del paciente:\n");printf("--------------------\n");printf("%f\n",PAC.estatura);
				printf("\n");printf("Peso del paciente:\n");printf("--------------------\n");printf("%f\n",PAC.peso);printf("\n");printf("Diagnostico del paciente:\n");
				printf("--------------------\n");	puts(PAC.diagnostico);printf("\n");printf("Fecha de la proxima cita:\n");printf("--------------------\n");	
				puts(PAC.fecha);printf("\n");
				printf("Nombre del medico que consulto:\n");printf("--------------------\n");puts(PAC.medico);printf("\n");
				printf("Nombre del medico con el que es compartida esta consulta:\n");printf("--------------------\n");puts(PAC.medicomparte);printf("\n");
				getchar();
				
			}
		
	}
	}
	fclose(B);
}
int conta_pa(int *fe,char NOMB[56])
{
	int best=0;	pacientes M;
	B=fopen(NOMB,"rb");
	if(B==NULL)
	{
		fclose(B);
	}
	else
		{
			system("cls");printf("\n\n\n\n");
			while (!feof(B))
			{
				if (  fread(&M,sizeof(pacientes),1,B) )
				{
					best++;
				}
				printf("\n\n\n");
			}
			*fe=best;
			return *fe;
			getchar();
			fclose(B);
			
		}
	return 0;
}

int menu_modi( int *opcionmo)
{	
	int jk=0;
	system("cls");
	printf("BIENVENIDO ALA MODIFICACION DE ARCHIVOS\n\n");
	printf("Acontinuacion le daremos un menu de opciones para modificar:\n\n\n");
	printf("1.-Modificar nombre del paciente.\n\n");
	printf("2.-Modificar numero del seguro social.\n\n");
	printf("3.-Modificar la edad del paciente.\n\n");
	printf("4.-Modificar su peso.\n\n");
	printf("5.-modificar la estatura del paciente.\n\n");
	printf("6.-Modificar su diagnostico.\n\n");
	printf("7.-Modificar la fecha de su proxima consulta.\n\n");
	printf("8.-Modificar la login del medico que va a compartir.\n\n");
	scanf("%d",&jk);
	*opcionmo=jk;
	return *opcionmo;
}
void mostrar_pa(char na[56])
{

	pacientes PAC;int d,b,i,j;char cade[34];
	y=conta_pa(&d,name);
	B=fopen(na,"rb");
	system("cls");fflush(stdin);printf("Proporcione su login:\n");
	gets(cade);
	for(j = 0;cade[j];j++) 
	{
		cade[j] = toupper(cade[j]);
	}
	while(!feof(B))
	{
		for(i=0;i<=y;i++)
		{
		fread(&PAC,sizeof(pacientes),1,B);
		d=strcmp(cade,PAC.medico);
		b=strcmp(cade,PAC.medicomparte);
		if(d==0 || b==0)
		{
			system("cls");
			printf("LOS PACIENTES DE ESTE HOSPITAL SON:\n\n");
			printf("Nombre del paciente:\n");printf("--------------------\n");puts(PAC.Nompac);printf("\n");
			printf("Fecha de la consulta:\n");printf("--------------------\n");puts(PAC.fechas);
			printf("\n");printf("Edad del paciente:\n");printf("--------------------\n");printf("%d\n",PAC.edad);
			printf("\n");printf("Numero del seguro social del paciente:\n");printf("--------------------\n");
			printf("%d\n",PAC.numsocial);printf("\n");printf("Estatura del paciente:\n");printf("--------------------\n");printf("%f\n",PAC.estatura);
			printf("\n");printf("Peso del paciente:\n");printf("--------------------\n");printf("%f\n",PAC.peso);printf("\n");printf("Diagnostico del paciente:\n");
			printf("--------------------\n");	puts(PAC.diagnostico);printf("\n");printf("Fecha de la proxima cita:\n");printf("--------------------\n");	
			puts(PAC.fecha);printf("\n");printf("Login del medico que consulto:\n");printf("--------------------\n");puts(PAC.medico);printf("\n");
			printf("Login que tiene acceso ala consulta:\n");printf("--------------------\n");puts(PAC.medicomparte);
		    getchar();
		}
		break;
		}
	
	}
	fclose(B);
}
void modificar_3(char NUme[56])
{ 	
	int i,j,opcil;
	char cad[45];
	char des[56];
	pacientes dat;int encontrado=0,s;char confir='N'; y=conta_pa(&d,name);fflush(stdin);
	system("cls");
	printf ("Introduzca el nombre que quiera modificar:\n "); 
	gets(cad); 
	
	for(j=0;j<strlen(cad);j++)
	{
		cad[j]=toupper(cad[j]);
	}	
	fflush (stdin); 
	if ((B=fopen(NUme,"rb"))==NULL){printf ("ERROR"); system ("PAUSE"); exit (1);}
	if ((aux=fopen("datosAux.txt","wb"))==NULL){printf ("ERROR"); system ("PAUSE"); exit (1);}
	printf ("\n\n---MODIFICAR DATOS---\n\n"); 
	for(i=0;i<y;i++){ fread (&dat, sizeof (pacientes), 1, B);s=strcmp(cad,dat.Nompac);
	if (s!=0){ fwrite(&dat, sizeof (pacientes), 1, aux); } 
	else
		{ 
			system("cls");encontrado=1;printf ("Estos son los datos que quiere Modificar:\n\n\n\n"); printf("Nombre del paciente:\n");printf("--------------------\n");	
			puts(dat.Nompac);printf("\n");printf("Edad del paciente:\n");printf("--------------------\n");printf("%d\n",dat.edad);printf("\n");
			printf("Numero del seguro social del paciente:\n");printf("--------------------\n");printf("%d\n",dat.numsocial);
			printf("\n");printf("Estatura del paciente:\n");printf("--------------------\n");printf("%f\n",dat.estatura);printf("\n");
			printf("Peso del paciente:\n");printf("--------------------\n");printf("%f\n",dat.peso);printf("\n");
			printf("Diagnostico del paciente:\n");printf("--------------------\n");	puts(dat.diagnostico);printf("\n");printf("Fecha de la proxima cita:\n");
			printf("--------------------\n");puts(dat.fecha);printf("\n");printf ("\n\n"); 
			printf ("Esta seguro de que quiere Modificarlos? (S para confirmar): "); scanf ("%c", &confir); fflush (stdin);confir = toupper (confir); 
			if (confir=='S')
			{ 
				menu_modi( &opcil);
				switch(opcil)
				{
				case 1:
					system("cls");
					fflush(stdin);printf("Cual es el nombre nuevo del paciente:\n");fflush(stdin);gets(des);
					for(i=0;i<strlen(des);i++)
					{
						des[i]=toupper(des[i]);
					}
					strcpy(dat.Nompac,des);
					break;
				case 2:
					system("cls");
					printf("Cual es el numero social del paciente!\n");
					fflush(stdin);scanf("%d",&dat.numsocial);
					break;
				case 3:
					system("cls");
					printf("Proporcione la edad del paciente:\n");fflush(stdin);scanf("%d",&dat.edad);
					break;
				case 4:
					system("cls");
					printf("Proporcione el peso del paciente:\n");fflush(stdin);
					scanf("%f",&dat.peso);
					break;
				case 5:
					system("cls");
					printf("Proporcione la estatura del paciente:\n");scanf("%f",&dat.estatura);
					break;
				case 6:
					system("cls");
					printf("Cual es el diagnostico medico\n");fflush(stdin);gets(dat.diagnostico);
					break;
				case 7:
					system("cls");
					printf("Cual sera la fecha de la proxima cita.?\n");
					fflush(stdin);gets(dat.fecha);
					break;
				}
				fwrite(&dat, sizeof (pacientes), 1, aux);
			} 
		}
	}
	if (encontrado==0) printf ("ERROR. El paciente no fue encontrado\n"); 
	fclose (B); 
	fclose (aux); 
	if (confir=='S') copiar (name); 		
}
void copiar (char nuce[56])
{
	pacientes dat;
	if ((B=fopen(nuce,"w"))==NULL){ printf ("ERROR"); system ("PAUSE"); exit (1);} 
	if ((aux=fopen("datosAux.txt","r"))==NULL){ printf ("ERROR"); system ("PAUSE"); exit (1);} 
	while (!feof(aux))
	{ 
		if(fread (&dat, sizeof (pacientes), 1, aux)) {fwrite(&dat, sizeof (pacientes), 1, B); }
	} 
	printf("Se ha modificado su archivo\n");
	fclose(B); 
	fclose(aux); 
	remove ("datosAux.txt"); 
}
void eric(char pe[56])
{
	
	pacientes PAC;
	int TEM=0;
	char mod[56];
	int j,i;
	y=conta_pa(&d,name);
	B=fopen(pe,"rb");
	system("cls");fflush(stdin);
	printf("Cual es su login como medico:\n");
	gets(mod);
	for(j = 0; mod[j]; j++) 
	{
		mod[j] = toupper(mod[j]);
	}
	for(i=0;i<y;i++)
	{
		fread(&PAC,sizeof(pacientes),1,B);
		d=strcmp(mod,PAC.medico);
		b=strcmp(mod,PAC.medicomparte);
		if(d==0 || b==0)
		{
			modificar_3(name);
			TEM++;
		}
		if(TEM!=0)
		{
			break;
		}
	}
	fclose(B);
}
