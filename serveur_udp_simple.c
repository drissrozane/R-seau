#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>

int main () {
	char buf [80] ;
	typedef enum{DEPLACER, CREER, CONSTRUIRE}action;
	int s, exp_len ;
	struct sockaddr_in moi, client ,client2,client3;

	moi.sin_family = AF_INET ;
	moi.sin_addr.s_addr = INADDR_ANY ;
	moi.sin_port = htons (5000) ;
	memset (&moi.sin_zero, 0, sizeof(moi.sin_zero));

	s = socket (PF_INET, SOCK_DGRAM, 0) ;
	bind (s, (struct sockaddr *)&moi, sizeof moi) ;
    

	exp_len = sizeof (client) ;
    
    
    int connexion=0;
    int en=1;
    int fr=1;
        

    memset (buf, 0, 80);
	recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len) ;
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    memset (buf, 0, 80);


    strcpy (buf, "Entrer un login") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
    printf ("J'ai envoyé [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;	
    
    memset (buf, 0, 80);
	recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len) ;
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    
    if(strncmp (buf, "login", strlen ("login"))){
        memset (buf, 0, 80);
        strcpy (buf, "login incorrecte") ;
	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
        printf ("J'ai envoyé [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        close (s) ;
    }
    else{
	
    
    memset (buf, 0, 80);
        strcpy (buf, "vous etes bien reconnu") ;
	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
       printf ("J'ai envoyé [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;

        memset (buf, 0, 80);
        strcpy (buf, "entrer le mot de passe") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;

        memset (buf, 0, 80);
	recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len) ;
    printf("j'ai reçu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port));
	if(strncmp (buf, "azerty", strlen ("azerty"))){
		strcpy (buf, "MDP incorrecte") ;
	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        close(s);
	}
    else{
       
        strcpy (buf, "vous etes bien connecté") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;

	
	
    
	//printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;

	/* Exemple de réponse variant suivant ce qu'on a recu */
	//if (!strncmp (buf, "Au revoir", strlen ("Au revoir"))) {
        	
            
	//}
	//selection du joueur
	//}
        memset (buf, 0, 80);
        strcpy (buf, "En attente d'autre joueurs...") ;
    	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        connexion++;
        
	    memset (buf, 0, 80);
	    char msgen [20];
	        if(en){
	            strcpy(msgen,"Angleterre \n");
	        } else{
	           strcpy(msgen,"");
	        }
	        
	        strcpy (buf, "Selectionnez une Nation:\n") ;
	        strcat(buf," France \n");
	        strcat(buf,msgen);
	        sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
                printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
                
                memset (buf, 0, 80);
	        recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len) ;
                printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ; 
                memset (buf, 0, 80);
                
        int france=1;
        int angle=2;
        int choix;
        
        if(strncmp (buf, "Angleterre", strlen ("Angleterre"))){
            choix=angle;
        }
        
	switch(choix){
		case 1:
		if(en){
		struct sockaddr_in angleterre= client;
		en=0;
		}
		else{
		    memset (buf, 0, 80);
	        strcpy (buf, "choix incorrecte veuillez choisir une autre nation") ;
	        sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
            printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
		}
		break;
		case 2:
		//idem
		break;
	}
/*
        while(connexion!=4 && lancer_partie == 0){
            if(connexion >=2){
            memset (buf, 0, 80);
            strcpy (buf, "Voulez Vous commencez la partie?") ;
    	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	        }
        }
        if(reponse1 == oui && reponse2 == oui)
        
        }
*/	
	//vous avez choisi 
	memset (buf, 0, 80);
	strcpy (buf, " vous allez commencer le jeu") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        
        int tour=0;
    while(tour<=2 ){   
    memset (buf, 0, 80);
	strcpy (buf, "C'est a vous de jouer") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    
    //choix d'action
    char msg0 [10];
    char msg1 [10];
    char msg2 [10];
    strcpy (buf, "Selectionnez une action :\n") ;
    strcpy (msg0, "DEPLA\n") ;
    strcpy (msg1, "CREER\n") ;
    strcpy (msg2, "CONST\n") ;
	        strcat(buf,msg0);
	        strcat(buf,msg1);
	        strcat(buf,msg2);
	        sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
                printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
                
    //choix            
    memset (buf, 0, 80);
	recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len) ;
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    
    int selection;
    if(!strncmp (buf, "DEPLA", strlen ("DEPLA"))){
        selection=1;
    } 
    if (!strncmp (buf, "CREER", strlen ("CREER"))){
        selection=2;
        } 
    if (!strncmp (buf, "CONST", strlen ("CONST"))) {
            selection=3;
            }
    
    switch(selection){
    
        case 1 :
        
        memset (buf, 0, 80);
	    strcpy (buf, "Indiquez les differents parametres :\nnbUnit posX posY nposX nposY") ;
	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
       
        break;
        case 2 : 
        
        memset (buf, 0, 80);
	    strcpy (buf, "Indiquez les differents parametres") ;
	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        
        break;
        case 3 : 
        
        memset (buf, 0, 80);
	    strcpy (buf, "Indiquez les differents parametres") ;
	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        
        break;
    
    }
        memset (buf, 0, 80);
	    strcpy (buf, "Fin de tour") ;
	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
       
     tour++;       
    }
    
        memset (buf, 0, 80);
	    strcpy (buf, "Fin de partie") ;
	    sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
       
    /*    
    memset (buf, 0, 80);
	strcpy (buf, " vous allez attendre votre tour") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client2, sizeof client) ;
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client2.sin_addr), ntohs (client2.sin_port) ) ; 
        
    memset (buf, 0, 80);
	strcpy (buf, " vous allez attendre votre tour") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client3, sizeof client) ;
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client3.sin_addr), ntohs (client3.sin_port) ) ;    
	*/
	//
	/*
	strcpy (buf, "En attente d'autre selection de joueurs..... ") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	
	
	//angleterre joue en attente d'une cmd
	memset (buf, 0, 80);
	strcpy (buf, "Angleterre à toi de jouer") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    
	//reçoit la cmd
	memset (buf, 0, 80);
	recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len) ;
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    
	
	// et interprète le résultat
	// buf= Deplacer/Creer armee positionX positionY NpositionX NpositionY
	// tab[0]=Deplacer/Creer tab[4]=NpositionX
	if (){
	memset (buf, 0, 80);
	strcpy (buf, "Angleterre à toi de jouer") ;
	sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client) ;
    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;}
    
    else
    if (buf==){
    
    
    
    }
	
	
	*/
	
  	   close (s) ;
	    }
	}










}
