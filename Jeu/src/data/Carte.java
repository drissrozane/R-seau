package data;

public class Carte {
	private Ville[][] carte;
	private int longueur,largeur;
	public Carte(int longueur,int largeur){
		this.longueur=longueur;
		this.largeur=largeur;
		carte=new Ville[longueur][largeur];
	}
	public void AfficheCarte(){
		for(int index=0;index<longueur;index++){
			for(int index2=0;index2<largeur;index2++){
				System.out.print(carte[index][index2].getNom()+" ");
			}
			System.out.println();
		}
	}
	public int getLongueur() {
		return longueur;
	}
	
	public int getLargeur() {
		return largeur;
	}
	
	public Ville getVille(int x,int y){
		return carte[x][y];
	}
	
	public void ajoutVille(Ville ville){
		carte[ville.getPositionX()][ville.getPositionY()]=ville;
	}
	
	
}
