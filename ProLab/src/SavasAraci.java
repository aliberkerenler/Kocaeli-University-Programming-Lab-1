public abstract class SavasAraci {
    private int seviyePuani;

    public SavasAraci(int seviyePuani) {
        this.seviyePuani = seviyePuani;
    }

    public abstract int getDayaniklilik();
    public abstract void setDayaniklilik(int dayaniklilik);

    public abstract String getSinif();
    public abstract void setSinif(String sinif);

    public abstract int getVurus();
    public abstract void setVurus(int vurus);

    public int getSeviyePuani() {
        return seviyePuani;
    }

    public void setSeviyePuani(int seviyePuani) {
        this.seviyePuani = seviyePuani;
    }
    public void kartPuaniGoster() {
        System.out.println("Dayan�kl�l�k: " + getDayaniklilik() + ", Seviye Puan�: " + seviyePuani );
    }

    public abstract void DurumGuncelle(int vurus);

}
