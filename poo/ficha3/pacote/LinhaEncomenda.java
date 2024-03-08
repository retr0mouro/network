package pacote;


import org.junit.jupiter.api.Test;

public class LinhaEncomenda{
    private String code;
    private String description;
    private int quantity;
    private double tax;
    private double discount;

    
    private double basePrice;
    
    public LinhaEncomenda() {
        this.code = "001110";
        this.description = "SSD 1 TB";
        this.basePrice = 100;
        this.quantity = 20;
        this.tax = 0.06;
        this.discount = 2;
    }
    
    
    
    public LinhaEncomenda(String code, String description, double basePrice, int quantity, double tax, double discount) {
        this.code = code;
        this.description = description;
        this.basePrice = basePrice;
        this.quantity = quantity;
        this.tax = tax;
        this.discount = discount;
    }
    
    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getDescription() {
        return description;
    }
    
    public void setDescription(String description) {
        this.description = description;
    }

    public double getBasePrice() {
        return basePrice;
    }

    public void setBasePrice(double basePrice) {
        this.basePrice = basePrice;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public double getTax() {
        return tax;
    }

    public void setTax(double tax) {
        this.tax = tax;
    }

    public double getDiscount() {
        return discount;
    }
    
    public void setDiscount(double discount) {
        this.discount = discount;
    }

    @Override
    public String toString() {
        return "LinhaEncomenda [code=" + this.code + ", description=" + this.description + ", basePrice=" + this.basePrice + ", quantity="
                + this.quantity + ", tax=" + this.tax + ", discount=" + this.discount + "]";
    }
    
    
    @Override
    public LinhaEncomenda clone(){
        return new LinhaEncomenda(this.code,this.description, this.basePrice, this.quantity,this.tax,this.discount);
    }

    public boolean equals(LinhaEncomenda pack){
        return pack.code == this.code;
    }


    public double calculaValorLinhaEnc(){
        return this.quantity * (this.basePrice + ((this.tax) * this.basePrice) - (this.discount * this.basePrice));
    }

    public double calculaValorDesconto(){
        return (this.basePrice * (1 + this.tax)) * this.discount;
    }

}