package data;

public class Ville {
	private String nom;
	private int positionX;
	private int positionY;
	private int armee;
	
	
	public Ville(int positionX,int positionY){
		this.positionX=positionX;
		this.positionY=positionY;
		armee=0;
	}
	
	void ajouter_Armee(int armee){
		this.armee+=armee;
	}
	
	void réduire_Armee(int armee){
		this.armee-=armee;
		
	}

	public int getArmee() {
		return armee;
	}

	public void setArmee(int armee) {
		this.armee = armee;
	}
	
	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getPositionX() {
		return positionX;
	}

	public void setPositionX(int positionX) {
		this.positionX = positionX;
	}

	public int getPositionY() {
		return positionY;
	}

	public void setPositionY(int positionY) {
		this.positionY = positionY;
	}
	
	
}
