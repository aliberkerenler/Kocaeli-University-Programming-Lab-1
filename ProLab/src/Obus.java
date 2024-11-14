
public class Obus extends KaraAraci{

			private int dayaniklilik;
			private int vurus;
			private int denizVurusAvantaji;
			private String altSinif;
	
	
		    public Obus(int dayaniklilik, int seviyePuani, String sinif, int vurus, int denizVurusAvantaji,String altSinif) {
		        super(seviyePuani, sinif);
		        this.dayaniklilik = dayaniklilik;
		        this.vurus = vurus;
		        this.denizVurusAvantaji = denizVurusAvantaji;
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
		public int getDenizVurusAvantaji() {
			return denizVurusAvantaji;
		}
		@Override
		public void setDenizVurusAvantaji(int denizVurusAvantaji) {
			this.denizVurusAvantaji = denizVurusAvantaji;
		}
		
		
		
		@Override
		public int getDayaniklilik() {
			return dayaniklilik;
		}
		@Override
		public void setDayaniklilik(int dayaniklilik) {
                  if (dayaniklilik < 0) {
                  this.dayaniklilik = 0;
                 }
                else{
                this.dayaniklilik = dayaniklilik;
                }
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
		       // Dayanýklýlýðý saldýrý deðeri ve kara vuruþ avantajý kadar azaltýyoruz
		       this.dayaniklilik -= vurus;
		       if (dayaniklilik < 0) {
		           dayaniklilik = 0; // Dayanýklýlýk 0'ýn altýna düþmesin
		       }

		       // Seviye puanýný güncelle
		       if (vurus > 10) {
		           this.setSeviyePuani(this.getSeviyePuani() + 1); // Basit bir güncelleme mantýðý
		       }
		       
		       System.out.println("Güncellenmiþ Dayanýklýlýk: " + dayaniklilik + ", Seviye Puaný: " + getSeviyePuani());
		   }
		    
	
}
