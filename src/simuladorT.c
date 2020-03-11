/*
 * main.c
 *
 *  Created on: 4 jun. 2019
 *      Author: master2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mysql.h>

#define MAX_STRING 512

int inArray(int *haystack,int needle, int haystackSize);
void introduceDate(int myDate[3]);

int main() {
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	/*DB connection data*/
	char *server = "localhost";
	char *user = "phpmyadmin";
	char *password = "12345"; /* set me first */
	char *database = "IoTMonitorizacion";
	char *sql;
	char sql2[MAX_STRING] = {0};

	int numberFilesReturned, sensorId, i;
	int *idList;
	int hour, myDate[3];
	/* Temp tables
	 *
	 * Para el cálculo del valor de la temperatura se utilizará la fórmula
	 *
	 * T = tempMediaMensual[mes]*tempHoraDiaNormalizada[hora]
	 *
	 * Donde tempHoraDiaNormalizada[hora] = tempHoraDia[hora]/tempMediaDia
	 *
	 * */
	float tempMediaMensual[] = {10.4,13.7,15.1,15.9,20.0,25.2,25.6,26.2,21.9,20.7,14.7,11.4};
	float tempHoraDiaNormalizada[] = {0.9402, 0.9402, 0.8907, 0.8907, 0.8412, 0.8412, 0.8907, 0.8907, 0.9402, 0.9896, 0.9896, 1.0391, 1.0391, 1.0886, 1.1381, 1.1381, 1.1381, 1.1381, 1.0886, 1.0886, 1.0391, 1.0391, 0.9896, 0.9896};
	float tempSimulada;

	conn = mysql_init(NULL);
	sql = "SELECT lt.id, t.numeroSerie, t.modelo, s.codigo, s.modelo, s.rango, m.nombre 'magnitud' from ListadoSensoresTrafo lt join Transformador t on t.id = lt.idTransformador join Sensor s on s.id = lt.idSensor join Magnitud m on m.id = s.idMagnitud where m.nombre = 'Temperatura';";

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	/* send SQL query */
	if (mysql_query(conn, sql)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}

	res = mysql_store_result(conn);
	numberFilesReturned = mysql_num_rows(res);
	idList = calloc(numberFilesReturned, sizeof(int));
	i = 0;

	/* output table name */
	puts("SIMULADOR DE LECTURAS DE TEMPERATURA (0-23H) DE UN SENSOR");
	printf("------------------------------------------------------------------\n");
	puts("Dado un dia del año y un sensor, el programa genera los valores.\n\n");
	printf("Lista de sensores de temperatura simulables (%d):\n\n", numberFilesReturned);
	printf("Id\tSerial T\tModelo T\tCodigo S\tModelo S\n");
	printf("------------------------------------------------------------------\n");
	while ((row = mysql_fetch_row(res)) != NULL){
		printf("%s\t%s\t\t%s\t%s\t\t%s\n", row[0], row[1], row[2], row[3], row[4]);
		idList[i] = atoi(row[0]);
		i++;
	}
	/* close connection */
	mysql_free_result(res);

	printf("\nId[]: %i,%i,%i",idList[0],idList[1],idList[2]);

	/*read line id from keyboard*/
	sensorId = 0;
	while (!inArray(idList, sensorId, numberFilesReturned)){
		printf("\nIntroduce el Id del sensor: ");
		i = scanf("%d", &sensorId);
	}

	printf("\nSimulación del sensor %d\n",sensorId);
	free(idList);

	/* read date from keyboard*/
	introduceDate(myDate);
	printf("Fecha de la simulación %02d-%02d-%04d\n", myDate[2], myDate[1], myDate[0]);

	for(hour = 0; hour < 24; hour++){
		tempSimulada = tempMediaMensual[myDate[1]]*tempHoraDiaNormalizada[hour];
		snprintf(sql2,256,"insert into Lectura (idListado,fecha,valor) values (%d,'%04d-%02d-%02d %02d:00:00',%.1f);",
				sensorId, myDate[0], myDate[1], myDate[2], hour, tempSimulada);
		/* send SQL query */
		if (mysql_query(conn, sql2)) {
			fprintf(stderr, "%s\n", mysql_error(conn));
			mysql_close(conn);
			exit(2);
		}
		puts (sql2);

	}
	mysql_close(conn);
	puts("----------------------------------------------------------------------------------");
	puts("Programa finalizado");


	return 0;
}

int inArray(int *haystack, int needle, int haystackSize){
	int i;
	for(i = 0; i < haystackSize; i++){
		if(haystack[i] == needle) return 1;
	}
	return 0;
}

void introduceDate(int myDate[3]){
	int dd,mm,yy;

	while(1==1){
		printf("Introduce una fecha en formato DD/MM/YYYY (valor mínimo 01/01/2019): ");
		scanf("%d/%d/%d",&dd,&mm,&yy);

		//check year
		if(yy>=2019 && yy<=9999) {
			//check month
			if(mm>=1 && mm<=12)	{
				//check days
				if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
					//printf("Date is valid.\n");
					break;
				else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
					//printf("Date is valid.\n");
					break;
				else if((dd>=1 && dd<=28) && (mm==2))
					//printf("Date is valid.\n");
					break;
				else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
					//printf("Date is valid.\n");
					break;
				else {
					printf("El día no es correcto.\n");
					continue;
				}
			}
			else {
				printf("El mes no es correcto.\n");
				continue;
			}
		} else {
			printf("El año no es correcto.\n");
			continue;
		}
	}

	myDate[0] = yy;
	myDate[1] = mm;
	myDate[2] = dd;
}


