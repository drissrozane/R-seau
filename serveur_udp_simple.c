#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>

int main () {
	char buf [80] ;
	typedef enum{DEPLACER, CREER, CONSTRUIRE}action;
	int s, exp_len ;
	struct sockaddr_in moi, client;
	int reponse=0;
	struct timeval timeVal;

	moi.sin_family = AF_INET ;
	moi.sin_addr.s_addr = INADDR_ANY ;
	moi.sin_port = htons (5000) ;
	memset (&moi.sin_zero, 0, sizeof(moi.sin_zero));

	s = socket (PF_INET, SOCK_DGRAM, 0) ;
	bind (s, (struct sockaddr *)&moi, sizeof moi) ;
    

	exp_len = sizeof (client) ;
    
    
    int connexion=0;
    //choix d'équipe
    int r=1;
    int b=1;
    int j=1;
    int v=1;
    
    
    /*if(1){
    printf("est dans 1\n");
    }
    else{
       printf("erreur\n");
    }
    
    if(0){
        printf("est dans 0\n");
    }
    
    else{
       printf("erreur\n");
    }
    
    if(22){
    printf("est dans 2\n");
    }
    else{
       printf("erreur\n");
    }
    
    */
        

    memset (buf, 0, 80);
    
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }
    
    
    
    memset (buf, 0, 80);
    strcpy (buf, "Entrer un login") ;
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
    printf ("J'ai envoyé [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }	
    
    
    memset (buf, 0, 80);
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }
    
    if(strncmp (buf, "login",80)){
        memset (buf, 0, 80);
        strcpy (buf, "login incorrecte") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
        printf ("J'ai envoyé [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        }
        close (s) ;
    }
    else{
	
    
    memset (buf, 0, 80);
        strcpy (buf, "vous etes bien reconnu") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
       printf ("J'ai envoyé [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
}
        memset (buf, 0, 80);
        strcpy (buf, "entrer le mot de passe") ;
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	}

        memset (buf, 0, 80);
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
    printf("j'ai reçu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port));
    }
	if(strncmp (buf, "azerty", 80)){
		strcpy (buf, "MDP incorrecte") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        }
        close(s);
	}
    else{
       
        strcpy (buf, "vous etes bien connecté") ;
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }

	
	
    
	//printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;

	/* Exemple de réponse variant suivant ce qu'on a recu */
	//if (!strncmp (buf, "Au revoir", strlen ("Au revoir"))) {
        	
            
	//}
	//selection du joueur
	//}
        memset (buf, 0, 80);
        strcpy (buf, "En attente d'autre joueurs...") ;
    	if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	    }
        connexion++;
        
	    memset (buf, 0, 80);
	    char msgb [20];
	    char msgj [20];
	    char msgr [20];
	    char msgv [20];
	        if(b){
	            strcpy(msgb,"BLEU\n");
	        } else{
	           strcpy(msgb,"");
	        }
	        if(r){
	            strcpy(msgr,"ROUGE\n");
	        } else{
	           strcpy(msgr,"");
	        
	        }
	        if(v){
	            strcpy(msgv,"VERT\n");
	        } else{
	           strcpy(msgv,"");
	        
	        }
	        if(j){
	            strcpy(msgj,"JAUNE\n");
	        } else{
	           strcpy(msgj,"");
	        
	        }
	        int valider=0;
	   while(!valider){     
	        memset (buf, 0, 80);
	        strcpy (buf, "Selectionnez une Nation:\n") ;
	        strcat(buf,msgb);
	        strcat(buf,msgj);
	        strcat(buf,msgr);
	        strcat(buf,msgv);
	        if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
                printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
                }
                
                memset (buf, 0, 80);
	        if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
                printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ; 
            }    
                
                
        int rouge=3;
        int bleu=1;
        int jaune=2;
        int vert=4;
        int choix;
        
        if(!strncmp (buf, "BLEU", strlen ("BLEU"))){
            choix=bleu;
        }
        
        if(!strncmp (buf, "ROUGE", strlen ("ROUGE"))){
            choix=rouge;
        }
        
        if(!strncmp (buf, "VERT", strlen ("VERT"))){
            choix=vert;
        }
        
        if(!strncmp (buf, "JAUNE", strlen ("JAUNE"))){
            choix=jaune;
        }
        
        
	switch(choix){
		case 1:
		if(b){
		
		b=0;
		valider++;
		}
		else{
		    memset (buf, 0, 80);
	        strcpy (buf, "choix incorrecte veuillez choisir une autre nation") ;
	        if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
            printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
            }
		}
		break;
		case 2:
		if(j){
		
		j=0;
		valider++;
		}
		else{
		    memset (buf, 0, 80);
	        strcpy (buf, "choix incorrecte veuillez choisir une autre nation") ;
	        if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
            printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
            }
		}
		break;
		case 3:
		if(r){
		
		r=0;
		valider++;
		}
		else{
		    memset (buf, 0, 80);
	        strcpy (buf, "choix incorrecte veuillez choisir une autre nation") ;
	        if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
            printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
            }
		}
		
		break;
		case 4:
		if(v){
		
		v=0;
		valider++;
		}
		else{
		    memset (buf, 0, 80);
	        strcpy (buf, "choix incorrecte veuillez choisir une autre nation") ;
	        if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
            printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
            }
		}
		break;
		
		
		default:
		    memset (buf, 0, 80);
	        strcpy (buf, "choix incorrecte veuillez choisir une autre nation") ;
	        if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
            printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
            }
		break;
	}
	
	}
	//vous avez choisi 
	memset (buf, 0, 80);
	strcpy (buf, " vous allez commencer le jeu") ;
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }    
        
        int tour=0;
    while(tour<=2 ){   
    memset (buf, 0, 80);
	strcpy (buf, "C'est a vous de jouer") ;
	if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	}
	reponse=0;
    while(!reponse){
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
	        if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
                printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
            }    
                
    //choix            
    memset (buf, 0, 80);
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    }
    int selection;
    int comp1=(!strncmp (buf, "DEPLA", strlen ("DEPLA")));
    int comp2=(!strncmp (buf, "CREER", strlen ("CREER")));
    int comp3=(!strncmp (buf, "CONST", strlen ("CONST")));
    if(comp1 || comp2 || comp3){
    if (comp1){
        selection=1;
    } 
    if (comp2){
        selection=2;
        } 
    if (comp3) {
        selection=3;
            }
   }
   
            
    
    switch(selection){
    
        case 1 :
        
        memset (buf, 0, 80);
	    strcpy (buf, "Indiquez les differents parametres :\nnbUnit_posX_posY_nposX_nposY\n") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	    }
	    /*MSG suite instruction*/
    //reçoit la cmd
	memset (buf, 0, 80);
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    
    }
    
    /*Traitement*/
    // buf= Deplacer/Creer armee positionX positionY NpositionX NpositionY
	// tab[0]=Deplacer/Creer tab[4]=NpositionX
	
	//résolution du probleme 6)format et débordement
    char *cmd1= strtok(buf, "_");
    //armee
    long armee=strtol(cmd1);
	        
	   
	    
	    
	    
	    
       
        break;
        
        case 2 : 
        
        memset (buf, 0, 80);
	    strcpy (buf, "Indiquez les differents parametres:\ntypeUnit_nbUnit_posX_posY") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	    }
	    
	    /*MSG suite instruction*/
    //reçoit la cmd
	memset (buf, 0, 80);
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    
    }
    
    /*Traitement*/
    // buf= Deplacer/Creer armee positionX positionY NpositionX NpositionY
	// tab[0]=Deplacer/Creer tab[4]=NpositionX
	
	//résolution du probleme 6)format et débordement
    char *cmd2= strtok(buf, "_");
        
        
        
        
        break;
        case 3 : 
        
        memset (buf, 0, 80);
	    strcpy (buf, "Indiquez les differents parametres:posX_posY\n") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	    }
	    
	    
	    /*MSG suite instruction*/
    //reçoit la cmd
	memset (buf, 0, 80);
	if(recvfrom (s, buf, 80, 0, (struct sockaddr *)&client, &exp_len)!=-1){
    printf ("J'ai recu [%s] de %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
    
    }
    
    /*Traitement*/
    // buf= Deplacer/Creer armee positionX positionY NpositionX NpositionY
	// tab[0]=Deplacer/Creer tab[4]=NpositionX
	
        
        
        
        
        
        break;
    
    }
    
    
    
	
	   
	//MSG OK    
	    memset (buf, 0, 80);
	    strcpy (buf, "CMD valider") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	    }
	    if(!strncmp (buf, "CMD valider", strlen ("CMD valider"))){
	        reponse=1;
	    }
	
	else{
        memset (buf, 0, 80);
	    strcpy (buf, "CMD incorrecte veuillez recommencer \n") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
            printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
        }
    
    }
	    
    }
    
    //FIN de tour
        memset (buf, 0, 80);
	    strcpy (buf, "Fin de tour") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	        printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	    }
       
     tour++;       
    }
    
        memset (buf, 0, 80);
	    strcpy (buf, "Fin de partie") ;
	    if(sendto (s, buf, 80, 0, (struct sockaddr *)&client, sizeof client)!=-1){
	    printf ("J'ai envoye [%s] à %s:%d\n", buf, inet_ntoa (client.sin_addr), ntohs (client.sin_port) ) ;
	    }
       
    // Attente de la réponse pendant une seconde.
   /* FD_ZERO(&readSet);
    FD_SET(s, &readSet);
    timeVal.tv_sec = 5;
    timeVal.tv_usec = 0;
    if (select(s+1, &readSet,NULL, NULL, &timeVal)) {
    
    
    }*/
	
  	   close (s) ;
	    }
	}










}
