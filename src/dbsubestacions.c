#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main() {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "localhost";
   char *user = "phpmyadmin";
   char *password = "12345"; /* set me first */
   char *database = "IoTMonitorizacion";

   conn = mysql_init(NULL);

   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   /* send SQL query */
   if (mysql_query(conn, "select codigo,nombre,poblacion from Subestacion;")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   res = mysql_use_result(conn);

   /* output table name */
   printf("Lista de subestaciones:\n");
   while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s\t%s\t%s\n", row[0], row[1], row[2]);

   /* close connection */
   mysql_free_result(res);
   mysql_close(conn);

   return 0;
}