package pacote;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class LinhaEncomendaTest {
    @Test
    void testCalculaValorDesconto() {
        LinhaEncomenda line = new LinhaEncomenda("01101", "Pacote leite", 1.5, 10, 0.23, 0.5);

        assertEquals(15*1.23*0.5,line.calculaValorDesconto());
    }

    @Test
    void testCalculaValorLinhaEnc() {

    }

    @Test   
    void testClone() {

    }

    @Test
    void testEquals() {

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
