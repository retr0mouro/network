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
        
        LinhaEncomenda fake = new LinhaEncomenda("01101", "Pao", 1.5, 10, 0.23, 0.5);
        
        assertEquals(true, line.equals(cloned));        
        assertEquals(false, line.equals(fake));        
        
    }

    @Test
    void testGetBasePrice() {

    }

    @Test
    void testGetCode() {

    }

    @Test
    void testGetDescription() {

    }

    @Test
    void testGetDiscount() {

    }

    @Test
    void testGetQuantity() {

    }

    @Test
    void testGetTax() {

    }

    @Test
    void testSetBasePrice() {

    }

    @Test
    void testSetCode() {

    }

    @Test
    void testSetDescription() {

    }

    @Test
    void testSetDiscount() {

    }

    @Test
    void testSetQuantity() {

    }

    @Test
    void testSetTax() {

    }

    @Test
    void testToString() {

    }
}
