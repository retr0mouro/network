import java.time.LocalDateTime;
/**
 * Write a description of class PedidoSuporte here.
 *
 * @author (your name)
 * @version (a version number or a date)
*/

public class PedidoSuporte
{
    // instance variables - replace the example below with your own
    private String nome;
    private LocalDateTime data;
    private String assunto;
    private String descricao;
    /**
     * Constructor for objects of class PedidoSuporte
     */
    public PedidoSuporte()
    {
        // initialise instance variables
        this.nome = "";
        this.data = null;
        this.assunto = "";
        this.descricao = "";
    }

    public String getNome(){
        return this.nome;
    }
    public void setNome(String name){
        this.nome = name;
    }
    public LocalDateTime getData(){
        return this.data;
    }
    public void setData(LocalDateTime date){
        this.data = date;
    }
    public String getAssunto(){
        return this.assunto;
    }
    public void setAssunto(String name){
        this.assunto = name;
    }
    public String getDescricao(){
        return this.descricao;
    }
    public void setDescricao(String name){
        this.descricao = name;
    }
    
    public boolean equals(PedidoSuporte p){
        return 
            this.nome.equals(p.nome) &&
            this.data.equals(p.data) && 
            this.assunto.equals(p.assunto) && 
            this.descricao.equals(p.descricao);
    }
}
