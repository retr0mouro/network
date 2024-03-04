package pacote;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.api.DisplayName;

import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

public class CirculoTest {
    @Test
    void testAlteraCentro() {
        Circulo centro = new Circulo();

        assertNotNull(centro);
    }

    @Test
    void testCalculaArea() {
        Circulo centro = new Circulo(14, 20, 7);

        assertEquals(Math.PI * 49,centro.calculaArea());
    }

    @Test
    void testCalculaPerimetro() {
        Circulo centro = new Circulo(0, 0, 17);

        assertEquals(Math.PI * 2 * 17,centro.calculaPerimetro());
    }

    @Test
    void testClone() {
        Circulo original = new Circulo(-69, 69, 13);

        Circulo cloned = original.clone();

        assertEquals(original,cloned);
    }

    @Test
    @DisplayName("Testar os iguais; DEVE ESTAR FALSO")
    void testEquals() {
        Circulo original = new Circulo(69, 210, 111);
        
        Circulo elementoTestado = new Circulo(69, 210, 111);
        
        assertNotEquals(original,elementoTestado);
    }
    
    @Test
    void testGetRaio() {
        Circulo original = new Circulo(69, 210, 111);

        assertEquals(111,original.getRaio());
    }
    
    @Test
    void testGetX() {
        Circulo original = new Circulo(69, 210, 111);
    
        assertEquals(69,original.getX());
        
    }
    
    @Test
    void testGetY() {
        Circulo original = new Circulo(69, 210, 111);
        
        assertEquals(210,original.getY());
        
    }
    
    @Test
    void testSetRaio() {
        Circulo original = new Circulo(69, 210, 111);

        original.setRaio(96);

        assertEquals(96,original.getRaio());
    }
    
    @Test
    void testSetX() {
        Circulo original = new Circulo(69, 210, 111);
    
        original.setX(96);
    
        assertEquals(96,original.getX());
        
    }
    
    @Test
    void testSetY() {
        Circulo original = new Circulo(69, 210, 111);
    
        original.setY(96);
    
        assertEquals(96,original.getY());
        
        
    }

    @Test
    void testToString() {
        Circulo original = new Circulo();
        assertEquals("(0.0,0.0,0.0)", original.toString());
    }
}
