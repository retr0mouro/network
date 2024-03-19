
public class Turma {
    private String designacao;
    private Aluno[] alunos;
    private int capacidade;
    private int ocupacao;
    private static final int capacidadeInicial = 20;


    
    

    public String getDesignacao() {
        return designacao;
    }
    public void setDesignacao(String designacao) {
        this.designacao = designacao;
    }
    public int getCapacidade() {
        return capacidade;
    }
    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }
    public int getOcupacao() {
        return ocupacao;
    }
    public void setOcupacao(int ocupacao) {
        this.ocupacao = ocupacao;
    }

    //private Aluno[] getAlunos(){
    //    return this.alunos;
    //}

    public void insereAluno(Aluno a){
        this.alunos[this.ocupacao] = new Aluno(a.getNumero(),a.getNota(),a.getNome(),a.getCurso());
        this.ocupacao++;
    }
    public void insereAluno(String numero,int nota, String nome, String curso){
        this.alunos[this.ocupacao] = new Aluno(numero,nota,nome,curso);
        this.ocupacao++;
    }


    public Turma(String designacao, int capacidade, int ocupacao, Aluno[] alunos) {
        this.designacao = designacao;
        this.capacidade = capacidade;
        this.ocupacao = ocupacao;
    }
    public Turma() {
        this.designacao = "";
        this.capacidade = 0;
        this.ocupacao = 0;
    }
    
    @Override
    public String toString() {
        return "Turma [designacao=" + designacao + ", capacidade=" + capacidade + ", ocupacao=" + ocupacao
                + ", capacidadeInicial=" + capacidadeInicial + "]";
    }
    
    
    
}
