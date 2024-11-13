
public class Firkateyn extends DenizAraci {

	private int dayaniklilik;
	private int vurus;
	private int havaVurusAvantaji;
	private String altSinif;
	
	
	 public Firkateyn(int dayaniklilik, int seviyePuani, String sinif, int vurus, int havaVurusAvantaji, String altSinif) {
	        super(seviyePuani, sinif);
	        this.dayaniklilik = dayaniklilik;
	        this.vurus = vurus;
	        this.havaVurusAvantaji = havaVurusAvantaji;
	        this.altSinif = altSinif;
	    }

	 
	 
	 @Override
	    public String getAltSinif()
	    {
	    	return altSinif;
	    }
	    @Override
	    public void setAltSinif(String altSinif)
	    {
	    	this.altSinif = altSinif;
	    }
	    

	    
	@Override
	public int getHavaVurusAvantaji() {
		return havaVurusAvantaji;
	}
	@Override
	public void setHavaVurusAvantaji(int havaVurusAvantaji) {
		this.havaVurusAvantaji = havaVurusAvantaji;
	}

	
	
	@Override
	public int getDayaniklilik() {
		return dayaniklilik;
	}
	@Override
	public void setDayaniklilik(int dayaniklilik) {
		this.dayaniklilik = dayaniklilik;
	}

	
	
	@Override
	public int getVurus() {
		return vurus;
	}
	@Override
	public void setVurus(int vurus) {
		this.vurus = vurus;
	}

	
	
	@Override
	   public void DurumGuncelle(int vurus) {
	       // Dayan�kl�l��� sald�r� de�eri ve kara vuru� avantaj� kadar azalt�yoruz
	       this.dayaniklilik -= vurus;
	       if (dayaniklilik < 0) {
	           dayaniklilik = 0; // Dayan�kl�l�k 0'�n alt�na d��mesin
	       }

	       // Seviye puan�n� g�ncelle
	       if (vurus > 10) {
	           this.setSeviyePuani(this.getSeviyePuani() + 1); // Basit bir g�ncelleme mant���
	       }
	       
	       System.out.println("G�ncellenmi� Dayan�kl�l�k: " + dayaniklilik + ", Seviye Puan�: " + getSeviyePuani());
	   }
	    

}
