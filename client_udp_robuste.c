#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <time.h>

#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>


#define MAX 80

int main () {
    char buf [80];
    char msg [80];
    struct timeval timeVal;
    fd_set readSet;
    
    int s, exp_len ;
	struct sockaddr_in serveur ;
	
	s = socket (PF_INET, SOCK_DGRAM, 0) ;

	serveur.sin_family = AF_INET ;
	serveur.sin_addr.s_addr = INADDR_ANY;//permettra de ne plus écrire l'adresse ip dans le dur
	serveur.sin_addr.s_addr = inet_addr ("127.0.0.1");
	serveur.sin_port =htons(5000) ;
	memset (&serveur.sin_zero, 0, sizeof(serveur.sin_zero));


    int logger ;
    int i, n ;
    char log [MAX] ;

    if ((logger = open ("traces_client.txt", O_CREAT|O_APPEND|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP)) == -1) {
        perror ("Erreur fichier destination") ;
    }


    memset (buf, 0, 80);
	strcpy (buf, "Bonjour") ;
	
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&serveur, sizeof serveur)!=-1){
    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (serveur.sin_addr), ntohs (serveur.sin_port) ) ;
    
    }
    memset(buf,0,80);
    if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&serveur, &exp_len)!=-1){
        printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (serveur.sin_addr), ntohs (serveur.sin_port) ) ;
    }
    
    memset(buf,0,80);
    if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&serveur, &exp_len)!=-1){
        printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (serveur.sin_addr), ntohs (serveur.sin_port) ) ;
    }
    
    
    memset (buf, 0, 80);
    memset(msg,0,80);
    scanf("%80s",msg);
	//strcpy (buf, "CREER_5_12_25") ;
	strcpy (buf, msg);
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&serveur, sizeof serveur)!=-1){
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (serveur.sin_addr), ntohs (serveur.sin_port) ) ;
    
    }
    
    // Attente de la réponse pendant une seconde.
    FD_ZERO(&readSet);
    FD_SET(s, &readSet);
    timeVal.tv_sec = 5;
    timeVal.tv_usec = 0;
    if (select(s+1, &readSet,NULL, NULL, &timeVal)) {
    // Lecture de la ligne modifiée par le serveur.
        memset(buf, 0, 80); // Mise à  zéro du tampon
        if (recvfrom(s, buf, 80, 0,(struct sockaddr *)&serveur, &exp_len) == -1) {
            
            memset(log,0,MAX);
            strcpy (log, "recvfrom non aboutie\n") ;
            n = write (logger, log, strlen (log)) ;
            if (n == -1) {
	        perror ("Probleme d'écriture\n") ;
            }
            strcpy (msg, "cmd valide execute\n") ;
            
            
            
            close(logger);
            close(s);
            exit(EXIT_FAILURE);
        }
        
        
       
       
        printf("Message traité : %s\n", msg);
    }
    else {
        printf("Pas de réponse dans le temps donnee.\n");
    }
    close(logger);
    close (s) ;

}
