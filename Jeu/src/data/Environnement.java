package data;

public class Environnement {
	private Carte carte=new Carte(20,20);
	
	public Ville creerVille(int x,int y){
		Ville ville=new Ville(x,y);
		ville.setNom(x+"_"+y);
		return ville;
	}
	
	public void initialiser(){
		for(int index=0;index<carte.getLongueur();index++){
			for(int index2=0;index2<carte.getLargeur();index2++){
				carte.ajoutVille(creerVille(index,index2));
			}
		}
		
	}
	public void afficher(){
		carte.AfficheCarte();
	}
	public Ville selectionner(int x,int y){
		return carte.getVille(x, y);
		
	}
	
	
	public static void main(String args[]){
		Environnement environnement=new Environnement();
		environnement.initialiser();
		environnement.afficher();
		Ville v1=environnement.selectionner(14,15);
		System.out.println();
		System.out.println(v1.getNom());
		System.out.println(v1.getArmee());
	}
	
}
