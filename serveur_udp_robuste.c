#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>


#define MAX 80

int main () {
	char buf [80] ;
	char msg [MAX];
	
	char cmd[5],nbArmee,posX,posY;
	
	int s, exp_len ;
	int logger ;
    int i, n ;
    

  if ((logger = open ("traces_serveur.txt", O_CREAT|O_APPEND|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP)) == -1) {
    perror ("Erreur fichier destination") ;
  }
	
	struct sockaddr_in moi, client;
	
	moi.sin_family = AF_INET ;
	moi.sin_addr.s_addr = INADDR_ANY ;
	moi.sin_port = htons (5000) ;
	memset (&moi.sin_zero, 0, sizeof(moi.sin_zero));

	s = socket (PF_INET, SOCK_DGRAM, 0) ;
	bind (s, (struct sockaddr *)&moi, sizeof moi) ;
    

	exp_len = sizeof (client) ;
	

  
	
	//4)En cas d'UDP : message perdu, message dupliqué, message désordonné:
	/*
	Solution:
	// Attente de la réponse pendant 45 secondes.
FD_ZERO(&readSet);
FD_SET(s, &readSet);
    timeVal.tv_sec = 45;
    timeVal.tv_usec = 0;
if (select(s+1, &readSet,NULL, NULL, &timeVal)) {
// Lecture de la ligne modifiée par le serveur.
memset(msg, 0, sizeof msg); // Mise à zéro du tampon
if (recv(socketDescriptor, msg, sizeof msg, 0) == -1) {
perror("recv:");
close(socketDescriptor);
exit(EXIT_FAILURE);
}

printf("Message traité : %s\n", msg);
	*/
	
	memset (buf, 0, 80);
	
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
	   
        printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }
    
    memset (buf, 0, 80);
    strcpy (buf, "Bonjour,Entrer une cmd valide") ;
	
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
        printf ("J'ai envoyé [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }
    
    //demande au client une commande spécifique
    memset (buf, 0, 80);
    strcpy (buf, "du type:'CREER_nbArmee_posX_posY'") ;
	
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
        printf ("J'ai envoyé [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }
    
    
    memset (buf, 0, 80);
	
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
        printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }
    
    //résolution du probleme 6)format et débordement
    char *cmd2= strtok(buf, "_");
    if( (strncmp (cmd, "CREER", strlen ("CREER"))) ){
        printf("commande valide\n");
        memset(buf,0,MAX);
        strcpy (msg, "cmd valide execute\n") ;
        n = write (logger, msg, strlen (msg)) ;
        if (n == -1) {
	        perror ("Probleme d'écriture\n") ;
        }
    }
    else{
        strcpy (msg, "cmd invalide\n") ;
        n = write (logger, msg, strlen (msg)) ;
        if (n == -1) {
	    perror ("Probleme d'écriture\n") ;
        }
    
    }    
    
    
    //concernant le lag 
    
    
    
    close(logger);
    close(s);	
    
}
