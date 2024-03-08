package pacote;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;

public class LinhaEncomendaTest {
    @Test
    void testCalculaValorDesconto() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals(0.5*(1.5 * 1.23),line.calculaValorDesconto());
    }
    
    @Test
    void testCalculaValorLinhaEnc() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        assertEquals(10.95, line.calculaValorLinhaEnc());
    }
    
    @Test   
    void testClone() { 
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        LinhaEncomenda cloned = line.clone();
        assertEquals(line.getCode(),cloned.getCode());
        assertEquals(line.getDescription(),cloned.getDescription());
        assertEquals(line.getBasePrice(),cloned.getBasePrice());
        assertEquals(line.getQuantity(),cloned.getQuantity());
        assertEquals(line.getTax(),cloned.getTax());
        assertEquals(line.getDiscount(),cloned.getDiscount());
    }
    
    @Test
    void testEquals() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        LinhaEncomenda cloned = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        LinhaEncomenda fake = new LinhaEncomenda("11111", "Pao", 1.5, 10, 0.23, 0.5);
        
        assertEquals(true, line.equals(cloned));        
        assertEquals(false, line.equals(fake));        
        
    }
    
    @Test
    void testGetBasePrice() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals(1.5,line.getBasePrice());
        line.setBasePrice(15);
        assertNotEquals(1.5,line.getBasePrice());
        assertEquals(15, line.getBasePrice());
    }
    
    @Test
    void testGetCode() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals("01101",line.getCode());
    }
    
    @Test
    void testGetDescription() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals("Pacote leite", line.getDescription());
    }
    
    @Test
    void testGetDiscount() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals(0.5, line.getDiscount());
    }
    
    @Test
    void testGetQuantity() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals(10, line.getQuantity());
    }
    
    @Test
    void testGetTax() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals(0.23, line.getTax());
    }
    
    @Test
    void testSetBasePrice() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        assertEquals(1.5,line.getBasePrice());
        line.setBasePrice(90);
        assertNotEquals(1.5,line.getBasePrice());
        assertEquals(90,line.getBasePrice());
    }
    
    @Test
    void testSetCode() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals("01101",line.getCode());
        line.setCode("1000101");
        assertNotEquals("01101",line.getCode());
        assertEquals("1000101",line.getCode());
        
        
    }
    
    @Test
    void testSetDescription() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals("Pacote leite",line.getDescription());
        line.setDescription("Queijo");
        assertNotEquals("Pacote leite",line.getDescription());
        assertEquals("Queijo",line.getDescription());
        
    }
    
    @Test
    void testSetDiscount() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals(0.5,line.getDiscount());
        line.setDiscount(0.9);
        assertNotEquals(0.5,line.getDiscount());
        assertEquals(0.9,line.getDiscount());
    }
    
    @Test
    void testSetQuantity() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        assertEquals(10,line.getQuantity());
        line.setQuantity(100);
        assertNotEquals(10,line.getQuantity());
        assertEquals(100,line.getQuantity());
    }
    
    @Test
    void testSetTax() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);
        
        
        assertEquals(0.23,line.getTax());
        line.setTax(100);
        assertNotEquals(0.23,line.getTax());
        assertEquals(100,line.getTax());

    }
    
    @Test
    void testToString() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);

        assertEquals("LinhaEncomenda [code=01101, description=Pacote leite, basePrice=1.5, quantity=10, tax=0.23, discount=0.5]" ,
        line.toString());
    }
}
