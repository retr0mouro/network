package pacote;

public class Telemovel{
    private String marca;
    private String modelo;
    private double x;
    private double y;
    private double smsStorage;
    private double totalStorage;
    private double picStorage;
    private double appStorage;
    private double totalOccupiedStorage;
    private int picNum;
    private int appNum;
    private String[] appNames;
    
    
    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getSmsStorage() {
        return smsStorage;
    }

    public void setSmsStorage(double smsStorage) {
        this.smsStorage = smsStorage;
    }

    public double getTotalStorage() {
        return totalStorage;
    }

    public void setTotalStorage(double totalStorage) {
        this.totalStorage = totalStorage;
    }

    public double getPicStorage() {
        return picStorage;
    }

    public void setPicStorage(double picStorage) {
        this.picStorage = picStorage;
    }

    public double getAppStorage() {
        return appStorage;
    }

    public void setAppStorage(double appStorage) {
        this.appStorage = appStorage;
    }

    public double getTotalOccupiedStorage() {
        return totalOccupiedStorage;
    }

    public void setTotalOccupiedStorage(double totalOccupiedStorage) {
        this.totalOccupiedStorage = totalOccupiedStorage;
    }

    public int getPicNum() {
        return picNum;
    }

    public void setPicNum(int picNum) {
        this.picNum = picNum;
    }

    public int getAppNum() {
        return appNum;
    }

    public void setAppNum(int appNum) {
        this.appNum = appNum;
    }

    public void setAppNames(String[] appNames) {
        this.appNames = appNames.clone();
    }

    public Telemovel(){
        this.marca = "Blackberry";
        this.modelo = "Skyline";
        this.x = 1080;
        this.y = 920;
        this.smsStorage = 100;
        this.totalStorage = 640000;
        this.picStorage = 10000;
        this.appStorage = 50;
        this.totalOccupiedStorage = 240000;
        this.picNum = 37;
        this.appNum = 16;
        this.appNames = new String[16];
    }
    
    public Telemovel(
        String marca,
        String modelo,
        double x,
        double y,
        double smsStorage,
        double totalStorage,
        double picStorage,
        double appStorage,
        double totalOccupiedStorage,
        int picNum,
        int appNum,
        String[] appNames){
            
        this.marca = marca;
        this.modelo = modelo;
        this.x = x;
        this.y = y;
        this.smsStorage = smsStorage;
        this.totalStorage = totalStorage;
        this.picStorage = picStorage;
        this.appStorage = appStorage;
        this.totalOccupiedStorage = totalOccupiedStorage;
        this.picNum = picNum;
        this.appNum = appNum;
        this.appNames = appNames.clone();
    }

    public String[] getAppNames() {
        return appNames;
    }
    
}